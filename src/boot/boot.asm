; Set the origin address. The BIOS loads the bootsector at 0x7C00.
; ORG 0x7c00

; We are in 16-bit real mode.
; BITS 16

; Calculate GDT segment selectors.
; CODE_SEG equ gdt_code - gdt_start
; DATA_SEG equ gdt_data - gdt_start

; Jump to the main bootloader code.
; jmp short start
; nop

; --- FAT16 BIOS Parameter Block (BPB) ---
; This structure provides information about the filesystem.
; OEMIdentifier           db 'PEACHOS '
; BytesPerSector          dw 0x200       ; 512 bytes
; SectorsPerCluster       db 0x80        ; 128 sectors
; ReservedSectors         dw 200
; FATCopies               db 0x02        ; 2 FATs
; RootDirEntries          dw 0x40        ; 64 entries
; NumSectors              dw 0x00        ; Total sectors (if < 65536)
; MediaType               db 0xF8        ; Fixed disk
; SectorsPerFat           dw 0x100       ; 256 sectors
; SectorsPerTrack         dw 0x20        ; 32 sectors
; NumberOfHeads           dw 0x40        ; 64 heads
; HiddenSectors           dd 0x00
; SectorsBig              dd 0x773594    ; Total sectors (if > 65536)

; --- Extended BPB (DOS 4.0) ---
; DriveNumber             db 0x80        ; 0x80 for hard disk
; WinNTBit                db 0x00
; Signature               db 0x29        ; Extended boot signature
; VolumeID                dd 0xD105
; VolumeIDString          db 'PEACHOS BOO'
; SystemIDString          db 'FAT16   '

; Main entry point of the bootloader.
; start:
    ; Perform a far jump to set CS to 0.
    ; jmp 0:step2

; step2:
    ; Disable interrupts for critical setup.
    ; cli
    ; Initialize segment registers to 0.
    ; mov ax, 0x00
    ; mov ds, ax
    ; mov es, ax
    ; mov ss, ax
    ; mov fs, ax
    ; mov gs, ax

    ; Set the stack pointer just below the bootloader's load address.
    ; mov sp, 0x7c00
    ; Re-enable interrupts.
    ; sti

; --- Switch to Protected Mode ---
; .load_protected:
    ; cli
    ; Load the Global Descriptor Table (GDT).
    ; lgdt[gdt_descriptor]
    ; Set the PE (Protection Enable) bit in the CR0 register to enter protected mode.
    ; mov eax, cr0
    ; or eax, 0x1
    ; mov cr0, eax
    ; Far jump to our 32-bit code to flush the CPU pipeline and load CS with the code segment selector.
    ; jmp CODE_SEG:load32

; --- Global Descriptor Table (GDT) ---
; gdt_start:
; The null descriptor, required by the GDT.
; gdt_null:
    ; dd 0x0
    ; dd 0x0

; Code Segment Descriptor (CS).
; gdt_code:
    ; dw 0xffff      ; Limit (first 16 bits)
    ; dw 0           ; Base (first 16 bits)
    ; db 0           ; Base (bits 16-23)
    ; db 0x9a        ; Access byte: Present, Ring 0, Code, Executable, Readable
    ; db 11001111b   ; Flags (Granularity=4KB, 32-bit) and Limit (last 4 bits)
    ; db 0           ; Base (bits 24-31)

; Data Segment Descriptor (DS, SS, ES, FS, GS).
; gdt_data:
    ; dw 0xffff      ; Limit (first 16 bits)
    ; dw 0           ; Base (first 16 bits)
    ; db 0           ; Base (bits 16-23)
    ; db 0x92        ; Access byte: Present, Ring 0, Data, Writable
    ; db 11001111b   ; Flags (Granularity=4KB, 32-bit) and Limit (last 4 bits)
    ; db 0           ; Base (bits 24-31)

; gdt_end:

; GDT Descriptor structure (pointer to the GDT).
; gdt_descriptor:
    ; dw gdt_end - gdt_start - 1 ; Size of the GDT
    ; dd gdt_start               ; Start address of the GDT

; --- 32-bit Protected Mode Code ---
; [BITS 32]
; load32:
    ; Update segment registers to use the new GDT data segment.
    ; mov ax, DATA_SEG
    ; mov ds, ax
    ; mov es, ax
    ; mov fs, ax
    ; mov gs, ax
    ; mov ss, ax

    ; Enable the A20 line to access memory above 1MB.
    ; in al, 0x92
    ; or al, 2
    ; out 0x92, al

    ; --- Load Kernel from Disk ---
    ; Set up parameters for the disk read.
    ; mov eax, 1         ; LBA (Logical Block Address) to start reading from (sector 1).
    ; mov ecx, 100       ; Number of sectors to read.
    ; mov edi, 0x0100000 ; Destination address in memory (1MB).

    ; Call the disk read function.
    ; call ata_lba_read

    ; Jump to the loaded kernel code at 1MB.
    ; jmp CODE_SEG:0x0100000

; --- ATA LBA Read Function ---
; Reads sectors from the primary ATA drive using 28-bit LBA.
; ata_lba_read:
    ; mov ebx, eax ; Backup LBA.

    ; --- Send LBA Address and Sector Count to ATA Controller ---
    ; Send bits 24-27 of LBA, plus drive select (Master=0xE0).
    ; shr eax, 24
    ; or eax, 0xE0
    ; out 0x1F6, al

    ; Send sector count.
    ; mov eax, ecx
    ; out 0x1F2, al

    ; Send bits 0-7 of LBA.
    ; mov eax, ebx
    ; out 0x1F3, al

    ; Send bits 8-15 of LBA.
    ; mov eax, ebx
    ; shr eax, 8
    ; out 0x1F4, al

    ; Send bits 16-23 of LBA.
    ; mov eax, ebx
    ; shr eax, 16
    ; out 0x1F5, al

    ; Send the READ SECTORS command (0x20) to the command port.
    ; mov al, 0x20
    ; out 0x1F7, al

    ; --- Read Sectors from Disk ---
; .next_sector:
    ; push ecx ; Save the outer loop counter (total sectors).

    ; Poll the status port until the drive is ready (BSY is clear, DRQ is set).
; .try_again:
    ; in al, 0x1F7
    ; test al, 8   ; Test DRQ bit.
    ; jz .try_again

    ; Read one sector (256 words = 512 bytes) from the data port.
    ; mov ecx, 256
    ; rep insw

    ; pop ecx ; Restore the outer loop counter.
    ; loop .next_sector ; Repeat for all sectors.
    ; ret

; --- Bootloader Signature ---
; Pad the rest of the bootsector with zeros.
; times 510 - ($ - $$) db 0
; The boot signature 0xAA55 must be at the end of the 512-byte sector.
; dw 0xAA55
