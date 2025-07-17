// Header guard to prevent multiple inclusions.
// #ifndef DISK_H
// #define DISK_H

// Include the file system header, as the disk structure references it.
// #include "fs/file.h"

// Define a type for the disk type identifier.
// typedef unsigned int PEACHOS_DISK_TYPE;

// --- Disk Type Constants ---

// Constant to identify a real physical hard disk.
// #define PEACHOS_DISK_TYPE_REAL 0

// --- Disk Structure Definition ---

// Represents a disk in the system.
// struct disk
// {
    // The type of the disk (e.g., real, virtual).
    // PEACHOS_DISK_TYPE type;

    // The size of a single sector on the disk.
    // int sector_size;

    // A unique identifier for this disk.
    // int id;

    // A pointer to the filesystem that is managing this disk.
    // struct filesystem* filesystem;

    // A pointer to private data specific to the filesystem, allowing it to store its own state.
    // void* fs_private;
// };

// --- Disk Function Declarations ---

// Searches for and initializes all available disks in the system.
// void disk_search_and_init();

// Retrieves a pointer to a disk structure by its index.
// struct disk* disk_get(int index);

// Reads a specified number of blocks from the disk.
// Parameters:
//   - idisk: A pointer to the disk to read from.
//   - lba: The starting Logical Block Address.
//   - total: The total number of blocks to read.
//   - buf: The buffer to store the read data into.
// Returns: 0 on success, or an error code on failure.
// int disk_read_block(struct disk* idisk, unsigned int lba, int total, void* buf);

// End of header guard.
// #endif