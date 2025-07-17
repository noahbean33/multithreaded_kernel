// Include necessary headers for the streamer, kernel heap, and configuration.
// #include "streamer.h"
// #include "memory/heap/kheap.h"
// #include "config.h"
// #include <stdbool.h> // For boolean type

// Creates a new disk stream for a given disk ID.
// struct disk_stream* diskstreamer_new(int disk_id)
// {
    // Get the disk associated with the provided ID.
    // struct disk* disk = disk_get(disk_id);
    // if (!disk)
    // {
        // return 0; // Return null if the disk doesn't exist.
    // }

    // Allocate memory for the stream structure on the kernel heap.
    // struct disk_stream* streamer = kzalloc(sizeof(struct disk_stream));
    // Initialize the stream position to the beginning.
    // streamer->pos = 0;
    // Link the stream to the disk.
    // streamer->disk = disk;
    // return streamer;
// }

// Sets the position of the stream to a new value.
// int diskstreamer_seek(struct disk_stream* stream, int pos)
// {
    // Update the stream's position.
    // stream->pos = pos;
    // return 0; // Success
// }

// Reads data from the disk stream.
// This function handles reads that may cross sector boundaries.
// int diskstreamer_read(struct disk_stream* stream, void* out, int total)
// {
    // Calculate the starting sector and the offset within that sector.
    // int sector = stream->pos / PEACHOS_SECTOR_SIZE;
    // int offset = stream->pos % PEACHOS_SECTOR_SIZE;

    // Determine if the read will cross into the next sector.
    // bool overflow = (offset + total) >= PEACHOS_SECTOR_SIZE;
    // Create a buffer to hold one sector of data.
    // char buf[PEACHOS_SECTOR_SIZE];

    // If the read overflows the current sector, only read up to the end of this sector for now.
    // int total_to_read = total;
    // if (overflow)
    // {
        // total_to_read = PEACHOS_SECTOR_SIZE - offset;
    // }

    // Read the single sector from the disk into our buffer.
    // int res = disk_read_block(stream->disk, sector, 1, buf);
    // if (res < 0)
    // {
        // goto out; // Abort on read error.
    // }

    // Copy the requested data from the sector buffer to the output buffer.
    // for (int i = 0; i < total_to_read; i++)
    // {
        // *((char*)out++) = buf[offset + i];
    // }

    // Update the stream's position.
    // stream->pos += total_to_read;

    // If the read overflowed, recursively call this function to read the remaining data.
    // if (overflow)
    // {
        // res = diskstreamer_read(stream, out, total - total_to_read);
    // }

// out:
    // return res;
// }

// Frees the memory used by a disk stream.
// void diskstreamer_close(struct disk_stream* stream)
// {
    // kfree(stream);
// }