// Include headers for miscellaneous syscalls, the IDT, and task management.

// Implements the handler for system call 0, a test command for summing two numbers.
// The arguments are expected to have been pushed onto the user task's stack before
// the `int 0x80` instruction was called.
// void* isr80h_command0_sum(struct interrupt_frame* frame)
// {
//     // 1. Get a pointer to the current task.
//     // 2. Retrieve the second argument (v2) from the task's stack (at index 1).
//     // 3. Retrieve the first argument (v1) from the task's stack (at index 0).
//     // 4. Calculate the sum of v1 and v2.
//     // 5. Return the result as a void pointer. The assembly wrapper will place this
//     //    value into the EAX register, making it the return value of the syscall.
// }