/**
 * @file memory.c
 * @brief Implements standard memory manipulation functions.
 */

// Implements the memset function to fill a block of memory with a specific value.
// void* memset(void* ptr, int c, size_t size)
// {
//     // Cast the generic pointer to a char pointer to work with individual bytes.
//     // char* c_ptr = (char*) ptr;
//
//     // Loop through each byte of the memory block.
//     // for (int i = 0; i < size; i++)
//     // {
//     //     // Set the current byte to the specified value.
//     //     c_ptr[i] = (char) c;
//     // }
//
//     // Return the original pointer to allow for function chaining.
//     // return ptr;
// }

// Implements the memcmp function to compare two blocks of memory.
// int memcmp(void* s1, void* s2, int count)
// {
//     // Cast the generic pointers to char pointers.
//     // char* c1 = s1;
//     // char* c2 = s2;
//
//     // Loop `count` times, decrementing the counter each iteration.
//     // while(count-- > 0)
//     // {
//     //     // Compare the current bytes and advance the pointers.
//     //     if (*c1++ != *c2++)
//     //     {
//     //         // If the bytes are different, return -1 or 1 based on their values.
//     //         // The pointers were already incremented, so we look at the previous byte (c1[-1]).
//     //         return c1[-1] < c2[-1] ? -1 : 1;
//     //     }
//     // }
//
//     // If the loop completes without finding differences, the blocks are identical.
//     // return 0;
// }

// Implements the memcpy function to copy memory from a source to a destination.
// void* memcpy(void* dest, void* src, int len)
// {
//     // Cast the generic pointers to char pointers.
//     // char *d = dest;
//     // char *s = src;
//
//     // Loop `len` times.
//     // while(len--)
//     // {
//     //     // Copy the byte from source to destination and advance both pointers.
//     //     *d++ = *s++;
//     // }
//
//     // Return the original destination pointer.
//     // return dest;
// }