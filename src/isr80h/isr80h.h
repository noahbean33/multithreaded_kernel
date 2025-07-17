// Header guard to prevent multiple inclusions.
// #ifndef ISR80H_H
// #define ISR80H_H

// Defines the command numbers for all available system calls.
// These numbers are passed in the EAX register during a system call (int 0x80)
// to identify which service the user program is requesting.
// enum SystemCommands
// {
//     SYSTEM_COMMAND0_SUM,                  // A test command to sum numbers.
//     SYSTEM_COMMAND1_PRINT,                // Prints a null-terminated string to the console.
//     SYSTEM_COMMAND2_GETKEY,               // Waits for and returns a single key press.
//     SYSTEM_COMMAND3_PUTCHAR,              // Prints a single character to the console.
//     SYSTEM_COMMAND4_MALLOC,               // Allocates a block of memory from the process's heap.
//     SYSTEM_COMMAND5_FREE,                 // Frees a previously allocated block of memory.
//     SYSTEM_COMMAND6_PROCESS_LOAD_START,   // Loads and starts a new process from a file.
//     SYSTEM_COMMAND7_INVOKE_SYSTEM_COMMAND,// (Not fully implemented/used) For invoking commands.
//     SYSTEM_COMMAND8_GET_PROGRAM_ARGUMENTS,// Gets the command-line arguments for the current process.
//     SYSTEM_COMMAND9_EXIT                  // Terminates the current process.
// };

// Declares the main registration function for system calls.
// This function is responsible for calling `isr80h_register_command` for each
// of the system calls listed above, linking the command number to its handler function.
// void isr80h_register_commands();

// #endif