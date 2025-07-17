/**
 * @file process.c
 * @brief Implements process-related system call handlers for interrupt 0x80.
 * These handlers manage the lifecycle of processes, including loading, argument passing, and termination.
 */

// Include headers for process syscalls, task management, string manipulation, and kernel utilities.

/**
 * @brief Handles the 'process_load_start' system call (command 6).
 *
 * It loads a new process from a given filename and prepares it for execution.
 * @param frame The interrupt frame containing the task's state.
 * @return The new process ID on success, or an error code.
 */
// void* isr80h_command6_process_load_start(struct interrupt_frame* frame)
// {
//     // 1. Retrieve the virtual address of the filename string from the task's stack.
//     // 2. Safely copy the filename from the user's virtual memory into a kernel buffer.
//     // 3. If the copy fails, return an error.
//     // 4. Call `process_load` to create and load a new process from the executable file.
//     // 5. If loading fails, return an error.
//     // 6. Return the new process's ID on success.
// }

/**
 * @brief Handles the 'invoke_system_command' system call (command 7).
 *
 * This is a generic command invocation handler. (Not fully implemented).
 * @param frame The interrupt frame containing the task's state.
 * @return Result of the command, or an error.
 */
// void* isr80h_command7_invoke_system_command(struct interrupt_frame* frame)
// {
//     // This system call appears to be a placeholder or for future use.
//     // A full implementation would:
//     // 1. Parse a command structure passed from the user task.
//     // 2. Dispatch to an appropriate internal kernel function based on the command.
//     // 3. Return the result.
//     return 0; // Not implemented
// }

/**
 * @brief Handles the 'get_program_arguments' system call (command 8).
 *
 * It retrieves the command-line arguments for the current process and copies them
 * into a user-provided buffer.
 * @param frame The interrupt frame containing the task's state.
 * @return 0 on success, or an error code.
 */
// void* isr80h_command8_get_program_arguments(struct interrupt_frame* frame)
// {
//     // 1. Get the current process.
//     // 2. Get the pointer to the user-space `process_arguments` struct from the stack.
//     // 3. Translate the user-space virtual address to a physical address for safe access.
//     // 4. Call `process_get_arguments` to retrieve the kernel's stored argc and argv.
//     // 5. Copy the argc and argv values into the user-provided structure.
//     // 6. Return 0 on success.
// }

/**
 * @brief Handles the 'exit' system call (command 9).
 *
 * It terminates the currently running process and schedules the next available task.
 * @param frame The interrupt frame containing the task's state.
 * @return This function never returns.
 */
// void* isr80h_command9_exit(struct interrupt_frame* frame)
// {
//     // 1. Get the current process.
//     // 2. Call `process_terminate` to free all resources used by the process.
//     // 3. Call `task_next` to run the scheduler, which will select a new task to run.
//     //    The current task will never be scheduled again.
// }