/**
 * @file file.c
 * @brief Implements the virtual filesystem (VFS) layer.
 *
 * This file provides a generic interface for file operations. It manages a list of
 * registered filesystems (e.g., FAT16) and a table of open file descriptors.
 * When a file operation is requested (e.g., fopen, fread), the VFS determines
 * the correct underlying filesystem based on the disk and routes the request
 * to the appropriate driver function.
 */

// Include necessary headers for VFS, config, memory management, string operations,
// disk access, FAT16, status codes, and kernel utilities.

// --- Global State ---

// An array to hold pointers to all registered filesystem drivers.
// The size is defined by PEACHOS_MAX_FILESYSTEMS.
static struct filesystem* filesystems[PEACHOS_MAX_FILESYSTEMS];

// An array to hold pointers to all open file descriptors in the system.
// The size is defined by PEACHOS_MAX_FILE_DESCRIPTORS.
static struct file_descriptor* file_descriptors[PEACHOS_MAX_FILE_DESCRIPTORS];

// --- Filesystem Management ---

// Finds the first empty slot in the `filesystems` array.
// Returns a pointer to the empty slot, or NULL if no slots are free.
static struct filesystem** fs_get_free_filesystem()
{
    for (int i = 0; i < PEACHOS_MAX_FILESYSTEMS; i++)
    {
        if (filesystems[i] == NULL)
        {
            return &filesystems[i];
        }
    }
    return NULL;
}

// Registers a new filesystem driver with the VFS.
// It finds a free slot and adds the filesystem pointer to the global array.
void fs_insert_filesystem(struct filesystem* filesystem)
{
    struct filesystem** slot = fs_get_free_filesystem();
    if (slot != NULL)
    {
        *slot = filesystem;
    }
}

// Statically loads all built-in filesystem drivers.
// This function is called during initialization to make filesystems available.
// Currently, this only loads the FAT16 driver by calling `fat16_init()`.
static void fs_static_load()
{
    fat16_init();
}

// Initializes the `filesystems` array and loads the static drivers.
void fs_load()
{
    for (int i = 0; i < PEACHOS_MAX_FILESYSTEMS; i++)
    {
        filesystems[i] = NULL;
    }
    fs_static_load();
}

// --- Initialization ---

// Initializes the entire virtual file system.
// This function is called once during kernel startup.
void fs_init()
{
    // 1. Clear the file descriptor table.
    for (int i = 0; i < PEACHOS_MAX_FILE_DESCRIPTORS; i++)
    {
        file_descriptors[i] = NULL;
    }
    // 2. Load all static filesystem drivers (e.g., FAT16).
    fs_load();
}

// --- File Descriptor Management ---

// Frees a file descriptor and its associated memory.
static void file_free_descriptor(struct file_descriptor* desc)
{
    // Free the descriptor's memory
    free(desc);
}

// Allocates a new file descriptor from the global pool.
// Returns the descriptor index on success, or a negative error code.
static int file_new_descriptor(struct file_descriptor** desc_out)
{
    for (int i = 0; i < PEACHOS_MAX_FILE_DESCRIPTORS; i++)
    {
        if (file_descriptors[i] == NULL)
        {
            *desc_out = malloc(sizeof(struct file_descriptor));
            if (*desc_out != NULL)
            {
                file_descriptors[i] = *desc_out;
                return i;
            }
            else
            {
                return -1; // Out of memory
            }
        }
    }
    return -2; // No free descriptors
}

// Retrieves a file descriptor structure from its integer handle (fd).
// Returns a pointer to the descriptor, or NULL if the handle is invalid.
static struct file_descriptor* file_get_descriptor(int fd)
{
    if (fd >= 0 && fd < PEACHOS_MAX_FILE_DESCRIPTORS)
    {
        return file_descriptors[fd];
    }
    return NULL;
}

// --- VFS Core Logic ---

// Resolves the filesystem for a given disk.
// It iterates through all registered filesystems and calls their `resolve` function.
// Returns the first filesystem that successfully identifies the disk's format.
struct filesystem* fs_resolve(struct disk* disk)
{
    for (int i = 0; i < PEACHOS_MAX_FILESYSTEMS; i++)
    {
        if (filesystems[i] != NULL)
        {
            if (filesystems[i]->resolve(disk) == 0)
            {
                return filesystems[i];
            }
        }
    }
    return NULL;
}

// Converts a file mode string (e.g., "r", "w", "a") to a FILE_MODE enum.
FILE_MODE file_get_mode_by_string(const char* str)
{
    if (strcmp(str, "r") == 0)
    {
        return FILE_MODE_READ;
    }
    else if (strcmp(str, "w") == 0)
    {
        return FILE_MODE_WRITE;
    }
    else if (strcmp(str, "a") == 0)
    {
        return FILE_MODE_APPEND;
    }
    return FILE_MODE_INVALID;
}

// --- Public File API ---

// Opens a file.
int fopen(const char* filename, const char* mode_str)
{
    // 1. Parse the path string (e.g., "0:/path/to/file.txt") to get drive number and path components.
    int drive_number = atoi(filename);
    char* path = strdup(filename + 2); // Skip the drive number and colon

    // 2. Validate the path. It must contain more than just a drive number.
    if (path == NULL || strlen(path) == 0)
    {
        free(path);
        return -1; // Invalid path
    }

    // 3. Get the disk object corresponding to the drive number.
    struct disk* disk = get_disk(drive_number);
    if (disk == NULL)
    {
        free(path);
        return -2; // Disk not found
    }

    // 4. If the disk doesn't have a filesystem yet, try to resolve it.
    struct filesystem* filesystem = fs_resolve(disk);
    if (filesystem == NULL)
    {
        free(path);
        return -3; // Unable to resolve filesystem
    }

    // 5. Convert the mode string ("r", "w", "a") to a FILE_MODE enum.
    FILE_MODE mode = file_get_mode_by_string(mode_str);
    if (mode == FILE_MODE_INVALID)
    {
        free(path);
        return -4; // Invalid mode
    }

    // 6. Call the `open` function of the disk's filesystem driver.
    void* private_data = filesystem->open(disk, path, mode);
    if (private_data == NULL)
    {
        free(path);
        return -5; // Unable to open file
    }

    // 7. Allocate a new file descriptor for the newly opened file.
    struct file_descriptor* desc;
    int fd = file_new_descriptor(&desc);
    if (fd < 0)
    {
        filesystem->close(private_data);
        free(path);
        return fd; // Error allocating descriptor
    }

    // 8. Populate the file descriptor with the filesystem pointer, the private data from the driver, and the disk pointer.
    desc->filesystem = filesystem;
    desc->private_data = private_data;
    desc->disk = disk;

    // 9. The result is the file descriptor's index (a positive integer handle).
    free(path);
    return fd;
}

// Retrieves status information (metadata) about an open file.
int fstat(int fd, struct file_stat* stat)
{
    // 1. Get the file descriptor for the given handle `fd`.
    struct file_descriptor* desc = file_get_descriptor(fd);
    if (desc == NULL)
    {
        return -1; // Invalid file descriptor
    }

    // 2. If the descriptor is invalid, return an error.
    if (desc->filesystem == NULL || desc->private_data == NULL)
    {
        return -2; // Invalid file descriptor
    }

    // 3. Call the `stat` function of the associated filesystem driver.
    return desc->filesystem->stat(desc->disk, desc->private_data, stat);
}

// Closes an open file.
int fclose(int fd)
{
    // 1. Get the file descriptor for the given handle `fd`.
    struct file_descriptor* desc = file_get_descriptor(fd);
    if (desc == NULL)
    {
        return -1; // Invalid file descriptor
    }

    // 2. If the descriptor is invalid, return an error.
    if (desc->filesystem == NULL || desc->private_data == NULL)
    {
        return -2; // Invalid file descriptor
    }

    // 3. Call the `close` function of the associated filesystem driver.
    int result = desc->filesystem->close(desc->private_data);
    if (result == 0)
    {
        // 4. If the driver's close function succeeds, free the file descriptor from the global table.
        file_free_descriptor(desc);
    }
    return result;
}

// Changes the current read/write position within a file.
int fseek(int fd, int offset, FILE_SEEK_MODE whence)
{
    // 1. Get the file descriptor for the given handle `fd`.
    struct file_descriptor* desc = file_get_descriptor(fd);
    if (desc == NULL)
    {
        return -1; // Invalid file descriptor
    }

    // 2. If the descriptor is invalid, return an error.
    if (desc->filesystem == NULL || desc->private_data == NULL)
    {
        return -2; // Invalid file descriptor
    }

    // 3. Call the `seek` function of the associated filesystem driver.
    return desc->filesystem->seek(desc->disk, desc->private_data, offset, whence);
}

// Reads data from an open file.
int fread(void* ptr, uint32_t size, uint32_t nmemb, int fd)
{
    // 1. Validate input: `size` and `nmemb` must be non-zero.
    if (size == 0 || nmemb == 0)
    {
        return -1; // Invalid input
    }

    // 2. Get the file descriptor for the given handle `fd`.
    struct file_descriptor* desc = file_get_descriptor(fd);
    if (desc == NULL)
    {
        return -2; // Invalid file descriptor
    }

    // 3. If the descriptor is invalid or has no associated read function, return an error.
    if (desc->filesystem == NULL || desc->private_data == NULL)
    {
        return -3; // Invalid file descriptor
    }

    // 4. Call the `read` function of the associated filesystem driver.
    return desc->filesystem->read(desc->disk, desc->private_data, ptr, size, nmemb);
}