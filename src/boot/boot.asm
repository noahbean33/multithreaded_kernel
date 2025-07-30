; Ralf Brown's Interrupt List: https://www.ctyme.com/rbrown.htm
; nasm -f bin boot.asm -o boot.img
; qemu-system-x86_64 -drive format=raw,file=boot.img
; -------------  boot.asm (NASM, 512 B) -------------
ORG 0x7C00
BITS 16

start:
    cli                 ; no interrupts while we move segment regs
    xor ax, ax
    mov ds, ax          ; DS = 0000  (where BIOS loaded us)
    mov ss, ax
    mov sp, 0x7C00      ; simple stack above our sector
    sti                 ; re‑enable interrupts

    mov si, message     ; DS:SI -> zero‑terminated text
    call print
    jmp $               ; spin forever (could also 'hlt' in a loop)

; --- print DS:SI ASCIIZ -----------------------------
print:
    lodsb               ; AL = *SI++, SI auto‑inc
    test al, al
    jz   .done
    mov ah, 0x0E        ; BIOS teletype
    mov bh, 0           ; page 0
    int 0x10
    jmp  print
.done:
    ret
; ----------------------------------------------------

message db 'Hello World!', 0

times 510 - ($ - $$) db 0   ; pad to 510 bytes
dw 0xAA55                   ; mandatory boot signature
