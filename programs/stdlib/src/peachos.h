// Header guard to prevent multiple inclusions.
// #ifndef PEACHOS_H
// #define PEACHOS_H

// Include standard headers for size_t and boolean types.
// #include <stddef.h>
// #include <stdbool.h>

// Represents a single command argument in a linked list.
// struct command_argument
// {
    // // The argument string.
    // char argument[512];
    // // Pointer to the next argument in the list.
    // struct command_argument* next;
// };

// Represents the arguments passed to a process.
// struct process_arguments
// {
    // // The number of arguments.
    // int argc;
    // // An array of argument strings.
    // char** argv;
// };

// Function Declarations for PeachOS Standard Library

// Prints a string to the console.
// void print(const char* message);

// Gets a single character from the keyboard (non-blocking).
// int peachos_getkey();

// Allocates a block of memory of a given size.
// void* peachos_malloc(size_t size);

// Frees a previously allocated block of memory.
// void peachos_free(void* ptr);

// Prints a single character to the console.
// void peachos_putchar(char c);

// Gets a single character from the keyboard (blocking).
// int peachos_getkeyblock();

// Reads a line of text from the terminal.
// void peachos_terminal_readline(char* out, int max, bool output_while_typing);

// Loads and starts a new process from a file.
// void peachos_process_load_start(const char* filename);

// Parses a command string into a linked list of arguments.
// struct command_argument* peachos_parse_command(const char* command, int max);

// Retrieves the arguments for the current process.
// void peachos_process_get_arguments(struct process_arguments* arguments);

// Executes a command with a list of arguments.
// int peachos_system(struct command_argument* arguments);

// Executes a command from a single string.
// int peachos_system_run(const char* command);

// Exits the current process.
// void peachos_exit();

// End of header guard.
// #endif