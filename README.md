# Multithreaded Kernel from Scratch

## Kernel Features

- **Custom Bootloader**
  - Written in x86 assembly
  - Runs in Real Mode
  - Outputs text to screen
  - Reads sectors directly from disk
  - Implements basic interrupts

- **Protected Mode Kernel**
  - Switches CPU to 32-bit protected mode
  - Uses Intel memory protection and privilege rings
  - Implements paging and virtual memory
  - Supports memory virtualization for processes

- **Memory Management**
  - Physical and virtual address mapping
  - Page table manipulation
  - Custom heap allocator (`malloc` / `free`)
  - Memory mapping and unmapping for processes

- **Multitasking & Process Management**
  - Task creation and scheduling
  - User-mode execution with privilege separation
  - Inter-process communication via interrupts
  - Process termination and crash handling

- **Filesystem Support**
  - Virtual File System (VFS) abstraction layer
  - FAT16 filesystem driver
  - File operations: `fopen`, `fread`, `fseek`, `fstat`, `fclose`
  - Path parsing and directory handling

- **Executable Loading**
  - ELF binary loader
  - Support for loading user-space programs
  - Process argument passing

- **Device Drivers**
  - PS/2 keyboard driver with buffer
  - ATA disk driver
  - Virtual keyboard input layer

- **Shell Environment**
  - Interactive command-line shell
  - Built-in kernel commands
  - Ability to launch user-space programs from shell

- **Debugging Support**
  - GDB integration via emulators
  - Disassembled machine code debugging

- **Additional Features**
  - Kernel panic handler
  - Caps lock and character case handling
  - Backspace and basic terminal editing

