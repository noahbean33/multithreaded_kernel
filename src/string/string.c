/**
 * @file string.c
 * @brief Implements standard string and character manipulation functions.
 */

// Converts an uppercase character to lowercase.
// char tolower(char s1)
// {
//     // If the character is between 'A' and 'Z'.
//     //     Add 32 to convert it to its lowercase equivalent.
//     // Return the character.
// }

// Calculates the length of a null-terminated string.
// int strlen(const char* ptr)
// {
//     // Initialize a counter to 0.
//     // Loop while the character at the current pointer is not the null terminator.
//     //     Increment the counter.
//     //     Move the pointer to the next character.
//     // Return the counter.
// }

// Calculates the length of a string up to a maximum number of characters.
// int strnlen(const char* ptr, int max)
// {
//     // Initialize a counter `i` to 0.
//     // Loop `i` from 0 up to `max`.
//     //     If the character at `ptr[i]` is the null terminator.
//     //         Break the loop.
//     // Return `i`.
// }

// Calculates the length of a string until a specific terminator or null is found, up to a max length.
// int strnlen_terminator(const char* str, int max, char terminator)
// {
//     // Initialize a counter `i` to 0.
//     // Loop `i` from 0 up to `max`.
//     //     If the character at `str[i]` is the null terminator or the specified terminator.
//     //         Break the loop.
//     // Return `i`.
// }

// Compares two strings case-insensitively, up to `n` characters.
// int istrncmp(const char* s1, const char* s2, int n)
// {
//     // Loop while `n` is greater than 0, decrementing `n` each time.
//     //     Get the current characters from s1 and s2.
//     //     If the characters are different AND their lowercase versions are different.
//     //         Return the difference between the original characters.
//     //     If the character from s1 is the null terminator (meaning strings match up to this point).
//     //         Return 0.
//     // Return 0 if the loop completes (strings are equal up to n characters).
// }

// Compares two strings case-sensitively, up to `n` characters.
// int strncmp(const char* str1, const char* str2, int n)
// {
//     // Loop while `n` is greater than 0, decrementing `n` each time.
//     //     Get the current characters from str1 and str2.
//     //     If the characters are different.
//     //         Return the difference.
//     //     If the character from str1 is the null terminator.
//     //         Return 0.
//     // Return 0.
// }

// Copies a source string into a destination buffer.
// char* strcpy(char* dest, const char* src)
// {
//     // Save the starting address of the destination buffer.
//     // Loop while the character at the source pointer is not the null terminator.
//     //     Copy the character from source to destination.
//     //     Increment both pointers.
//     // Add a null terminator to the end of the destination buffer.
//     // Return the original starting address of the destination.
// }

// Copies up to `count` characters from a source string to a destination buffer.
// char* strncpy(char* dest, const char* src, int count)
// {
//     // Initialize a counter `i` to 0.
//     // Loop `i` from 0 up to `count - 1`.
//     //     If the source character is the null terminator.
//     //         Break the loop.
//     //     Copy the character from source to destination.
//     // Place a null terminator at the end of the copied content in the destination.
//     // Return the destination pointer.
// }

// Checks if a character is a numeric digit ('0'-'9').
// bool isdigit(char c)
// {
//     // Return true if `c` is between '0' and '9', otherwise false.
// }

// Converts a character digit to its integer value.
// int tonumericdigit(char c)
// {
//     // Return the ASCII value of `c` minus the ASCII value of '0'.
// }