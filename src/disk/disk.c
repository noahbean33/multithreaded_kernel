// Include necessary headers for disk operations, I/O, configuration, status codes, and memory management.
// #include "disk.h"
// #include "io/io.h"
// #include "config.h"
// #include "status.h"
// #include "memory/memory.h"

// A global structure representing the primary system disk. This kernel only supports one disk.
// struct disk disk;

// Reads sectors from the ATA hard disk using 28-bit LBA PIO mode.
// Parameters:
//   - lba: The starting Logical Block Address.
//   - total: The number of sectors to read.
//   - buf: The destination buffer in memory.
// Returns: 0 on success.
// int disk_read_sector(int lba, int total, void* buf)
// {
    // --- Send command to ATA Controller ---
    // Select the drive (Master=0xE0) and send the highest 4 bits of the LBA.
    // outb(0x1F6, (lba >> 24) | 0xE0);
    // Send the number of sectors to read.
    // outb(0x1F2, total);
    // Send the low 8 bits of the LBA.
    // outb(0x1F3, (unsigned char)(lba & 0xff));
    // Send bits 8-15 of the LBA.
    // outb(0x1F4, (unsigned char)(lba >> 8));
    // Send bits 16-23 of the LBA.
    // outb(0x1F5, (unsigned char)(lba >> 16));
    // Send the READ SECTORS command (0x20) to the command port.
    // outb(0x1F7, 0x20);

    // Cast the buffer to a short pointer for 16-bit I/O operations.
    // unsigned short* ptr = (unsigned short*) buf;

    // Loop through each sector that needs to be read.
    // for (int b = 0; b < total; b++)
    // {
        // Poll the status port until the drive is ready (DRQ bit is set).
        // char c = insb(0x1F7);
        // while(!(c & 0x08))
        // {
            // c = insb(0x1F7);
        // }

        // Read 256 16-bit words (512 bytes) from the data port into the buffer.
        // for (int i = 0; i < 256; i++)
        // {
            // *ptr = insw(0x1F0);
            // ptr++;
        // }
    // }
    // return 0; // Success
// }

// Initializes the primary disk.
// void disk_search_and_init()
// {
    // Clear the global disk structure.
    // memset(&disk, 0, sizeof(disk));
    // Set the disk type to a real physical disk.
    // disk.type = PEACHOS_DISK_TYPE_REAL;
    // Set the sector size from the configuration.
    // disk.sector_size = PEACHOS_SECTOR_SIZE;
    // Assign a static ID of 0.
    // disk.id = 0;
    // Resolve and attach the appropriate filesystem for this disk.
    // disk.filesystem = fs_resolve(&disk);
// }

// Retrieves the disk structure for a given index.
// Since this kernel only supports one disk, it only returns a valid disk for index 0.
// struct disk* disk_get(int index)
// {
    // if (index != 0)
        // return 0; // Invalid index
    
    // return &disk; // Return the global disk structure.
// }

// A higher-level function to read blocks from a specified disk.
// int disk_read_block(struct disk* idisk, unsigned int lba, int total, void* buf)
// {
    // Validate that the provided disk is the one we support.
    // if (idisk != &disk)
    // {
        // return -EIO; // Return I/O error if it's not our disk.
    // }

    // Call the low-level sector read function.
    // return disk_read_sector(lba, total, buf);
// }