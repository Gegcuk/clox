#ifndef clox_memory_h
#define clox_memory_h

#include "common.h"

/**
 * Macro to calculate the new capacity for a dynamically growing array.
 * 
 * If the current capacity is less than 8, it returns 8. Otherwise, it doubles 
 * the capacity. This is used for dynamically resizing arrays or buffers.
 *
 * @param capacity The current capacity of the array.
 * @return int The new capacity, either 8 or double the current capacity.
 */
#define GROW_CAPACITY(capacity) ((capacity) < 8 ? 8 : (capacity) * 2)

/**
 * Macro to grow a dynamically allocated array.
 * 
 * This macro resizes a given array to the new size, allocating memory using the
 * `reallocate` function. It is used to increase the capacity of an array as more
 * elements are added.
 *
 * @param type The type of elements in the array (e.g., int, float, etc.).
 * @param pointer The pointer to the current array.
 * @param oldCount The current number of elements in the array.
 * @param newCount The new number of elements in the resized array.
 * @return type* A pointer to the newly resized array.
 */
#define GROW_ARRAY(type, pointer, oldCount, newCount) \
    (type*)reallocate(pointer, sizeof(type) * (oldCount), sizeof(type) * (newCount))

/**
 * Macro to free a dynamically allocated array.
 * 
 * This macro deallocates memory for a given array by calling the `reallocate` function
 * with a size of 0, effectively freeing the memory. It is used when the array is no longer needed.
 *
 * @param type The type of elements in the array.
 * @param pointer The pointer to the array to be freed.
 * @param oldCount The current number of elements in the array.
 * @return void
 */
#define FREE_ARRAY(type, pointer, oldCount) reallocate(pointer, sizeof(type) * (oldCount), 0)

/**
 * Reallocates a block of memory to a new size.
 * 
 * This function is used for dynamically resizing or freeing memory. If the `newSize` is 0,
 * it frees the memory. Otherwise, it resizes the block of memory to the new size.
 *
 * @param pointer A pointer to the memory block to be reallocated (or freed).
 * @param oldSize The old size of the memory block.
 * @param newSize The new size of the memory block.
 * @return void* A pointer to the reallocated memory block, or NULL if freed.
 */
void* reallocate(void* pointer, size_t oldSize, size_t newSize);

#endif