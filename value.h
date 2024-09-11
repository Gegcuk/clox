#ifndef clox_value_h
#define clox_value_h

#include "common.h"

/**
 * Defines the type of values used in the virtual machine.
 * 
 * Currently, a `Value` is represented as a `double`, allowing for numerical
 * operations with floating-point precision.
 */
typedef double Value;

/**
 * A dynamic array for storing `Value` types.
 * 
 * This struct manages a dynamically allocated array of `Value` elements, 
 * including information about the current capacity and the number of elements.
 */
typedef struct {
    int capacity;    /**< The total allocated capacity of the array. */
    int count;       /**< The current number of elements in the array. */
    Value* values;   /**< Pointer to the dynamically allocated array of values. */
} ValueArray;

/**
 * Initializes a `ValueArray` by setting its initial values.
 * 
 * This function prepares a `ValueArray` for use, setting its capacity, count, 
 * and pointer to NULL. It is the first step before using the array.
 *
 * @param array A pointer to the `ValueArray` to be initialized.
 * @return void This function does not return a value.
 */
void initValueArray(ValueArray* array);

/**
 * Adds a value to the `ValueArray`, resizing it if necessary.
 * 
 * This function appends a `Value` to the `ValueArray`. If the array has reached its
 * current capacity, it dynamically grows the array before adding the new value.
 *
 * @param array A pointer to the `ValueArray` where the value will be added.
 * @param value The `Value` to be added to the array.
 * @return void This function does not return a value.
 */
void writeValueArray(ValueArray* array, Value value);

/**
 * Frees the memory used by a `ValueArray`.
 * 
 * This function releases the memory allocated for the `ValueArray` and resets it to 
 * its initial state, making it safe to reuse or discard the array.
 *
 * @param array A pointer to the `ValueArray` whose memory is to be freed.
 * @return void This function does not return a value.
 */
void freeValueArray(ValueArray* array);

/**
 * Prints a `Value` in a human-readable format.
 * 
 * This function takes a `Value` (currently a `double`) and prints it 
 * in a formatted output for debugging or logging purposes.
 *
 * @param value The `Value` to be printed.
 * @return void This function does not return a value.
 */
void printValue(Value value);

#endif    