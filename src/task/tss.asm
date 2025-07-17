; @file tss.asm
; @brief This file contains the low-level assembly routine for loading the Task State Segment (TSS).

; section .asm - Defines the code section.

; global tss_load - Makes the tss_load label visible to the linker.

; ------------------------------------------------------------------------------
; tss_load(int tss_segment)
; ------------------------------------------------------------------------------
; This function loads the given TSS segment selector into the CPU's Task Register (TR).
; The `ltr` instruction is privileged and can only be executed in kernel mode.
; Once the TR is loaded, the CPU knows where to find the TSS in the GDT.
; 
; Pseudocode:
; 1. Set up the standard function stack frame.
; 2. Get the `tss_segment` selector argument from the stack and move it into the AX register.
; 3. Execute `ltr ax`. This loads the selector into the TR. The CPU will then
;    read the GDT to cache the TSS descriptor information internally.
; 4. Clean up the stack frame and return.