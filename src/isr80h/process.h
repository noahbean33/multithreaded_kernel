// Header guard to prevent multiple inclusions.
// #ifndef ISR80H_PROCESS_H
// #define ISR80H_PROCESS_H

// Forward declaration of the interrupt_frame struct.
// struct interrupt_frame;

// Declares the handler for system call 6 (process_load_start).
// This function takes a filename from the user task's stack, loads the corresponding
// executable file, creates a new process for it, and starts its execution.
// void* isr80h_command6_process_load_start(struct interrupt_frame* frame);

// Declares the handler for system call 7 (invoke_system_command).
// A generic command invocation handler, its implementation will reveal its purpose.
// void* isr80h_command7_invoke_system_command(struct interrupt_frame* frame);

// Declares the handler for system call 8 (get_program_arguments).
// This function retrieves the command-line arguments for the current process.
// void* isr80h_command8_get_program_arguments(struct interrupt_frame* frame);

// Declares the handler for system call 9 (exit).
// This function terminates the currently running process.
// void* isr80h_command9_exit(struct interrupt_frame* frame);

// #endif