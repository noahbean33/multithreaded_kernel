/**
 * @file tss.h
 * @brief Defines the structure and functions for the Task State Segment (TSS).
 * The TSS is a special structure in the x86 architecture that holds information about a task.
 * While x86 supports hardware task switching, this kernel uses a software-based approach.
 * The primary role of the TSS here is to tell the CPU which stack to use when an interrupt
 * or system call occurs, causing a privilege level change from user mode (ring 3) to
 * kernel mode (ring 0).
 */

// The `__attribute__((packed))` ensures that the C compiler does not add any padding
// between the fields, so the structure's layout in memory exactly matches the
// hardware-defined TSS format.
// struct tss
// {
//     uint32_t link; // Previous task link. Not used in this kernel's scheduling model.
//     uint32_t esp0; // The kernel stack pointer (ESP) for ring 0.
//     uint32_t ss0;  // The kernel stack segment (SS) for ring 0.
//
//     // Stack pointers and segments for other privilege levels (not used).
//     uint32_t esp1;
//     uint32_t ss1;
//     uint32_t esp2;
//     uint32_t ss2;
//
//     uint32_t sr3;  // CR3 (Page Directory Base Register), not used for hardware context switching here.
//
//     // Saved registers, not used for hardware context switching.
//     uint32_t eip, eflags, eax, ecx, edx, ebx, esp, ebp, esi, edi;
//     uint32_t es, cs, ss, ds, fs, gs;
//
//     uint32_t ldtr; // LDT segment selector, not used.
//     uint32_t iopb; // I/O map base address.
//     uint32_t ssp;  // Shadow stack pointer.
// };

/**
 * @brief Loads the Task State Segment selector into the CPU's Task Register (TR).
 * This function is implemented in assembly (`tss.asm`) and executes the `ltr` instruction.
 * Once loaded, the CPU knows where to find the TSS and will automatically use the `esp0`
 * and `ss0` values when a privilege change from ring 3 to ring 0 occurs.
 * @param tss_segment The GDT selector for the TSS.
 */
// void tss_load(int tss_segment);