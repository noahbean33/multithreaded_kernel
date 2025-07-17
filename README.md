# Multithreaded Kernel

This repository contains the complete source code of a multithreaded x86 kernel.

### Documented Subsystems

The pseudocode covers all major kernel components, including:
- **Bootloader & Low-Level Initialization**
- **Global Descriptor Table (GDT) & Interrupt Descriptor Table (IDT)**
- **Memory Management:** Paging, Heap Allocation (`kmalloc`)
- **Tasking:** Scheduler, Context Switching, Processes
- **Filesystem:** Virtual Filesystem (VFS) and a FAT16 implementation
- **Disk I/O:** ATA PIO Driver
- **System Calls:** A complete set of handlers for user-space interaction
- **ELF Loader:** For loading and executing user programs


