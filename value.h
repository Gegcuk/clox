#ifndef clox_value_h
#define clox_value_h

// Include common definitions and utilities for portability and standard functionality.
#include "common.h"

// Define `Value` as a type alias for `double`.
// This represents the type of values that the virtual machine can store and manipulate.
// Using a typedef allows flexibility to change the value type (e.g., to support other data types) in the future.
typedef double Value;

// Define the `ValueArray` structure to store a dynamic collection of `Value` elements.
// This structure provides a resizable array for managing multiple values efficiently.
typedef struct {
    int capacity;   // The total number of elements the array can currently hold.
    int count;      // The current number of elements in the array.
    Value* values;  // Pointer to the dynamically allocated array of `Value` elements.
} ValueArray;

// Function declarations for managing a `ValueArray`.

// Initializes a `ValueArray`, preparing it for use.
// Sets initial values for capacity, count, and pointer to ensure the array is in a valid state.
void initValueArray(ValueArray* array);

// Adds a `Value` to the `ValueArray`, resizing it if necessary.
// Handles dynamic memory allocation to accommodate an arbitrary number of elements.
void writeValueArray(ValueArray* array, Value value);

// Frees the memory used by a `ValueArray` and resets it to its initial state.
// Ensures proper cleanup of dynamically allocated memory to prevent leaks.
void freeValueArray(ValueArray* array);

// Prints a single `Value` to the console.
// Provides a convenient way to display values for debugging or output purposes.
void printValue(Value value);

#endif // End of include guard