// Include the GDT header and kernel utilities.

// Encodes a single `gdt_structured` entry into the raw 8-byte GDT format.
// `target` is a pointer to the 8-byte destination in the GDT.
// `source` is the structured GDT entry to encode.
// void encodeGdtEntry(uint8_t* target, struct gdt_structured source)
// {
//     // 1. Check for an invalid segment limit. If the limit is > 64KB, it must be page-aligned.
//     //    If not, it's an error, so panic.

//     // 2. Set the granularity flag. By default, set for 1-byte granularity (target[6] = 0x40).
//     //    If the limit is larger than 65536, switch to 4KB page granularity.
//     //    - Right-shift the limit by 12 bits (divide by 4096).
//     //    - Set the granularity flag bit in the high flags byte (target[6] = 0xC0).

//     // 3. Encode the 20-bit limit into its non-contiguous fields:
//     //    - `target[0]` gets the lowest 8 bits of the limit.
//     //    - `target[1]` gets the next 8 bits.
//     //    - `target[6]` gets the highest 4 bits (ORed with the flags already there).

//     // 4. Encode the 32-bit base address into its non-contiguous fields:
//     //    - `target[2]` gets the lowest 8 bits.
//     //    - `target[3]` gets the next 8 bits.
//     //    - `target[4]` gets the next 8 bits.
//     //    - `target[7]` gets the highest 8 bits.

//     // 5. Set the access byte (`target[5]`) from the `source.type` field.
// }

// Converts an array of `gdt_structured` entries into the hardware-compliant `gdt` format.
// `gdt` is the destination array of raw GDT entries.
// `structured_gdt` is the source array of structured GDT entries.
// `total_entries` is the number of entries to convert.
// void gdt_structured_to_gdt(struct gdt* gdt, struct gdt_structured* structured_gdt, int total_entries)
// {
//     // Loop through each entry in the source array.
//     // For each entry, call `encodeGdtEntry` to perform the conversion and
//     // place the result in the corresponding index of the destination GDT array.
// }