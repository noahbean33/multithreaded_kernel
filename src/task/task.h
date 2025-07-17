// Header guard to prevent multiple inclusions.
// #ifndef TASK_H
// #define TASK_H

// Include necessary headers for configuration and memory management (paging).

// Forward declaration for the interrupt frame structure.
// struct interrupt_frame;

// Defines the structure for holding the complete CPU state of a task.
// This is saved when a task is switched out and restored when it's switched back in.
// struct registers
// {
//     // General-purpose registers.
//     uint32_t edi, esi, ebp, ebx, edx, ecx, eax;

//     // Instruction Pointer (IP) - the address of the next instruction to execute.
//     uint32_t ip;

//     // Code Segment (CS) - the segment selector for the code.
//     uint32_t cs;

//     // Flags Register - contains status flags like carry, zero, interrupt enable, etc.
//     uint32_t flags;

//     // Stack Pointer (ESP) - points to the top of the task's stack.
//     uint32_t esp;

//     // Stack Segment (SS) - the segment selector for the stack.
//     uint32_t ss;
// };

// Forward declaration for the process structure.
// struct process;

// Defines the Task Control Block (TCB), which holds all information about a single task (thread).
// struct task
// {
//     // Pointer to the task's page directory, defining its unique virtual address space.
//     struct paging_4gb_chunk* page_directory;

//     // The saved CPU state (registers) when the task is not running.
//     struct registers registers;

//     // A pointer to the process that this task belongs to.
//     struct process* process;

//     // Pointers to form a doubly linked list of tasks for the scheduler.
//     struct task* next;
//     struct task* prev;
// };

// --- Task Management Functions ---

// Creates a new task associated with a given process.
// struct task* task_new(struct process* process);

// Returns a pointer to the currently executing task.
// struct task* task_current();

// Returns the next task in the scheduler's ready queue.
// struct task* task_get_next();

// Frees all resources associated with a task.
// int task_free(struct task* task);

// --- Scheduling and Context Switching ---

// Switches the currently executing task to the given one. This involves saving the
// old task's state and loading the new one's. This is a low-level assembly function.
// int task_switch(struct task* task);

// A high-level function that saves the current task's state and switches to the next scheduled task.
// void task_next();

// Loads the registers from the given structure and jumps to the task's code.
// This is used to start a task or return from an interrupt/syscall.
// void task_return(struct registers* regs);

// A special function to start the very first task after kernel initialization.
// void task_run_first_ever_task();

// --- Task State and Memory ---

// Saves the CPU state from an interrupt frame into the current task's structure.
// void task_current_save_state(struct interrupt_frame *frame);

// Maps the current task's page directory to the virtual address space.
// int task_page();

// A security-critical function to safely copy a string from a task's virtual memory
// into a kernel buffer, preventing direct kernel access to user memory.
// int copy_string_from_task(struct task* task, void* virtual, void* phys, int max);

// Retrieves an item from the task's stack, given an index from the stack pointer.
// void* task_get_stack_item(struct task* task, int index);

// Translates a virtual address from a task's address space to its corresponding physical address.
// void* task_virtual_address_to_physical(struct task* task, void* virtual_address);

// #endif