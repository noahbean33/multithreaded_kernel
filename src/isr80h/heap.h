// Header guard to prevent multiple inclusions.
// #ifndef ISR80H_HEAP_H
// #define ISR80H_HEAP_H

// Forward declaration of the interrupt_frame struct.
// struct interrupt_frame;

// Declares the handler for system call 4 (malloc).
// This function takes a size from the user task's stack, allocates a block of memory
// of that size from the task's heap, and returns a pointer to it.
// void* isr80h_command4_malloc(struct interrupt_frame* frame);

// Declares the handler for system call 5 (free).
// This function takes a pointer from the user task's stack and frees the
// previously allocated memory block it points to.
// void* isr80h_command5_free(struct interrupt_frame* frame);

// #endif