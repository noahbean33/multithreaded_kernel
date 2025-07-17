// Header guard to prevent multiple inclusions.
// #ifndef GDT_H
// #define GDT_H

// Include standard integer types.
// #include <stdint.h>

// Represents a single 8-byte GDT entry in the format required by the x86 hardware.
// The fields are broken up非-contiguously as per the architecture specification.
// The `__attribute__((packed))` ensures the struct has no padding.
// struct gdt
// {
//     uint16_t segment;           // Segment Limit (bits 0-15)
//     uint16_t base_first;        // Base Address (bits 0-15)
//     uint8_t base;               // Base Address (bits 16-23)
//     uint8_t access;             // Access Byte (P, DPL, S, E, DC, RW, A)
//     uint8_t high_flags;         // Upper 4 bits of segment limit and 4 flag bits (G, D/B, L, AVL)
//     uint8_t base_24_31_bits;    // Base Address (bits 24-31)
// };

// A programmer-friendly, structured representation of a GDT entry.
// This is easier to work with than the hardware-defined `gdt` struct.
// The `gdt_structured_to_gdt` function converts this into the hardware format.
// struct gdt_structured
// {
//     uint32_t base;  // The 32-bit base address of the segment.
//     uint32_t limit; // The 32-bit limit (size) of the segment.
//     uint8_t type;   // The access byte and high flags combined.
// };

// Loads the Global Descriptor Table Register (GDTR) with the address and size of the GDT.
// This is an external function implemented in assembly (`gdt.asm`).
// void gdt_load(struct gdt* gdt, int size);

// Converts an array of `gdt_structured` entries into the hardware-compliant `gdt` format.
// It iterates through the structured entries and maps their base, limit, and type
// to the corresponding bit-packed fields in the final GDT.
// void gdt_structured_to_gdt(struct gdt* gdt, struct gdt_structured* structured_gdt, int total_entries);

// End of header guard.
// #endif