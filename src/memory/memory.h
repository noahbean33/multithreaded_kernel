/**
 * @file memory.h
 * @brief Defines standard memory manipulation functions.
 * These are fundamental, low-level utilities for setting, comparing, and copying blocks of memory.
 */

// Sets a block of memory with a specific value.
// void* memset(void* ptr, int c, size_t size);
// @param ptr: Pointer to the start of the memory block.
// @param c: The value to set (as an int, but converted to an unsigned char).
// @param size: The number of bytes to set.
// @return: The original pointer `ptr`.

// Compares two blocks of memory.
// int memcmp(void* s1, void* s2, int count);
// @param s1: Pointer to the first memory block.
// @param s2: Pointer to the second memory block.
// @param count: The number of bytes to compare.
// @return: 0 if the blocks are identical, <0 if s1 < s2, >0 if s1 > s2.

// Copies a block of memory from a source to a destination.
// void* memcpy(void* dest, void* src, int len);
// @param dest: Pointer to the destination memory block.
// @param src: Pointer to the source memory block.
// @param len: The number of bytes to copy.
// @return: The original pointer `dest`.