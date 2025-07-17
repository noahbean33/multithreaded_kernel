// Header guard to prevent multiple inclusions.
// #ifndef DISKSTREAMER_H
// #define DISKSTREAMER_H

// Include the main disk header, as the stream operates on a disk.
// #include "disk.h"

// --- Disk Stream Structure ---

// Represents a stream for reading data sequentially from a disk.
// This provides a file-like abstraction over the raw disk blocks.
// struct disk_stream
// {
    // The current position (in bytes) within the stream.
    // int pos;

    // A pointer to the disk this stream is associated with.
    // struct disk* disk;
// };

// --- Disk Streamer Function Declarations ---

// Creates and initializes a new disk stream for a given disk ID.
// Returns a pointer to the new stream structure, or NULL on failure.
// struct disk_stream* diskstreamer_new(int disk_id);

// Sets the read/write position of the stream.
// Returns 0 on success, or an error code on failure.
// int diskstreamer_seek(struct disk_stream* stream, int pos);

// Reads a specified number of bytes from the stream into a buffer.
// Returns the number of bytes read, or an error code on failure.
// int diskstreamer_read(struct disk_stream* stream, void* out, int total);

// Closes the disk stream and frees associated memory.
// void diskstreamer_close(struct disk_stream* stream);

// End of header guard.
// #endif