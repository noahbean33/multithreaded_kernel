/**
 * @file elfloader.h
 * @brief Defines the public interface for the kernel's ELF file loader.
 * This interface provides functions to load an ELF file from the filesystem, inspect its headers,
 * and manage its representation in memory.
 */

// Represents a loaded ELF file in memory.
// This structure holds all the necessary information about the executable, including its memory layout
// and pointers to its various components.
// struct elf_file
// {
//     // The filename from which the ELF file was loaded.
//     char filename[PEACHOS_MAX_PATH];
//
//     // The total size of the ELF file data as read into memory.
//     int in_memory_size;
//
//     // A pointer to the raw contents of the ELF file, loaded into physical memory.
//     void* elf_memory;
//
//     // The base virtual address where the executable expects to be loaded.
//     // This is typically derived from the program headers.
//     void* virtual_base_address;
//
//     // The highest virtual address used by the executable.
//     void* virtual_end_address;
//
//     // The base physical address where the executable is actually loaded in memory.
//     void* physical_base_address;
//
//     // The highest physical address used by the executable in memory.
//     void* physical_end_address;
// };

// Loads an ELF file from the filesystem into memory and prepares it for execution.
// - filename: The path to the ELF file to load.
// - file_out: A pointer to a `struct elf_file*` that will be populated with the loaded file's info.
// - returns: 0 on success, or a negative error code on failure.
// int elf_load(const char* filename, struct elf_file** file_out);

// Allocates and initializes a new, empty `elf_file` structure.
// - returns: A pointer to the newly allocated structure.
// struct elf_file* elf_file_new();

// Frees all resources associated with a loaded ELF file.
// This includes the `elf_file` structure itself and the memory holding the file's contents.
// - file: The ELF file to free.
// void elf_file_free(struct elf_file* file);

// An alias for `elf_file_free`.
// void elf_close(struct elf_file* file);

// --- Accessor Functions ---
// These functions provide convenient access to the properties of a loaded ELF file.

// Returns the base virtual address of the loaded ELF file.
// void* elf_virtual_base(struct elf_file* file);

// Returns the end virtual address of the loaded ELF file.
// void* elf_virtual_end(struct elf_file* file);

// Returns the base physical address of the loaded ELF file.
// void* elf_phys_base(struct elf_file* file);

// Returns the end physical address of the loaded ELF file.
// void* elf_phys_end(struct elf_file* file);

// --- ELF Structure Accessors ---
// These functions provide pointers to the core structures within the loaded ELF file data.

// Returns a pointer to the main ELF header.
// struct elf_header* elf_header(struct elf_file* file);

// Returns a pointer to the section header table.
// struct elf32_shdr* elf_sheader(struct elf_header* header);

// Returns a pointer to the raw memory buffer containing the ELF file.
// void* elf_memory(struct elf_file* file);

// Returns a pointer to the program header table.
// struct elf32_phdr* elf_pheader(struct elf_header* header);

// Returns a pointer to a specific program header entry by its index.
// struct elf32_phdr* elf_program_header(struct elf_header* header, int index);

// Returns a pointer to a specific section header entry by its index.
// struct elf32_shdr* elf_section(struct elf_header* header, int index);

// Calculates the final physical address of a program header's data in memory.
// This is done by adding the segment's offset within the ELF file to the file's base physical address.
// void* elf_phdr_phys_address(struct elf_file* file, struct elf32_phdr* phdr);