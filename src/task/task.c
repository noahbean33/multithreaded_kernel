/**
 * @file task.c
 * @brief This file contains the C-level implementation for the kernel's multitasking system.
 * It manages the lifecycle of tasks, handles scheduling, and provides utility functions for
 * safely interacting with a task's memory and state.
 */

// Global pointer to the currently executing task.
// struct task *current_task = 0;

// Pointers to the head and tail of the scheduler's doubly linked list of tasks.
// struct task *task_tail = 0;
// struct task *task_head = 0;

// Returns a pointer to the currently running task.
// struct task *task_current();

// Creates a new task and adds it to the scheduler's queue.
// struct task *task_new(struct process *process);

// Implements the round-robin scheduling logic to get the next task.
// struct task *task_get_next();

// Frees all resources associated with a task.
// int task_free(struct task *task);

// The main scheduler function, called to switch to the next task.
// void task_next();

// The C part of the context switch.
// int task_switch(struct task *task);

// Copies the CPU state from an interrupt frame into the task's register structure.
// void task_save_state(struct task *task, struct interrupt_frame *frame);

// A wrapper around `task_save_state` for the currently running task.
// void task_current_save_state(struct interrupt_frame *frame);

// Switches the page directory to the one for the current task.
// int task_page();

// Switches the page directory to the one for a specific given task.
// int task_page_task(struct task* task);

// Starts the very first task after the kernel has initialized.
// void task_run_first_ever_task();

// Initializes a task structure, setting up its memory and initial register state.
// int task_init(struct task *task, struct process *process);

// Retrieves an item from a task's stack by its index.
// void* task_get_stack_item(struct task* task, int index);

// Translates a virtual address within a task's context to a physical address.
// void* task_virtual_address_to_physical(struct task* task, void* virtual_address);

// Safely copies a string from a task's virtual memory to a physical kernel buffer.
// int copy_string_from_task(struct task* task, void* virtual, void* phys, int max);