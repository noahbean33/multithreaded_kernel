; @file paging.asm
; @brief Contains low-level assembly functions for controlling the CPU's paging hardware.

; section .asm

; Make the functions visible to C code.
; global paging_load_directory
; global enable_paging

; Loads the physical address of a page directory into the CR3 control register.
; This switch tells the CPU to use a new address space for all subsequent memory accesses.
; paging_load_directory:
;     ; Standard function prologue.
;     push ebp
;     mov ebp, esp

;     ; Get the first argument (the directory pointer) from the stack.
;     mov eax, [ebp+8]

;     ; Load the address into CR3. This is a privileged instruction.
;     mov cr3, eax

;     ; Standard function epilogue.
;     pop ebp
;     ret

; Enables the paging unit on the CPU.
; enable_paging:
;     ; Standard function prologue.
;     push ebp
;     mov ebp, esp

;     ; Read the current value of the CR0 control register.
;     mov eax, cr0

;     ; Set the paging (PG) bit, which is bit 31 (0x80000000).
;     or eax, 0x80000000

;     ; Write the modified value back to CR0 to enable paging.
;     mov cr0, eax

;     ; Standard function epilogue.
;     pop ebp
;     ret
