/**
 * @file io.c
 * @brief Implements I/O-related system call handlers for interrupt 0x80.
 * These functions provide user-space programs with controlled access to console I/O.
 */

// Include headers for I/O syscalls, task management, the keyboard driver, and kernel utilities.

/**
 * @brief Handles the 'print' system call (command 1).
 * 
 * It safely copies a string from the user's virtual address space into a kernel buffer
 * and then prints it to the console.
 * @param frame The interrupt frame containing the task's state.
 * @return 0 on success.
 */
// void* isr80h_command1_print(struct interrupt_frame* frame)
// {
//     // 1. Get the virtual address of the string to be printed from the task's stack.
//     // 2. Create a kernel-space buffer to hold the string.
//     // 3. Use `copy_string_from_task` to safely copy the string from the user's memory
//     //    into the kernel buffer. This is a critical security step to prevent the kernel
//     //    from crashing due to a bad user-provided pointer.
//     // 4. Print the contents of the kernel buffer to the console using the kernel's `print` function.
//     // 5. Return 0 to indicate success.
// }

/**
 * @brief Handles the 'getkey' system call (command 2).
 * 
 * It retrieves the next character from the keyboard buffer, blocking if empty.
 * @param frame The interrupt frame containing the task's state.
 * @return The character code of the key pressed.
 */
// void* isr80h_command2_getkey(struct interrupt_frame* frame)
// {
//     // 1. Call `keyboard_pop()` to get the next character from the global keyboard buffer.
//     //    This function will block if the buffer is empty, effectively pausing the process
//     //    until a key is pressed.
//     // 2. Cast the character to a `void*` and return it. The assembly wrapper will place
//     //    this value in the EAX register, making it the return value of the system call.
// }

/**
 * @brief Handles the 'putchar' system call (command 3).
 * 
 * It prints a single character to the console.
 * @param frame The interrupt frame containing the task's state.
 * @return 0 on success.
 */
// void* isr80h_command3_putchar(struct interrupt_frame* frame)
// {
//     // 1. Get the character to be printed from the task's stack.
//     // 2. Call the kernel's `terminal_writechar` function to print the single character.
//     // 3. Return 0 to indicate success.
// }