//  1.	initValueArray:
// 	•	Purpose: Prepares a ValueArray for use by initializing its fields to default values.
// 	•	Usage: Called before any operations on the array to ensure it is in a valid state.
// 	2.	writeValueArray:
// 	•	Purpose: Adds a new value to the array, dynamically resizing the array if necessary.
// 	•	Usage: Handles efficient storage and management of an arbitrary number of Value elements.
// 	•	Dynamic Resizing: If the current capacity is insufficient, it grows the array using the GROW_CAPACITY and GROW_ARRAY macros, ensuring efficient memory usage.
// 	3.	freeValueArray:
// 	•	Purpose: Frees the memory allocated for the array and resets its fields to default values.
// 	•	Usage: Prevents memory leaks and prepares the array for reuse or cleanup.
// 	4.	printValue:
// 	•	Purpose: Prints a single value to the console in a human-readable format.
// 	•	Usage: Provides a convenient way to display values for debugging or output purposes.


#include <stdio.h> // Include the standard I/O library for printing values to the console.

#include "memory.h" // Include memory management utilities for dynamic allocation and deallocation.
#include "value.h"  // Include the definition of `Value` and `ValueArray` types used for storing values.

// Initializes a `ValueArray` structure to prepare it for use.
// This function sets initial values and ensures the array is in a valid state for storing values.
void initValueArray(ValueArray* array) {
    array->values = NULL;       // Set the pointer to the values array to NULL (unallocated).
    array->capacity = 0;        // Set the initial capacity to zero, meaning no memory is allocated yet.
    array->count = 0;           // Initialize the count of elements in the array to zero.
}

// Adds a new `Value` to the `ValueArray`, resizing the array if necessary to accommodate the new element.
// This function ensures efficient dynamic resizing to handle arbitrary numbers of values.
void writeValueArray(ValueArray* array, Value value) {
    if (array->capacity < array->count + 1) { // Check if there is enough capacity for a new element.
        int oldCapacity = array->capacity;   // Store the current capacity for resizing calculations.
        array->capacity = GROW_CAPACITY(oldCapacity); // Calculate the new capacity using the `GROW_CAPACITY` macro.
        // Resize the array to the new capacity, reallocating memory if necessary.
        array->values = GROW_ARRAY(Value, array->values, oldCapacity, array->capacity);
    }

    array->values[array->count] = value; // Add the new value to the array at the current count index.
    array->count++;                      // Increment the count of elements in the array.
}

// Frees the memory used by a `ValueArray`, releasing all resources and resetting the array to its initial state.
// This function ensures no memory leaks occur and the array can be reused if needed.
void freeValueArray(ValueArray* array) {
    FREE_ARRAY(Value, array->values, array->capacity); // Free the memory allocated for the values array.
    initValueArray(array);                             // Reinitialize the array to reset its fields.
}

// Prints a single `Value` to the console in a human-readable format.
// The `%g` format specifier is used for printing floating-point values compactly.
// This function is useful for debugging or displaying values stored in the array.
void printValue(Value value) {
    printf("%g", value); // Print the value to the console in a compact format.
}