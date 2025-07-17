; section .asm
; This section contains the assembly code for low-level I/O operations.

; Make the following function names visible to the linker.
; global insb, insw, outb, outw

; --- insb: Read a byte from an I/O port ---
; insb:
    ; Standard function prologue: save the old base pointer and set up the new one.
    ; push ebp
    ; mov ebp, esp

    ; Clear the EAX register to ensure no garbage in the upper bits.
    ; xor eax, eax
    ; Move the first argument (port number) from the stack into the EDX register.
    ; mov edx, [ebp+8]
    ; Execute the `in` instruction to read a byte from the port specified in DX into AL.
    ; in al, dx

    ; Standard function epilogue: restore the old base pointer and return.
    ; The return value is in AL.
    ; pop ebp
    ; ret

; --- insw: Read a word from an I/O port ---
; insw:
    ; Standard function prologue.
    ; push ebp
    ; mov ebp, esp

    ; Clear the EAX register.
    ; xor eax, eax
    ; Move the port number from the stack into EDX.
    ; mov edx, [ebp+8]
    ; Read a 16-bit word from the port into AX.
    ; in ax, dx

    ; Standard function epilogue. The return value is in AX.
    ; pop ebp
    ; ret

; --- outb: Write a byte to an I/O port ---
; outb:
    ; Standard function prologue.
    ; push ebp
    ; mov ebp, esp

    ; Move the second argument (the byte value) from the stack into EAX.
    ; mov eax, [ebp+12]
    ; Move the first argument (the port number) from the stack into EDX.
    ; mov edx, [ebp+8]
    ; Execute the `out` instruction to write the byte in AL to the port in DX.
    ; out dx, al

    ; Standard function epilogue.
    ; pop ebp
    ; ret

; --- outw: Write a word to an I/O port ---
; outw:
    ; Standard function prologue.
    ; push ebp
    ; mov ebp, esp

    ; Move the word value from the stack into EAX.
    ; mov eax, [ebp+12]
    ; Move the port number from the stack into EDX.
    ; mov edx, [ebp+8]
    ; Write the word in AX to the port in DX.
    ; out dx, ax

    ; Standard function epilogue.
    ; pop ebp
    ; ret