/**
 * @file kheap.h
 * @brief Defines the public interface for the kernel's heap memory management.
 */

// Initializes the kernel's heap, making it ready for allocations.
// void kheap_init();

// Allocates a block of memory of a given size from the kernel heap.
// void* kmalloc(size_t size);

// Allocates a block of memory and initializes its contents to zero.
// void* kzalloc(size_t size);

// Frees a previously allocated block of memory.
// void kfree(void* ptr);