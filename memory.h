#ifndef clox_memory_h
#define clox_memory_h

// Include common definitions and utilities for portability and standard functionality.
#include "common.h"

// Macro to calculate the new capacity for a dynamically resizing array.
// If the current capacity is less than 8, it grows to 8. Otherwise, it doubles the capacity.
// This ensures efficient resizing, balancing memory usage and performance.
#define GROW_CAPACITY(capacity) ((capacity) < 8 ? 8 : (capacity) * 2)

// Macro to resize a dynamically allocated array of a specific type.
// Parameters:
// - `type`: The data type of the elements in the array.
// - `pointer`: Pointer to the existing array.
// - `oldCount`: The current number of elements in the array.
// - `newCount`: The new desired number of elements in the array.
// The macro uses the `reallocate` function to resize the array and casts the result to the appropriate type.
#define GROW_ARRAY(type, pointer, oldCount, newCount) \
    (type*)reallocate(pointer, sizeof(type) * (oldCount), \
        sizeof(type) * (newCount))

// Macro to free a dynamically allocated array of a specific type.
// Parameters:
// - `type`: The data type of the elements in the array.
// - `pointer`: Pointer to the existing array to be freed.
// - `oldCount`: The current number of elements in the array.
// The macro uses the `reallocate` function to release the memory by setting the new size to 0.
#define FREE_ARRAY(type, pointer, oldCount) \
    reallocate(pointer, sizeof(type) * (oldCount), 0)

// Function declaration for the `reallocate` function.
// This function handles memory allocation, resizing, and deallocation.
// Parameters:
// - `pointer`: Pointer to the memory block to be resized or freed.
// - `oldSize`: The current size of the memory block in bytes.
// - `newSize`: The desired size of the memory block in bytes.
// Returns a pointer to the newly allocated memory or `NULL` if `newSize` is 0.
void* reallocate(void* pointer, size_t oldSize, size_t newSize);

#endif // End of include guard