/**
 * @file fat16.c
 * @brief This file provides a comprehensive pseudocode implementation of a FAT16 filesystem driver.
 * It outlines the data structures, constants, and functions required to interact with a FAT16-formatted disk.
 * The driver is designed to be integrated into a virtual filesystem (VFS) layer, providing a standard
 * interface for file operations like open, read, seek, stat, and close.
 */

// --- PSEUDOCODE OVERVIEW ---

// --- Constants and Definitions ---
// Define constants essential for identifying and parsing a FAT16 filesystem.
// - PEACHOS_FAT16_SIGNATURE: The magic number (0x29) in the boot sector to identify FAT16.
// - PEACHOS_FAT16_FAT_ENTRY_SIZE: The size of an entry in the File Allocation Table (2 bytes).
// - PEACHOS_FAT16_BAD_SECTOR: The value in a FAT entry that marks a bad cluster.
// - PEACHOS_FAT16_UNUSED: The value in a FAT entry that marks an unused cluster.
// - FAT_ITEM_TYPE: An enum to distinguish between files and directories.
// - FAT_FILE_ATTRIBUTES: Bitmasks for file properties like read-only, hidden, subdirectory, etc.

// --- Data Structures ---

// `struct fat_header_extended`: Represents the FAT16 Extended Boot Record (EBR).
// Contains metadata like drive number, volume ID, and system ID string.

// `struct fat_header`: Represents the main FAT16 Boot Sector.
// Contains critical parameters like bytes per sector, sectors per cluster, number of FATs, etc.

// `struct fat_h`: A combined header structure that holds both the primary and extended headers.

// `struct fat_directory_item`: Represents a 32-byte entry in a directory table.
// Contains the 8.3 filename, attributes, creation/modification timestamps, starting cluster, and file size.

// `struct fat_directory`: Represents a loaded directory.
// Contains an array of `fat_directory_item`s, the total number of items, and its position on the disk.

// `struct fat_item`: A union that can represent either a file (`fat_directory_item`) or a directory (`fat_directory`).
// This is used during path traversal to handle both types uniformly.

// `struct fat_file_descriptor`: Represents an open file handle.
// Contains a pointer to the `fat_item` and the current read/write position within the file.

// `struct fat_private`: A private data structure for an instance of the FAT16 filesystem on a specific disk.
// It holds the filesystem header, the loaded root directory, and disk streamers for efficient access to
// the FAT, clusters, and directories.

// --- Filesystem Struct Initialization ---

// `fat16_fs`: A global `filesystem` struct that is registered with the VFS.
// It is populated with function pointers to the FAT16 implementation of the VFS interface
// (e.g., `resolve`, `open`, `read`, `seek`, `stat`, `close`).

// --- Public API Functions ---

// `fat16_init()`: Initializes the FAT16 filesystem driver.
// 1. Sets the filesystem name to "FAT16".
// 2. Returns a pointer to the global `fat16_fs` struct, making it available for registration with the VFS.

// --- VFS Interface Implementation ---

// `fat16_resolve(disk)`: Checks if a given disk is formatted with FAT16.
// 1. Allocate a `fat_private` structure to hold filesystem-specific data for this disk.
// 2. Read the first sector of the disk to get the boot sector (header).
// 3. Check if the signature in the extended header is 0x29. If not, it's not a FAT16 disk.
// 4. If the signature matches, load the root directory information.
// 5. If all steps succeed, link the `fat_private` structure to the `disk` object.
// 6. Returns 0 on success, or an error code on failure.

// `fat16_open(disk, path, mode)`: Opens a file or directory.
// 1. Currently, only read mode is supported. Return an error for other modes.
// 2. Allocate a `fat_file_descriptor`.
// 3. Call `fat16_get_directory_entry` to traverse the path and find the target file/directory.
// 4. If the item is found, store it in the descriptor and initialize the position to 0.
// 5. Return the descriptor as a `void*` handle.

// `fat16_read(disk, descriptor, size, nmemb, out_ptr)`: Reads data from an open file.
// 1. Get the starting cluster and current file position from the descriptor.
// 2. For each element to be read (`nmemb`):
//    a. Call `fat16_read_internal` to handle the low-level reading.
//    b. This internal function will find the correct cluster for the current offset, read the data,
//       and handle crossing cluster boundaries by following the FAT chain.
// 3. Update the file position in the descriptor.
// 4. Return the number of items successfully read.

// `fat16_seek(private, offset, seek_mode)`: Changes the current position in an open file.
// 1. Get the file descriptor.
// 2. Check that the descriptor points to a file, not a directory.
// 3. Based on `seek_mode` (SEEK_SET, SEEK_CUR):
//    a. Update the `pos` field in the descriptor.
//    b. Ensure the new position is within the file's bounds.
// 4. Return 0 on success, or an error code.

// `fat16_stat(disk, private, stat)`: Retrieves information about a file.
// 1. Get the file descriptor and the associated directory item.
// 2. Populate the `file_stat` structure with the file's size and attributes (e.g., read-only).
// 3. Return 0 on success.

// `fat16_close(private)`: Closes an open file.
// 1. Get the file descriptor.
// 2. Free all memory associated with the descriptor, including the `fat_item` it contains.
// 3. Return 0.

// --- Static Helper Functions ---

// `fat16_get_directory_entry(disk, path)`: Traverses a path to find a file or directory.
// 1. Start with the root directory.
// 2. For each part of the path (e.g., "dir1", "file.txt"):
//    a. Search the current directory for an item with a matching name.
//    b. If found and it's a directory, load that directory and continue to the next path part.
//    c. If found and it's a file, this is the final item.
// 3. Return the found `fat_item`, or NULL if the path is invalid.

// `fat16_find_item_in_directory(disk, directory, name)`: Searches for an item in a single directory.
// 1. Iterate through all entries in the given `directory`.
// 2. For each entry, format its 8.3 name into a standard string.
// 3. Compare it with the target `name`.
// 4. If a match is found, create a `fat_item` for it and return it.

// `fat16_read_internal(disk, starting_cluster, offset, total, out)`: The core file reading logic.
// 1. Calculate which cluster contains the data at the given `offset` by following the FAT chain
//    using `fat16_get_cluster_for_offset`.
// 2. Calculate the exact starting sector and position within that sector.
// 3. Read data from the disk into the output buffer.
// 4. If the read spans multiple clusters, this function may be called recursively or iteratively
//    to read the remaining data from the next cluster in the chain.

// `fat16_get_cluster_for_offset(disk, starting_cluster, offset)`: Finds the cluster number for a given file offset.
// 1. Calculate how many clusters to skip based on the offset and cluster size.
// 2. Starting from the file's first cluster, read the FAT entry for the current cluster.
// 3. The FAT entry gives the number of the next cluster. Follow this chain `n` times.
// 4. Return the final cluster number.

// `fat16_get_fat_entry(disk, cluster)`: Reads a single 16-bit entry from the FAT.
// 1. Calculate the byte position of the entry in the FAT on disk.
// 2. Seek the disk stream to that position.
// 3. Read the 2-byte entry.
// 4. Return the value, which is the next cluster in the chain or an end-of-file marker.

// `fat16_load_fat_directory(disk, item)`: Loads a subdirectory from the disk.
// 1. Get the starting cluster of the subdirectory from its directory item.
// 2. Calculate the size of the directory and allocate memory for its contents.
// 3. Read the entire directory from the disk using `fat16_read_internal`.
// 4. Return the newly loaded `fat_directory` structure.

// `fat16_get_root_directory(disk, fat_private, directory)`: Loads the root directory.
// 1. Calculate the starting sector of the root directory based on header info (reserved sectors, FAT size).
// 2. Calculate the size of the root directory.
// 3. Allocate memory and read the entire root directory from the disk.

// `fat16_to_proper_string(out, in)`: Converts a FAT 8.3 filename to a standard null-terminated string.
// 1. Copies the filename part, stopping at the first space.
// 2. If an extension exists, adds a '.' and copies the extension part.