/**
 * @file elf.h
 * @brief Defines the data structures and constants for the Executable and Linkable Format (ELF).
 * This file provides the C-level representation of the ELF file format, which is used by the
 * kernel to load and execute programs. The structures defined here correspond directly to the
 * official ELF specification for 32-bit systems.
 */

// --- Program Header Flags (p_flags) ---
// These flags define the permissions for a memory segment described by a program header.
#define PF_X 0x01 /**< Execute: The segment is executable. */
#define PF_W 0x02 /**< Write: The segment is writable. */
#define PF_R 0x04 /**< Read: The segment is readable. */

// --- Program Header Types (p_type) ---
// These values identify the type of segment a program header entry describes.
#define PT_NULL    0 /**< Unused program header. */
#define PT_LOAD    1 /**< A loadable segment that should be mapped into memory. */
#define PT_DYNAMIC 2 /**< Dynamic linking information. */
#define PT_INTERP  3 /**< Path to an interpreter (e.g., /lib/ld-linux.so.2). */
#define PT_NOTE    4 /**< Auxiliary information. */
#define PT_SHLIB   5 /**< Reserved. */
#define PT_PHDR    6 /**< The program header table itself. */

// --- Section Header Types (sh_type) ---
// These values identify the type of a section.
#define SHT_NULL     0  /**< Inactive section header. */
#define SHT_PROGBITS 1  /**< Program data (e.g., .text, .data). */
#define SHT_SYMTAB   2  /**< Symbol table. */
#define SHT_STRTAB   3  /**< String table. */
#define SHT_RELA     4  /**< Relocation entries with addends. */
#define SHT_HASH     5  /**< Symbol hash table. */
#define SHT_DYNAMIC  6  /**< Dynamic linking information. */
#define SHT_NOTE     7  /**< Note section. */
#define SHT_NOBITS   8  /**< Section occupies no space in the file (e.g., .bss). */
#define SHT_REL      9  /**< Relocation entries without addends. */
#define SHT_SHLIB    10 /**< Reserved. */
#define SHT_DYNSYM   11 /**< Dynamic linker symbol table. */

// --- ELF File Types (e_type) ---
// These values identify the type of the ELF file.
#define ET_NONE 0 /**< No file type. */
#define ET_REL  1 /**< Relocatable file (e.g., an object file). */
#define ET_EXEC 2 /**< Executable file. */
#define ET_DYN  3 /**< Shared object (e.g., a library). */
#define ET_CORE 4 /**< Core dump. */

// --- ELF Identification (e_ident) ---
// These constants are used to parse the `e_ident` array in the ELF header.
#define EI_NIDENT 16 /**< The size of the e_ident array. */
#define EI_CLASS  4  /**< Index of the byte that specifies the architecture (32/64-bit). */
#define EI_DATA   5  /**< Index of the byte that specifies the data encoding (little/big-endian). */

// --- ELF Class (e_ident[EI_CLASS]) ---
#define ELFCLASS32 1 /**< 32-bit architecture. */
#define ELFCLASS64 2 /**< 64-bit architecture. */

// --- ELF Data Encoding (e_ident[EI_DATA]) ---
#define ELFDATA2LSB 1 /**< Little-endian. */
#define ELFDATA2MSB 2 /**< Big-endian. */

// --- Special Section Indexes (sh_link, sh_info) ---
#define SHN_UNDEF 0 /**< An undefined section reference. */

// --- ELF Data Types ---
// These are the standard 32-bit ELF data types.
typedef uint16_t elf32_half;  /**< 16-bit unsigned integer. */
typedef uint32_t elf32_word;  /**< 32-bit unsigned integer. */
typedef int32_t  elf32_sword; /**< 32-bit signed integer. */
typedef uint32_t elf32_addr;  /**< 32-bit memory address. */
typedef uint32_t elf32_off;   /**< 32-bit file offset. */

// --- Program Header (Segment) ---
// Describes a segment to be loaded into memory. An ELF file has a table of these headers.
struct elf32_phdr
{
    elf32_word p_type;   /**< The type of this segment (e.g., PT_LOAD). */
    elf32_off  p_offset; /**< The offset of the segment in the file image. */
    elf32_addr p_vaddr;  /**< The virtual address where the segment should be loaded. */
    elf32_addr p_paddr;  /**< The physical address (ignored by most systems). */
    elf32_word p_filesz; /**< The size of the segment in the file. */
    elf32_word p_memsz;  /**< The size of the segment in memory (can be larger than p_filesz for .bss). */
    elf32_word p_flags;  /**< Permissions for the segment (e.g., PF_R | PF_X). */
    elf32_word p_align;  /**< The required alignment of the segment in memory. */
} __attribute__((packed));

// --- Section Header ---
// Describes a section in the ELF file (e.g., .text, .data, .symtab).
struct elf32_shdr
{
    elf32_word sh_name;      /**< An offset into the section header string table for the section's name. */
    elf32_word sh_type;      /**< The type of this section (e.g., SHT_PROGBITS). */
    elf32_word sh_flags;     /**< Section-specific flags. */
    elf32_addr sh_addr;      /**< The virtual address of the section in memory (if loaded). */
    elf32_off  sh_offset;    /**< The offset of the section's data in the file. */
    elf32_word sh_size;      /**< The size of the section's data. */
    elf32_word sh_link;      /**< A link to another section (e.g., a symbol table's string table). */
    elf32_word sh_info;      /**< Extra information (depends on section type). */
    elf32_word sh_addralign; /**< The required alignment for the section's data. */
    elf32_word sh_entsize;   /**< The size of each entry in the section, if it's a table. */
} __attribute__((packed));

// --- ELF Header ---
// The main header at the beginning of every ELF file.
struct elf_header
{
    unsigned char e_ident[EI_NIDENT]; /**< The ELF identification bytes (magic number, class, etc.). */
    elf32_half e_type;      /**< The file type (e.g., ET_EXEC for an executable). */
    elf32_half e_machine;   /**< The required architecture (e.g., EM_386 for x86). */
    elf32_word e_version;   /**< The ELF version (should be 1). */
    elf32_addr e_entry;     /**< The virtual address of the program's entry point. */
    elf32_off  e_phoff;     /**< The file offset of the program header table. */
    elf32_off  e_shoff;     /**< The file offset of the section header table. */
    elf32_word e_flags;     /**< Processor-specific flags. */
    elf32_half e_ehsize;    /**< The size of this ELF header. */
    elf32_half e_phentsize; /**< The size of a single entry in the program header table. */
    elf32_half e_phnum;     /**< The number of entries in the program header table. */
    elf32_half e_shentsize; /**< The size of a single entry in the section header table. */
    elf32_half e_shnum;     /**< The number of entries in the section header table. */
    elf32_half e_shstrndx;  /**< The index of the section header that contains the section name string table. */
} __attribute__((packed));

// --- Dynamic Section Entry ---
// Describes a dynamic linking requirement or capability.
struct elf32_dyn
{
    elf32_sword d_tag; /**< The type of this dynamic entry (e.g., DT_NEEDED). */
    union 
    {
        elf32_word d_val; /**< The value of this dynamic entry (e.g., a library name). */
        elf32_addr d_ptr; /**< The address of this dynamic entry (e.g., a function pointer). */
    } d_un; /**< The value or address of this dynamic entry. */
    } d_un;
    
} __attribute__((packed));

struct elf32_sym
{
    elf32_word st_name;
    elf32_addr st_value;
    elf32_word st_size;
    unsigned char st_info;
    unsigned char st_other;
    elf32_half st_shndx;
} __attribute__((packed));

void* elf_get_entry_ptr(struct elf_header* elf_header);
uint32_t elf_get_entry(struct elf_header* elf_header);

#endif