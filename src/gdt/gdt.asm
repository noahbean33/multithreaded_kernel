; Declare this as a code section.
; section .asm

; Make the `gdt_load` symbol visible to the C linker.
; global gdt_load

; gdt_load:
; This function is called from C with two arguments on the stack:
; - [esp+8]: The size of the GDT (a 16-bit integer).
; - [esp+4]: A pointer to the GDT itself (a 32-bit address).
; It loads the Global Descriptor Table Register (GDTR) with these values.
; {
;     // 1. Get the pointer to the GDT from the stack and store it in the `eax` register.
;     //    `mov eax, [esp+4]`

;     // 2. Store the GDT pointer (base address) in the upper 4 bytes of our `gdt_descriptor`.
;     //    `mov [gdt_descriptor + 2], eax`

;     // 3. Get the size of the GDT from the stack and store it in the `ax` register.
;     //    `mov ax, [esp+8]`

;     // 4. Store the GDT size (limit) in the lower 2 bytes of our `gdt_descriptor`.
;     //    `mov [gdt_descriptor], ax`

;     // 5. Load the GDTR with the 6-byte value pointed to by `gdt_descriptor`.
;     //    The `lgdt` instruction makes the new GDT active.
;     //    `lgdt [gdt_descriptor]`

;     // 6. Return control to the C caller.
;     //    `ret`
; }

; Declare this as a data section.
; section .data

; gdt_descriptor:
; This is a 6-byte structure required by the `lgdt` instruction.
; It holds the size and base address of the GDT.
; {
;     dw 0x00 ; 2 bytes for the GDT size (limit).
;     dd 0x00 ; 4 bytes for the GDT's starting memory address.
; }