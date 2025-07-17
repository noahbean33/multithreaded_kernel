/*
 * Linker Script for the PeachOS Kernel
 */

// Set the entry point of the kernel. The linker will look for the `_start` symbol
// (defined in kernel.asm) and set it as the first code to be executed.
// ENTRY(_start)

// Specify the output format. `binary` means a flat, raw binary file with no headers,
// suitable for a bootloader to load directly into memory.
// OUTPUT_FORMAT(binary)

// Define the memory layout of the output file.
// SECTIONS
// {
    // Set the starting address of the kernel to 1MB (0x100000).
    // This is a common convention to avoid conflicts with low memory areas used by the BIOS.
    // . = 1M;

    // The .text section (executable code).
    // ALIGN(4096) ensures this section starts on a 4KB page boundary.
    // .text : ALIGN(4096)
    // {
        // Collect all .text sections from all input object files and place them here.
        // *(.text)
    // }

    // A custom section for assembly code.
    // .asm : ALIGN(4096)
    // {
        // Collect all .asm sections from input files.
        // *(.asm)
    // }

    // The .rodata section (read-only data).
    // .rodata : ALIGN(4096)
    // {
        // Collect all .rodata sections from all input object files.
        // *(.rodata)
    // }

    // The .data section (initialized data).
    // .data : ALIGN(4096)
    // {
        // Collect all .data sections from all input object files.
        // *(.data)
    // }

    // The .bss section (uninitialized data).
    // This section does not take up space in the executable file but is allocated at runtime.
    // .bss : ALIGN(4096)
    // {
        // Collect all common symbols and .bss sections from all input object files.
        // *(COMMON)
        // *(.bss)
    // }
// }