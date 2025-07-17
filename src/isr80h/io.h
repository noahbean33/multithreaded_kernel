// Header guard to prevent multiple inclusions.
// #ifndef ISR80H_IO_H
// #define ISR80H_IO_H

// Forward declaration of the interrupt_frame struct.
// struct interrupt_frame;

// Declares the handler for system call 1 (print).
// This function takes a pointer to a null-terminated string from the user task's stack
// and prints it to the console.
// void* isr80h_command1_print(struct interrupt_frame* frame);

// Declares the handler for system call 2 (getkey).
// This function waits for a key to be pressed and returns the character code.
// void* isr80h_command2_getkey(struct interrupt_frame* frame);

// Declares the handler for system call 3 (putchar).
// This function takes a single character from the user task's stack and prints it to the console.
// void* isr80h_command3_putchar(struct interrupt_frame* frame);

// #endif