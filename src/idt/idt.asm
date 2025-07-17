; Declare this as a code section.
; section .asm

; Declare external C functions that will be called from this assembly file.
; extern interrupt_handler  ; The main C-level interrupt handler.
; extern no_interrupt_handler; The C-level handler for unassigned interrupts.
; extern isr80h_handler      ; The C-level handler for system calls.

; Declare global symbols from this file to be visible to the C linker.
; global idt_load            ; Function to load the IDTR.
; global no_interrupt        ; The default ISR stub.
; global enable_interrupts   ; Function to enable interrupts.
; global disable_interrupts  ; Function to disable interrupts.
; global isr80h_wrapper      ; The ISR stub for system calls (int 0x80).
; global interrupt_pointer_table; The table of ISR addresses.

; enable_interrupts:
;   sti  ; Set the Interrupt Flag (IF) in the EFLAGS register.
;   ret  ; Return.

; disable_interrupts:
;   cli  ; Clear the Interrupt Flag (IF) in the EFLAGS register.
;   ret  ; Return.

; idt_load:
; Loads the IDTR with a pointer to the IDT descriptor.
; Expects a pointer to an `idtr_desc` struct on the stack.
; {
;     // Standard function prologue.
;     // Get the pointer to the descriptor from the stack [ebp+8].
;     // `lidt [ebx]` loads the IDT register with the contents pointed to by ebx.
;     // Standard function epilogue and return.
; }

; no_interrupt:
; A default ISR stub for interrupts that are not yet handled.
; {
;     // 1. `pushad`: Save all general-purpose registers.
;     // 2. `call no_interrupt_handler`: Call the simple C handler (which just sends EOI).
;     // 3. `popad`: Restore all general-purpose registers.
;     // 4. `iret`: Return from interrupt, restoring IP, CS, and EFLAGS.
; }

; A macro to generate a generic ISR stub for a given interrupt number.
; %macro interrupt (interrupt_number)
; {
;     // 1. `global int<interrupt_number>`: Make the label `int0`, `int1`, etc., global.
;     // 2. `int<interrupt_number>:`: Define the label for the ISR.
;     // 3. `pushad`: Save all general-purpose registers (eax, ecx, edx, ebx, esp, ebp, esi, edi).
;     //    This, along with the values pushed by the CPU, forms the `interrupt_frame`.
;     // 4. `push esp`: Push a pointer to the current stack pointer (which points to the frame).
;     // 5. `push dword <interrupt_number>`: Push the interrupt number itself.
;     // 6. `call interrupt_handler`: Call the main C handler with the two arguments.
;     // 7. `add esp, 8`: Clean up the two arguments from the stack.
;     // 8. `popad`: Restore the general-purpose registers.
;     // 9. `iret`: Return from the interrupt.
; }

; Use the macro to generate ISR stubs for interrupts 0 through 511.
; (Note: x86 only has 256 interrupts, 0-255. Generating 512 is excessive but harmless).
; %assign i 0
; %rep 512
;     interrupt i
;     %assign i i+1
; %endrep

; isr80h_wrapper:
; The specialized ISR for system call interrupt 0x80.
; {
;     // 1. `pushad`: Save all general-purpose registers.
;     // 2. `push esp`: Push a pointer to the interrupt frame.
;     // 3. `push eax`: Push the content of EAX, which holds the system call command number.
;     // 4. `call isr80h_handler`: Call the main C handler for system calls.
;     // 5. `mov dword[tmp_res], eax`: Save the return value from the C handler in a temporary variable.
;     // 6. `add esp, 8`: Clean up the arguments from the stack.
;     // 7. `popad`: Restore the original general-purpose registers.
;     // 8. `mov eax, [tmp_res]`: Move the syscall result into EAX, the standard return value register.
;     // 9. `iretd`: Return from interrupt.
; }

; Declare a data section.
; section .data

; A temporary 4-byte variable to hold the return value from a system call.
; tmp_res: dd 0

; A macro to generate a 4-byte data entry (a pointer) for the interrupt table.
; %macro interrupt_array_entry (interrupt_number)
; {
;     dd int<interrupt_number> ; Define a double word (32-bit pointer) to the ISR label.
; }

; The table of pointers to our ISR stubs.
; This table is used by `idt.c` to populate the actual IDT.
; interrupt_pointer_table:
; {
;     // Use the macro to generate a pointer for each of the 512 ISR stubs.
;     %assign i 0
;     %rep 512
;         interrupt_array_entry i
;         %assign i i+1
;     %endrep
; }