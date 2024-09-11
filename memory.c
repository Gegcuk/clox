#include <stdlib.h>

#include "memory.h"

/**
 * Resizes a memory block to a new size.
 * 
 * This function dynamically allocates, resizes, or frees memory as needed. 
 * If the new size is zero, the memory is freed. If the reallocation fails, 
 * the program exits with an error.
 *
 * @param pointer A pointer to the current memory block, or NULL.
 * @param oldSize The size of the memory block before resizing.
 * @param newSize The size of the memory block after resizing.
 * @return void* Returns a pointer to the newly allocated memory, or NULL if freed.
 */
void* reallocate(void* pointer, size_t oldSize, size_t newSize){
    if(newSize == 0){
        free(pointer);
        return NULL;
    }

    void* result = realloc(pointer, newSize);
    if(result == NULL) exit(1);
    return result;
}