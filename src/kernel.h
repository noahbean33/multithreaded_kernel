// Header guard to prevent multiple inclusions.
// #ifndef KERNEL_H
// #define KERNEL_H

// --- VGA Text Mode Dimensions ---
// Defines the width of the VGA text mode screen.
// #define VGA_WIDTH 80
// Defines the height of the VGA text mode screen.
// #define VGA_HEIGHT 20

// Defines the maximum length of a file path.
// #define PEACHOS_MAX_PATH 108

// --- Kernel Function Declarations ---

// The main entry point for the C part of the kernel.
// void kernel_main();

// Prints a null-terminated string to the terminal.
// void print(const char* str);

// Writes a single character with a specific color to the terminal.
// void terminal_writechar(char c, char colour);

// Halts the system in a panic state, displaying an error message.
// void panic(const char* msg);

// A function to handle kernel-specific page table operations.
// void kernel_page();

// A function to set up kernel segment registers, likely from assembly.
// void kernel_registers();

// --- Error Handling Macros ---

// Macro to cast an integer error code to a void pointer.
// This is a common way to return an error from a function that should return a pointer.
// #define ERROR(value) (void*)(value)

// Macro to cast an integer value to an integer error code.
// #define ERROR_I(value) (int)(value)

// Macro to check if a returned value is an error.
// It works by checking if the integer representation of the value is negative.
// #define ISERR(value) ((int)value < 0)

// End of header guard.
// #endif