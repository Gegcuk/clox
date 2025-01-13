#include <stdlib.h> // Include the standard library for memory management functions like `malloc`, `realloc`, and `free`.

#include "memory.h" // Include the header file defining memory management utilities specific to this project.

// Reallocates a block of memory, resizing it to the specified `newSize`.
// If `newSize` is zero, the memory is freed, and NULL is returned.
// If allocation fails, the program exits with an error code.
// This function is a general-purpose utility for dynamic memory management.
void* reallocate(void* pointer, size_t oldSize, size_t newSize) {
    // Check if the new size is zero, which indicates the memory should be freed.
    if (newSize == 0) {
        free(pointer); // Free the memory block pointed to by `pointer`.
        return NULL;   // Return NULL as the block is no longer allocated.
    }

    // Attempt to resize the memory block to the new size using `realloc`.
    void* result = realloc(pointer, newSize);

    // If `realloc` fails, it returns NULL. Exit the program to indicate a fatal error.
    // This ensures that the program does not continue with an invalid memory state.
    if (result == NULL) exit(1);

    // Return the pointer to the resized memory block.
    return result;
}