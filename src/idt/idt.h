// Header guard to prevent multiple inclusions.
// #ifndef IDT_H
// #define IDT_H

// Include standard integer types.
// #include <stdint.h>

// Forward declaration of the interrupt_frame struct.
// struct interrupt_frame;

// Typedef for a system call command handler function pointer.
// These functions handle specific requests made through interrupt 0x80.
// They receive a pointer to the interrupt frame and can return a result.
// typedef void*(*ISR80H_COMMAND)(struct interrupt_frame* frame);

// Typedef for a generic interrupt callback function pointer.
// These functions are called when a specific hardware or software interrupt occurs.
// typedef void(*INTERRUPT_CALLBACK_FUNCTION)(struct interrupt_frame* frame);

// Represents a single 8-byte Interrupt Descriptor Table (IDT) entry.
// Each entry points to an Interrupt Service Routine (ISR).
// `__attribute__((packed))` prevents compiler padding.
// struct idt_desc
// {
//     uint16_t offset_1;    // Lower 16 bits of the ISR's address.
//     uint16_t selector;    // Code segment selector from the GDT.
//     uint8_t zero;         // Unused, must be zero.
//     uint8_t type_attr;    // Gate type (e.g., 32-bit interrupt gate) and attributes (P, DPL).
//     uint16_t offset_2;    // Upper 16 bits of the ISR's address.
// };

// Represents the 6-byte structure for the Interrupt Descriptor Table Register (IDTR).
// This structure is loaded into the processor using the `lidt` instruction.
// `__attribute__((packed))` prevents compiler padding.
// struct idtr_desc
// {
//     uint16_t limit; // Size of the IDT in bytes, minus one.
//     uint32_t base;  // Linear base address of the IDT.
// };

// Represents the stack frame pushed by our assembly ISR stubs when an interrupt occurs.
// It preserves the state of the general-purpose registers and provides information
// about the interrupt (IP, CS, Flags).
// `__attribute__((packed))` prevents compiler padding.
// struct interrupt_frame
// {
//     uint32_t edi, esi, ebp, reserved, ebx, edx, ecx, eax; // Pushed by `pusha`.
//     uint32_t ip;      // Instruction Pointer pushed by the processor.
//     uint32_t cs;      // Code Segment pushed by the processor.
//     uint32_t flags;   // EFLAGS register pushed by the processor.
//     uint32_t esp;     // Stack Pointer (if a privilege change occurred).
//     uint32_t ss;      // Stack Segment (if a privilege change occurred).
// };

// Initializes the Interrupt Descriptor Table.
// Sets up default handlers for all 256 interrupts and loads the IDT register.
// void idt_init();

// Enables hardware interrupts processor-wide using the `sti` instruction.
// void enable_interrupts();

// Disables hardware interrupts processor-wide using the `cli` instruction.
// void disable_interrupts();

// Registers a handler for a specific command ID for the system call interrupt (0x80).
// void isr80h_register_command(int command_id, ISR80H_COMMAND command);

// Registers a C function as a callback for a specific interrupt number (0-255).
// Returns 0 on success.
// int idt_register_interrupt_callback(int interrupt, INTERRUPT_CALLBACK_FUNCTION interrupt_callback);

// #endif