; Specify that this is 32-bit code.
; [BITS 32]

; Export the _start and kernel_registers symbols to be used by the linker.
; global _start
; global kernel_registers

; Import the kernel_main symbol, which is defined in a C file.
; extern kernel_main

; Define constants for GDT selectors.
; CODE_SEG equ 0x08 ; Kernel code segment selector
; DATA_SEG equ 0x10 ; Kernel data segment selector

; The entry point of the kernel.
; _start:
    ; // Set up all segment registers to point to the kernel's data segment.
    ; mov ax, DATA_SEG
    ; mov ds, ax
    ; mov es, ax
    ; mov fs, ax
    ; mov gs, ax
    ; mov ss, ax

    ; // Set up the stack pointer to a safe location (2MB).
    ; mov ebp, 0x00200000
    ; mov esp, ebp

    ; // --- Remap the Programmable Interrupt Controller (PIC) ---
    ; // Start the initialization sequence for the master PIC.
    ; mov al, 0x11 ; ICW1: Initialize, ICW4 needed
    ; out 0x20, al

    ; // Set the master PIC's starting interrupt vector to 0x20 (32).
    ; mov al, 0x20 ; ICW2: Master PIC vector offset
    ; out 0x21, al

    ; // Tell the master PIC there is a slave PIC at IRQ2.
    ; mov al, 0x04 ; ICW3: Tell Master PIC that there is a slave PIC at IRQ2 (0000 0100)
    ; out 0x21, al

    ; // Set the PIC to 8086/88 (non-buffered) mode.
    ; mov al, 0x01 ; ICW4: 8086/88 (MCS-80/85) mode
    ; out 0x21, al
    ; // --- End of PIC Remapping ---

    ; // Call the main C function of the kernel.
    ; call kernel_main

    ; // If kernel_main returns, halt the CPU in an infinite loop.
    ; jmp $

; A function to set the data segment registers. Might be used for context switching.
; kernel_registers:
    ; // Load the kernel data segment selector.
    ; mov ax, DATA_SEG
    ; mov ds, ax
    ; mov es, ax
    ; mov gs, ax
    ; mov fs, ax
    ; // Return to the caller.
    ; ret

; Pad the rest of the file to 512 bytes with zeros.
; This is often used in bootloaders, but here it might just be for section alignment.
; times 512-($ - $$) db 0
