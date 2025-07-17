/**
 * @file string.h
 * @brief Declares standard string manipulation functions for user-space programs.
 */

// // Header guard
// #ifndef PEACHOS_STRING_H
// #define PEACHOS_STRING_H

// // Include for the 'bool' type.
// #include <stdbool.h>

// // Converts an uppercase character to lowercase.
// char tolower(char s1);

// // Calculates the length of a null-terminated string.
// int strlen(const char* ptr);

// // Calculates the length of a string up to a maximum number of characters.
// int strnlen(const char* ptr, int max);

// // Calculates the length of a string until a specific terminator or null is found.
// int strnlen_terminator(const char* str, int max, char terminator);

// // Compares two strings case-insensitively, up to `n` characters.
// int istrncmp(const char* s1, const char* s2, int n);

// // Compares two strings case-sensitively, up to `n` characters.
// int strncmp(const char* str1, const char* str2, int n);

// // Copies a source string into a destination buffer.
// char* strcpy(char* dest, const char* src);

// // Copies up to `count` characters from a source string to a destination buffer.
// char* strncpy(char* dest, const char* src, int count);

// // Checks if a character is a numeric digit ('0'-'9').
// bool isdigit(char c);

// // Converts a character digit to its integer value.
// int tonumericdigit(char c);

// // Tokenizes a string by splitting it into smaller strings based on a set of delimiters.
// // Note: This function maintains internal state and is not re-entrant.
// char* strtok(char* str, const char* delimiters);

// #endif