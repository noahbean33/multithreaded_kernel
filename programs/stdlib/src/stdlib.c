/**
 * @file stdlib.c
 * @brief Implements standard utility functions for user-space programs.
 */

// // Include the standard library header and the system call interface.
// #include "stdlib.h"
// #include "peachos.h"

// Converts an integer to a null-terminated string.
// char* itoa(int i)
// {
//     // Use a static buffer to hold the resulting string.
//     // Initialize a location pointer to the end of the buffer.
//     // Place the null terminator at the very end.
//
//     // Handle negative numbers by setting a flag and making the number positive for processing.
//     // Note: The logic here cleverly works with negative numbers to handle the full range.
//
//     // Loop while the number is not zero.
//     //     Calculate the last digit using the modulo operator.
//     //     Convert the digit to its character representation and place it in the buffer, moving backwards.
//     //     Remove the last digit by integer division.
//
//     // If the original number was 0, place '0' in the buffer.
//
//     // If the number was negative, add the '-' sign.
//
//     // Return a pointer to the start of the generated string within the buffer.
// }

// Allocates memory from the process's heap.
// void* malloc(size_t size)
// {
//     // This is a simple wrapper around the `peachos_malloc` system call.
//     // return peachos_malloc(size);
// }

// Frees previously allocated memory.
// void free(void* ptr)
// {
//     // This is a simple wrapper around the `peachos_free` system call.
//     // peachos_free(ptr);
// }