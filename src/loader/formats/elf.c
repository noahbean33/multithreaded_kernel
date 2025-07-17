/**
 * @file elf.c
 * @brief Implements helper functions for accessing ELF file properties.
 */

// Retrieves the program's entry point as a void pointer.
// - elf_header: A pointer to the ELF file's main header.
// - returns: The virtual address of the program's first instruction to be executed.
// void* elf_get_entry_ptr(struct elf_header* elf_header)
// {
//     // Pseudocode:
//     // 1. Access the `e_entry` field from the provided ELF header.
//     // 2. Cast the entry point address to a void pointer.
//     // 3. Return the pointer.
// }

// Retrieves the program's entry point as a 32-bit integer.
// - elf_header: A pointer to the ELF file's main header.
// - returns: The virtual address of the program's entry point.
// uint32_t elf_get_entry(struct elf_header* elf_header)
// {
//     // Pseudocode:
//     // 1. Access the `e_entry` field from the provided ELF header.
//     // 2. Return the 32-bit address value.
// }