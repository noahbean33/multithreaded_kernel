// Include necessary headers for IDT, kernel configuration, memory management, tasks, etc.
// Include necessary headers for IDT, kernel configuration, memory management, tasks, etc.
// #include "idt.h"
// #include "config.h"
// #include "kernel.h"
// #include "memory/memory.h"
// #include "task/task.h"
// #include "task/process.h"
// #include "io/io.h"
// #include "status.h"

// --- Global Variables ---

// The main Interrupt Descriptor Table (IDT), an array of 256 descriptors.
// static struct idt_desc idt_descriptors[PEACHOS_TOTAL_INTERRUPTS];

// The IDTR descriptor structure that will be loaded into the processor.
// static struct idtr_desc idtr_descriptor;

// An array of C function pointers for registered interrupt callbacks.
// static INTERRUPT_CALLBACK_FUNCTION interrupt_callbacks[PEACHOS_TOTAL_INTERRUPTS];

// An array of function pointers for system call (int 0x80) commands.
// static ISR80H_COMMAND isr80h_commands[PEACHOS_MAX_ISR80H_COMMANDS];

// --- External Assembly Functions ---

// extern void idt_load(struct idtr_desc* ptr); // Loads the IDTR.
// extern void* interrupt_pointer_table[PEACHOS_TOTAL_INTERRUPTS]; // Array of ISR stubs.
// extern void isr80h_wrapper(); // Wrapper for system calls.

// --- Forward Declarations for Internal Handlers ---

// static void idt_handle_exception();
// static void idt_clock();
// static void* isr80h_handler(int command, struct interrupt_frame* frame);

// --- IDT Initialization ---

// Initializes the entire interrupt handling system.
// void idt_init()
// {
//     // 1. Clear the command handler and callback arrays.
//     //    memset(isr80h_commands, 0, sizeof(isr80h_commands));
//     //    memset(interrupt_callbacks, 0, sizeof(interrupt_callbacks));

//     // 2. Set up the `idtr_descriptor` with the limit (size) and base address of the IDT.
//     //    idtr_descriptor.limit = sizeof(idt_descriptors) - 1;
//     //    idtr_descriptor.base = (uint32_t)idt_descriptors;

//     // 3. Loop through all 256 interrupts.
//     //    For each one, set its IDT entry to point to the corresponding assembly stub
//     //    from the `interrupt_pointer_table`.
//     //    for (int i = 0; i < PEACHOS_TOTAL_INTERRUPTS; i++)
//     //    {
//     //        idt_set(i, interrupt_pointer_table[i]);
//     //    }

//     // 4. Override specific interrupts with their handlers.
//     //    - Set interrupt 0x80 to use the `isr80h_wrapper` for system calls.
//     //    - Set interrupt 0x20 for the timer (clock).

//     // 5. Register C-level handlers for critical interrupts.
//     //    - Register `idt_handle_exception` for the first 32 CPU exceptions.
//     //    - Register `idt_clock` for the timer interrupt.

//     // 6. Load the IDT register using the `lidt` assembly instruction.
//     //    idt_load(&idtr_descriptor);
// }

// --- Interrupt Registration ---

// Registers a C function as a callback for a specific interrupt number.
// int idt_register_interrupt_callback(int interrupt, INTERRUPT_CALLBACK_FUNCTION callback)
// {
//     // 1. Check if the interrupt number is valid.
//     //    If not, return an error.
//     // 2. Check if a callback is already registered.
//     //    If so, return an error.
//     // 3. Store the callback function pointer in the `interrupt_callbacks` array.
//     // 4. Return success.
// }

// Registers a handler for a specific command ID for the system call interrupt (0x80).
// void isr80h_register_command(int command_id, ISR80H_COMMAND command)
// {
//     // 1. Check if the command ID is valid.
//     //    If not, panic or return an error.
//     // 2. Check if a command is already registered for this ID.
//     //    If so, panic.
//     // 3. Store the command handler in the `isr80h_commands` array.
// }

// --- C-Level Interrupt Handlers ---

// Generic handler for the first 32 CPU exceptions.
// static void idt_handle_exception()
// {
//     // 1. Print an error message.
//     // 2. Terminate the offending process.
//     // 3. Schedule the next available task.
// }

// Handler for the timer interrupt (IRQ0), which drives the scheduler.
// static void idt_clock()
// {
//     // 1. Send an End-of-Interrupt (EOI) signal to the PIC.
//     // 2. Switch to the kernel's page directory.
//     // 3. Call `task_next()` to switch to the next scheduled task.
// }

// The main C-level interrupt handler, called from assembly ISR stubs.
// void interrupt_handler(int interrupt, struct interrupt_frame* frame)
// {
//     // 1. Switch to the kernel's page directory for safe memory access.
//     // 2. Check if a C-level callback is registered for this interrupt.
//     //    if (interrupt_callbacks[interrupt] != 0)
//     //    {
//     //        // If yes, call the registered function.
//     //        interrupt_callbacks[interrupt](frame);
//     //    }
//     // 3. Send an EOI to the PIC to acknowledge the interrupt.
//     // 4. Switch back to the current task's page directory.
// }

// --- System Call (int 0x80) Handlers ---

// Dispatches a system call command to its registered handler.
// static void* isr80h_handle_command(int command, struct interrupt_frame* frame)
// {
//     // 1. Check if the command ID is valid.
//     //    If not, return an error.
//     // 2. Check if a handler is registered for this command.
//     //    If not, return an error.
//     // 3. Get the handler from the `isr80h_commands` array.
//     // 4. Call the handler, passing the interrupt frame.
//     // 5. Return the result from the handler.
// }

// The main C-level handler for system call interrupt 0x80.
// void* isr80h_handler(int command, struct interrupt_frame* frame)
// {
//     // 1. Switch to the kernel's page directory.
//     // 2. Save the calling task's state from the interrupt frame.
//     // 3. Call `isr80h_handle_command` to execute the specific syscall.
//     // 4. Switch back to the task's page directory.
//     // 5. Return the result of the syscall to the assembly wrapper, which places it in EAX.
// }

// --- Helper Functions ---

// Creates and sets a single entry in the IDT.
// static void idt_set(int interrupt_no, void* address)
// {
//     // 1. Get a pointer to the descriptor in the `idt_descriptors` array.
//     // 2. Set the lower 16 bits of the ISR's address.
//     // 3. Set the code segment selector (from GDT).
//     // 4. Set the type and attributes byte (e.g., 32-bit interrupt gate, present, DPL=3).
//     // 5. Set the upper 16 bits of the ISR's address.
// }