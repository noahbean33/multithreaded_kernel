/**
 * @file process.c
 * @brief This file contains the pseudocode for the kernel's process management system.
 * It outlines the logic for creating, managing, and terminating processes, including
 * loading executables, handling memory, and setting up command-line arguments.
 */

// --- Global State ---

// A pointer to the currently executing process.
// struct process* current_process = NULL;

// An array to hold all processes in the system. The size is limited by PEACHOS_MAX_PROCESSES.
// static struct process* processes[PEACHOS_MAX_PROCESSES] = {NULL};

// --- Forward Declarations for Static Functions ---

// Initializes a process structure by zeroing out its memory.
// static void process_init(struct process* process);

// Finds the first available index in a process's allocation tracker.
// static int process_find_free_allocation_index(struct process* process);

// Checks if a given pointer belongs to one of the process's tracked allocations.
// static bool process_is_process_pointer(struct process* process, void* ptr);

// Removes a memory allocation from a process's tracking list.
// static void process_allocation_unjoin(struct process* process, void* ptr);

// Retrieves a process's allocation structure by its memory address.
// static struct process_allocation* process_get_allocation_by_addr(struct process* process, void* addr);

// Frees all memory allocated by a process.
// int process_terminate_allocations(struct process* process);

// Frees the memory holding a raw binary executable.
// int process_free_binary_data(struct process* process);

// Frees the memory and resources associated with an ELF executable.
// int process_free_elf_data(struct process* process);

// Dispatches to the correct function to free program data based on its filetype.
// int process_free_program_data(struct process* process);

// Finds and switches to any available process. Panics if no processes are left.
// void process_switch_to_any();

// Removes a process from the global process table.
// static void process_unlink(struct process* process);

// Loads a raw binary file into memory.
// static int process_load_binary(const char* filename, struct process* process);

// Loads an ELF file into memory.
// static int process_load_elf(const char* filename, struct process* process);

// Tries to load a file as ELF, and if that fails, tries to load it as a raw binary.
// static int process_load_data(const char* filename, struct process* process);

// Maps a loaded binary executable into a process's virtual address space.
// static int process_map_binary(struct process* process);

// Maps a loaded ELF executable into a process's virtual address space.
// static int process_map_elf(struct process* process);

// Finds the first empty slot in the global process table.
// int process_get_free_slot();

// --- Public API Implementation ---

// Returns a pointer to the currently running process.
// struct process* process_current() {
//     return current_process;
// }

// Retrieves a process from the global table by its ID.
// struct process* process_get(int process_id) {
//     1. Validate that process_id is within the valid range (0 to PEACHOS_MAX_PROCESSES - 1).
//     2. If invalid, return NULL.
//     3. Return the process pointer from the `processes` array at the given index.
// }

// Sets the global `current_process` to the given process.
// int process_switch(struct process* process) {
//     current_process = process;
//     return 0; // Success
// }

// Allocates memory for a process, maps it, and tracks it.
// void* process_malloc(struct process* process, size_t size) {
//     1. Allocate physical memory of the requested size using `kzalloc`.
//     2. If allocation fails, return NULL.
//     3. Find a free slot in the process's `allocations` array to track this new memory block.
//     4. If no free slot is found, free the allocated memory and return NULL.
//     5. Map the allocated physical memory into the process's virtual address space.
//        - The virtual address will be the same as the physical address.
//        - The memory should be present, writable, and accessible from user mode.
//     6. If mapping fails, free the physical memory and return NULL.
//     7. Record the pointer and size in the process's `allocations` array.
//     8. Return the pointer to the allocated memory.
// }

// Frees a memory block previously allocated with `process_malloc`.
// void process_free(struct process* process, void* ptr) {
//     1. Look up the allocation details for the given pointer `ptr`.
//     2. If the pointer is not tracked by the process, do nothing and return.
//     3. Unmap the memory region from the process's page directory.
//     4. Remove the allocation from the process's tracking list (`process_allocation_unjoin`).
//     5. Free the physical memory using `kfree`.
// }

// Terminates a process and frees all its associated resources.
// int process_terminate(struct process* process) {
//     1. Terminate and free all memory allocations made by the process (`process_terminate_allocations`).
//     2. Free the program data (ELF or binary) loaded for the process (`process_free_program_data`).
//     3. Free the process's stack memory.
//     4. Free the main task associated with the process (`task_free`).
//     5. Remove the process from the global process list (`process_unlink`).
//     6. If the terminated process was the current one, switch to another available process.
//     7. Return success or an error code.
// }

// Loads a program from a file into the next available process slot.
// int process_load(const char* filename, struct process** process) {
//     1. Find a free slot in the global `processes` array using `process_get_free_slot`.
//     2. If no free slot is available, return an error.
//     3. Call `process_load_for_slot` to perform the actual loading.
//     4. Return the result of the load operation.
// }

// Loads a program and immediately switches to it.
// int process_load_switch(const char* filename, struct process** process) {
//     1. Call `process_load` to load the program into a new process.
//     2. If loading is successful, call `process_switch` to make it the current process.
//     3. Return the result.
// }

// Loads a program into a specific process slot.
// int process_load_for_slot(const char* filename, struct process** process, int process_slot) {
//     1. Check if the target `process_slot` is already taken. If so, return an error.
//     2. Allocate memory for a new `process` struct.
//     3. Initialize the new process struct (`process_init`).
//     4. Load the program's data from the file (`process_load_data`). This will determine if it's an ELF or binary file.
//     5. If loading the data fails, clean up and return an error.
//     6. Allocate memory for the process's user-mode stack.
//     7. Store the filename, stack pointer, and process ID in the `process` struct.
//     8. Create a new task for this process (`task_new`).
//     9. If task creation fails, clean up and return an error.
//     10. Associate the new task with the process.
//     11. Map the program's code, data, and stack into the task's virtual address space (`process_map_memory`).
//     12. If mapping fails, clean up and return an error.
//     13. Set the output `process` pointer to the newly created process.
//     14. Store the new process in the global `processes` array at the given slot.
//     15. Return success.
// }

// Maps the memory for a process, including its code, data, and stack.
// int process_map_memory(struct process* process) {
//     1. Determine the file type (ELF or binary).
//     2. Call the appropriate mapping function (`process_map_elf` or `process_map_binary`).
//     3. If mapping the program data is successful, map the process's stack memory into its virtual address space.
//        - The stack should be present, writable, and accessible from user mode.
//     4. Return the result.
// }

// Injects command-line arguments into a process's address space.
// int process_inject_arguments(struct process* process, struct command_argument* root_argument) {
//     1. Count the number of arguments (`argc`) in the provided linked list.
//     2. If `argc` is 0, return an error.
//     3. Allocate memory within the process's address space for the argument vector (`argv`), which is an array of character pointers.
//     4. Iterate through the linked list of arguments again:
//        a. For each argument, allocate memory for the string within the process's address space.
//        b. Copy the argument string into the newly allocated space.
//        c. Store the pointer to this string in the `argv` array.
//     5. Set the `argc` and `argv` fields in the process's `arguments` struct.
//     6. Return success.
// }

// Retrieves the stored command-line arguments for a process.
// void process_get_arguments(struct process* process, int* argc, char*** argv) {
//     *argc = process->arguments.argc;
//     *argv = process->arguments.argv;
// }