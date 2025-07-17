// Header guard to prevent multiple inclusions.
// #ifndef CONFIG_H
// #define CONFIG_H

// Defines the Global Descriptor Table (GDT) selector for the kernel code segment.
// #define KERNEL_CODE_SELECTOR 0x08

// Defines the GDT selector for the kernel data segment.
// #define KERNEL_DATA_SELECTOR 0x10

// Defines the total number of interrupts supported by the system.
// #define PEACHOS_TOTAL_INTERRUPTS 512

// --- Heap Configuration ---
// Defines the total size of the kernel heap (100MB).
// #define PEACHOS_HEAP_SIZE_BYTES 104857600

// Defines the size of a single block in the heap.
// #define PEACHOS_HEAP_BLOCK_SIZE 4096

// Defines the starting physical address of the heap.
// #define PEACHOS_HEAP_ADDRESS 0x01000000

// Defines the physical address of the heap's allocation table.
// #define PEACHOS_HEAP_TABLE_ADDRESS 0x00007E00

// --- Disk and Filesystem Configuration ---
// Defines the size of a disk sector.
// #define PEACHOS_SECTOR_SIZE 512

// Defines the maximum number of filesystems that can be mounted.
// #define PEACHOS_MAX_FILESYSTEMS 12

// Defines the maximum number of open file descriptors.
// #define PEACHOS_MAX_FILE_DESCRIPTORS 512

// Defines the maximum length of a file path.
// #define PEACHOS_MAX_PATH 108

// --- GDT Configuration ---
// Defines the total number of GDT segments.
// #define PEACHOS_TOTAL_GDT_SEGMENTS 6

// --- Process and Memory Management Configuration ---
// Defines the virtual address where user programs are loaded.
// #define PEACHOS_PROGRAM_VIRTUAL_ADDRESS 0x400000

// Defines the size of the stack for user programs (16 KB).
// #define PEACHOS_USER_PROGRAM_STACK_SIZE (1024 * 16)

// Defines the starting virtual address of the user program stack.
// #define PEACHOS_PROGRAM_VIRTUAL_STACK_ADDRESS_START 0x3FF000

// Defines the ending virtual address of the user program stack.
// #define PEACHOS_PROGRAM_VIRTUAL_STACK_ADDRESS_END (PEACHOS_PROGRAM_VIRTUAL_STACK_ADDRESS_START - PEACHOS_USER_PROGRAM_STACK_SIZE)

// Defines the maximum number of memory allocations a program can have.
// #define PEACHOS_MAX_PROGRAM_ALLOCATIONS 1024

// Defines the maximum number of concurrent processes.
// #define PEACHOS_MAX_PROCESSES 12

// --- User Mode GDT Segments ---
// Defines the GDT selector for the user data segment.
// #define USER_DATA_SEGMENT 0x23

// Defines the GDT selector for the user code segment.
// #define USER_CODE_SEGMENT 0x1b

// --- System Call Configuration ---
// Defines the maximum number of commands for interrupt 80h (system calls).
// #define PEACHOS_MAX_ISR80H_COMMANDS 1024

// --- Keyboard Configuration ---
// Defines the size of the keyboard input buffer.
// #define PEACHOS_KEYBOARD_BUFFER_SIZE 1024

// End of header guard.
// #endif