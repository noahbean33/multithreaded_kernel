/**
 * @file heap.h
 * @brief Defines the interface for a generic heap memory manager.
 * This implementation uses a table of block entries to track memory usage.
 */

// --- Block Entry Flags ---
// These flags indicate the state of a block in the heap's block table.

// #define HEAP_BLOCK_TABLE_ENTRY_TAKEN 0x01 // Marks a block as allocated.
// #define HEAP_BLOCK_TABLE_ENTRY_FREE 0x00  // Marks a block as free.

// These flags are combined with the block size to manage free lists within the table.
// #define HEAP_BLOCK_HAS_NEXT 0b10000000 // Indicates that this free block is part of a larger contiguous free region.
// #define HEAP_BLOCK_IS_FIRST  0b01000000 // Marks the first block in a contiguous allocation.

// Defines the data type for a single entry in the heap's block table.
// typedef unsigned char HEAP_BLOCK_TABLE_ENTRY;

// Represents the heap's metadata table.
// struct heap_table
// {
//     HEAP_BLOCK_TABLE_ENTRY* entries; // A pointer to an array of block entries.
//     size_t total;                    // The total number of entries in the table.
// };

// Represents a heap instance.
// struct heap
// {
//     struct heap_table* table; // The metadata table for this heap.
//     void* saddr;              // The start address of the memory pool managed by this heap.
// };

// Initializes a new heap.
// int heap_create(struct heap* heap, void* ptr, void* end, struct heap_table* table);
// - heap: The heap structure to initialize.
// - ptr: The starting address of the memory region for the heap.
// - end: The end address of the memory region.
// - table: The metadata table to use for this heap.

// Allocates a block of memory of a given size from the heap.
// void* heap_malloc(struct heap* heap, size_t size);

// Frees a previously allocated block of memory.
// void heap_free(struct heap* heap, void* ptr);