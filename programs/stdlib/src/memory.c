// Include the header file for memory-related function declarations.
// #include "memory.h"

// Sets a block of memory to a specific value.
// ptr: Pointer to the memory block.
// c: The value to be set.
// size: The number of bytes to be set.
// Returns the original pointer.
// void* memset(void* ptr, int c, size_t size)
// {
    // Cast the generic pointer to a character pointer.
    // char* c_ptr = (char*) ptr;

    // Loop through each byte of the memory block.
    // for (int i = 0; i < size; i++)
    // {
        // Set the byte to the specified value.
        // c_ptr[i] = (char) c;
    // }

    // Return the pointer to the memory block.
    // return ptr;
// }

// Compares two blocks of memory.
// s1: Pointer to the first memory block.
// s2: Pointer to the second memory block.
// count: The number of bytes to compare.
// Returns 0 if the blocks are equal, -1 if s1 < s2, 1 if s1 > s2.
// int memcmp(void* s1, void* s2, int count)
// {
    // Cast the generic pointers to character pointers.
    // char* c1 = s1;
    // char* c2 = s2;

    // Loop while there are still bytes to compare.
    // while(count-- > 0)
    // {
        // If the bytes are not equal.
        // if (*c1++ != *c2++)
        // {
            // Return -1 if the byte in c1 is smaller, otherwise return 1.
            // return c1[-1] < c2[-1] ? -1 : 1;
        // }
    // }

    // If all bytes are equal, return 0.
    // return 0;
// }

// Copies a block of memory from a source to a destination.
// dest: Pointer to the destination memory block.
// src: Pointer to the source memory block.
// len: The number of bytes to copy.
// Returns the pointer to the destination memory block.
// void* memcpy(void* dest, void* src, int len)
// {
    // Cast the generic pointers to character pointers.
    // char *d = dest;
    // char *s = src;

    // Loop while there are still bytes to copy.
    // while(len--)
    // {
        // Copy the byte from source to destination and move to the next byte.
        // *d++ = *s++;
    // }

    // Return the pointer to the destination memory block.
    // return dest;
// }