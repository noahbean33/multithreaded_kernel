/**
 * @file process.h
 * @brief Defines the structures and functions for process management.
 * A process is a container for a running program, holding all its associated resources
 * such as memory, tasks, and file handles.
 */

// Defines the type of executable file.
// #define PROCESS_FILETYPE_ELF 0
// #define PROCESS_FILETYPE_BINARY 1
// typedef unsigned char PROCESS_FILETYPE;

// Represents a single memory allocation made by a process.
// struct process_allocation
// {
//     void* ptr;    // Pointer to the allocated memory block.
//     size_t size;  // Size of the allocation.
// };

// A node in a linked list used to build command-line arguments before injecting them.
// struct command_argument
// {
//     char argument[512];
//     struct command_argument* next;
// };

// Holds the final argc/argv structure for a process.
// struct process_arguments
// {
//     int argc;     // Argument count.
//     char** argv;  // Argument vector (array of string pointers).
// };

// The main structure representing a process.
// struct process
// {
//     uint16_t id;                                // Unique process identifier.
//     char filename[PEACHOS_MAX_PATH];            // The filename of the executable.
//     struct task* task;                          // The main task associated with this process.
//     struct process_allocation allocations[PEACHOS_MAX_PROGRAM_ALLOCATIONS]; // Tracks memory allocations.
//     PROCESS_FILETYPE filetype;                  // Type of the executable (ELF or binary).
//
//     union
//     {
//         void* ptr;                              // Pointer to the raw executable data if binary.
//         struct elf_file* elf_file;              // Pointer to parsed ELF file info if ELF.
//     };
//
//     void* stack;                                // Pointer to the process's stack memory.
//     uint32_t size;                              // Size of the loaded executable data.
//
//     struct keyboard_buffer
//     {
//         // A dedicated circular buffer for keyboard input for this process.
//     } keyboard;
//
//     struct process_arguments arguments;         // Command-line arguments for the process.
// };

// Switches the currently running task to the main task of the given process.
// int process_switch(struct process* process);

// Loads a process from a file and immediately switches to it.
// int process_load_switch(const char* filename, struct process** process);

// Loads a program from a file into the next available process slot.
// int process_load(const char* filename, struct process** process);

// Loads a program into a specific process slot.
// int process_load_for_slot(const char* filename, struct process** process, int process_slot);

// Returns a pointer to the currently running process.
// struct process* process_current();

// Retrieves a process by its ID.
// struct process* process_get(int process_id);

// Allocates memory on behalf of a process and tracks it.
// void* process_malloc(struct process* process, size_t size);

// Frees a memory allocation previously made by a process.
// void process_free(struct process* process, void* ptr);

// Retrieves the command-line arguments for a process.
// void process_get_arguments(struct process* process, int* argc, char*** argv);

// Injects a prepared list of command-line arguments into a process's address space.
// int process_inject_arguments(struct process* process, struct command_argument* root_argument);

// Terminates a process, freeing all its associated resources (tasks, memory, etc.).
// int process_terminate(struct process* process);