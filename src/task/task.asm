; @file task.asm
; @brief This file contains the low-level assembly routines for task context switching.
; These functions handle the direct manipulation of CPU registers required to save and
; restore a task's execution state, which cannot be done from C code.

; BITS 32 - Specifies that this is 32-bit code.

; section .asm - Defines the code section.

; global restore_general_purpose_registers
; global task_return
; global user_registers

; ------------------------------------------------------------------------------
; task_return(struct registers* regs)
; ------------------------------------------------------------------------------
; This function is the final step in a context switch. It restores the state of
; the next task to run and uses the `iretd` instruction to jump to its code in
; user mode. This function never returns to its caller.
; 
; Pseudocode:
; 1. Get the pointer to the `registers` struct from the stack.
; 2. From the struct, push the following onto the stack in order:
;    a. Stack Segment (SS)
;    b. Stack Pointer (ESP)
;    c. EFLAGS (with the interrupt-enable bit set to 0x200)
;    d. Code Segment (CS)
;    e. Instruction Pointer (IP)
;    This sequence creates the exact stack frame that the `iretd` instruction expects.
; 3. Set up the data segment registers (DS, ES, FS, GS) for the new task.
; 4. Call `restore_general_purpose_registers` to load the task's general-purpose registers.
; 5. Execute `iretd`. The CPU pops the values from the stack into the SS, ESP, EFLAGS,
;    CS, and IP registers, effectively transferring control to the new task at the
;    saved instruction pointer and switching the CPU to the appropriate privilege level.

; ------------------------------------------------------------------------------
; restore_general_purpose_registers(struct registers* regs)
; ------------------------------------------------------------------------------
; A helper function to restore the general-purpose registers from a saved state.
; 
; Pseudocode:
; 1. Get the pointer to the `registers` struct from the stack.
; 2. Load the values from the struct into their corresponding registers:
;    EDI, ESI, EBP, EDX, ECX, EAX, EBX.
; 3. Return to the caller (`task_return`).

; ------------------------------------------------------------------------------
; user_registers()
; ------------------------------------------------------------------------------
; A utility function to set the data segment registers to the user data segment selector (0x23).
; This is used to prepare the CPU for operating in user space.
; 
; Pseudocode:
; 1. Load the user data segment selector (0x23) into AX.
; 2. Copy the value from AX into DS, ES, FS, and GS.
; 3. Return.