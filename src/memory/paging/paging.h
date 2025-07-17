/**
 * @file paging.h
 * @brief Defines the interface for the kernel's virtual memory and paging system.
 * This system manages the mapping of virtual addresses to physical addresses, providing
 * memory isolation for processes.
 */

// --- Paging Flags ---
// These flags control the properties of a page directory or page table entry.
// #define PAGING_CACHE_DISABLED  0b00010000 // If set, disables caching for the page.
// #define PAGING_WRITE_THROUGH   0b00001000 // If set, enables write-through caching.
// #define PAGING_ACCESS_FROM_ALL 0b00000100 // If set, allows access from user-mode (ring 3).
// #define PAGING_IS_WRITEABLE    0b00000010 // If set, the page is writeable.
// #define PAGING_IS_PRESENT      0b00000001 // If set, the page is present in memory.

// --- Paging Constants ---
// #define PAGING_TOTAL_ENTRIES_PER_TABLE 1024 // A page directory or table has 1024 entries.
// #define PAGING_PAGE_SIZE 4096               // Each page is 4KB.

// Represents a page directory, which manages a 4GB virtual address space.
// struct paging_4gb_chunk
// {
//     uint32_t* directory_entry; // A pointer to the page directory table (an array of 1024 uint32_t).
// };

// Creates and initializes a new page directory for a 4GB address space.
// struct paging_4gb_chunk* paging_new_4gb(uint8_t flags);

// Switches the current page directory by loading the physical address of the new one into CR3.
// void paging_switch(struct paging_4gb_chunk* directory);

// Enables the paging hardware on the CPU by setting the PG bit in CR0.
// void enable_paging();

// Maps a virtual address to a physical address.
// int paging_map(struct paging_4gb_chunk* directory, void* virt, void* phys, int flags);

// Maps a range of virtual addresses to a corresponding range of physical addresses.
// int paging_map_range(struct paging_4gb_chunk* directory, void* virt, void* phys, int count, int flags);

// Maps a virtual address range to a single physical address or a range.
// int paging_map_to(struct paging_4gb_chunk *directory, void *virt, void *phys, void *phys_end, int flags);

// Gets the page table entry for a given virtual address.
// uint32_t paging_get(uint32_t* directory, void* virt);

// Translates a virtual address to its corresponding physical address.
// void* paging_get_physical_address(uint32_t* directory, void* virt);

// Frees all resources associated with a page directory.
// void paging_free_4gb(struct paging_4gb_chunk* chunk);

// --- Utility Functions ---

// Aligns an address down to the nearest 4KB page boundary.
// void* paging_align_to_lower_page(void* addr);

// Aligns an address up to the nearest 4KB page boundary.
// void* paging_align_address(void* ptr);

// Checks if an address is 4KB-aligned.
// bool paging_is_aligned(void* addr);