/**
 * @file string.h
 * @brief Declares standard string and character manipulation functions.
 */

// // Header guard
// #ifndef STRING_H
// #define STRING_H

// // Include for the 'bool' type.
// #include <stdbool.h>

// // Calculates the length of a null-terminated string.
// int strlen(const char* ptr);

// // Calculates the length of a string up to a maximum number of characters.
// int strnlen(const char* ptr, int max);

// // Checks if a character is a numeric digit ('0'-'9').
// bool isdigit(char c);

// // Converts a character digit to its integer value.
// int tonumericdigit(char c);

// // Copies a source string into a destination buffer.
// char* strcpy(char* dest, const char* src);

// // Copies up to `count` characters from a source string to a destination buffer.
// char* strncpy(char* dest, const char* src, int count);

// // Compares two strings case-sensitively, up to `n` characters.
// int strncmp(const char* str1, const char* str2, int n);

// // Compares two strings case-insensitively, up to `n` characters.
// int istrncmp(const char* s1, const char* s2, int n);

// // Calculates the length of a string until a specific terminator or null is found.
// int strnlen_terminator(const char* str, int max, char terminator);

// // Converts an uppercase character to lowercase.
// char tolower(char s1);

// #endif