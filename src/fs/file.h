// Header guard to prevent multiple inclusions.
// #ifndef FILE_H
// #define FILE_H

// Include headers for path parsing and standard integer types.
// #include "pparser.h"
// #include <stdint.h>

// --- File Seek Modes ---
// Defines the mode for seek operations.
// typedef unsigned int FILE_SEEK_MODE;
// enum
// {
    // SEEK_SET: Seek from the beginning of the file.
    // SEEK_SET,
    // SEEK_CUR: Seek from the current position.
    // SEEK_CUR,
    // SEEK_END: Seek from the end of the file.
    // SEEK_END
// };

// --- File Modes ---
// Defines the mode for opening a file.
// typedef unsigned int FILE_MODE;
// enum
// { 
    // FILE_MODE_READ: Open for reading.
    // FILE_MODE_READ,
    // FILE_MODE_WRITE: Open for writing.
    // FILE_MODE_WRITE,
    // FILE_MODE_APPEND: Open for appending.
    // FILE_MODE_APPEND,
    // FILE_MODE_INVALID: Invalid mode.
    // FILE_MODE_INVALID
// };

// --- File Stat Flags ---
// Defines flags for file attributes.
// enum
// {
    // FILE_STAT_READ_ONLY: The file is read-only.
    // FILE_STAT_READ_ONLY = 0b00000001
// };
// typedef unsigned int FILE_STAT_FLAGS;

// Forward declaration of the disk structure.
// struct disk;

// --- Filesystem Function Pointers ---
// These define the interface that every filesystem must implement.

// Function to open a file.
// typedef void*(*FS_OPEN_FUNCTION)(struct disk* disk, struct path_part* path, FILE_MODE mode);
// Function to read from a file.
// typedef int (*FS_READ_FUNCTION)(struct disk* disk, void* private, uint32_t size, uint32_t nmemb, char* out);
// Function to check if a disk uses this filesystem.
// typedef int (*FS_RESOLVE_FUNCTION)(struct disk* disk);
// Function to close a file.
// typedef int (*FS_CLOSE_FUNCTION)(void* private);
// Function to seek within a file.
// typedef int (*FS_SEEK_FUNCTION)(void* private, uint32_t offset, FILE_SEEK_MODE seek_mode);
// Function to get file status (metadata).
// typedef int (*FS_STAT_FUNCTION)(struct disk* disk, void* private, struct file_stat* stat);

// --- File Stat Structure ---
// Holds metadata about a file.
// struct file_stat
// {
    // Flags such as read-only.
    // FILE_STAT_FLAGS flags;
    // Total size of the file in bytes.
    // uint32_t filesize;
// };

// --- Filesystem Structure ---
// Represents a filesystem implementation (e.g., FAT16).
// struct filesystem
// {
    // Pointer to the resolve function.
    // FS_RESOLVE_FUNCTION resolve;
    // Pointer to the open function.
    // FS_OPEN_FUNCTION open;
    // Pointer to the read function.
    // FS_READ_FUNCTION read;
    // Pointer to the seek function.
    // FS_SEEK_FUNCTION seek;
    // Pointer to the stat function.
    // FS_STAT_FUNCTION stat;
    // Pointer to the close function.
    // FS_CLOSE_FUNCTION close;
    // Name of the filesystem (e.g., "FAT16").
    // char name[20];
// };

// --- File Descriptor Structure ---
// Represents an open file instance.
// struct file_descriptor
// {
    // The numerical index of this descriptor in the system-wide table.
    // int index;
    // A pointer to the filesystem that handles this file.
    // struct filesystem* filesystem;
    // A pointer to filesystem-specific data for this open file.
    // void* private;
    // The disk this file resides on.
    // struct disk* disk;
// };

// --- Public VFS API ---

// Initializes the virtual file system.
// void fs_init();
// Opens a file and returns a file descriptor.
// int fopen(const char* filename, const char* mode_str);
// Changes the position of the file pointer.
// int fseek(int fd, int offset, FILE_SEEK_MODE whence);
// Reads data from a file.
// int fread(void* ptr, uint32_t size, uint32_t nmemb, int fd);
// Gets file status information.
// int fstat(int fd, struct file_stat* stat);
// Closes an open file.
// int fclose(int fd);

// --- Internal VFS Functions ---

// Registers a new filesystem with the VFS.
// void fs_insert_filesystem(struct filesystem* filesystem);
// Determines which filesystem is responsible for a given disk.
// struct filesystem* fs_resolve(struct disk* disk);

// End of header guard.
// #endif