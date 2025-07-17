/**
 * @file string.c
 * @brief Implements standard string manipulation functions for user-space programs.
 */

// // Include the string header.
// #include "string.h"

// // Converts an uppercase character to lowercase.
// char tolower(char s1) { /* ... */ }

// // Calculates the length of a null-terminated string.
// int strlen(const char* ptr) { /* ... */ }

// // Calculates the length of a string up to a maximum number of characters.
// int strnlen(const char* ptr, int max) { /* ... */ }

// // Calculates the length of a string until a specific terminator or null is found.
// int strnlen_terminator(const char* str, int max, char terminator) { /* ... */ }

// // Compares two strings case-insensitively, up to `n` characters.
// int istrncmp(const char* s1, const char* s2, int n) { /* ... */ }

// // Compares two strings case-sensitively, up to `n` characters.
// int strncmp(const char* str1, const char* str2, int n) { /* ... */ }

// // Copies a source string into a destination buffer.
// char* strcpy(char* dest, const char* src) { /* ... */ }

// // Copies up to `count` characters from a source string to a destination buffer.
// char* strncpy(char* dest, const char* src, int count) { /* ... */ }

// // Checks if a character is a numeric digit ('0'-'9').
// bool isdigit(char c) { /* ... */ }

// // Converts a character digit to its integer value.
// int tonumericdigit(char c) { /* ... */ }

// // --- strtok Implementation ---

// // A static pointer to maintain the current position in the string between calls.
// static char* strtok_sp = 0;

// // Tokenizes a string.
// char* strtok(char* str, const char* delimiters)
// {
//     // If a new string is provided, update the static pointer `strtok_sp`.
//     // If no new string is given and `strtok_sp` is null, there's nothing to do, return null.
//
//     // Skip any leading delimiters at the current position.
//     // `p_start` will point to the beginning of the next token.
//
//     // If we've reached the end of the string, reset `strtok_sp` and return null.
//
//     // Find the end of the current token.
//     // Loop from `p_start` until a delimiter or null terminator is found.
//     // `p_end` will point to the character that ends the token.
//
//     // If we found a delimiter.
//     //     Replace it with a null terminator to end the current token.
//     //     Update `strtok_sp` to point to the character after the new null terminator for the next call.
//     // Else (we hit the end of the main string).
//     //     Reset `strtok_sp` to null so the next call knows to return null.
//
//     // Return the starting pointer of the token found (`p_start`).
// }