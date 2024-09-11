#include <stdio.h>

#include "memory.h"
#include "value.h"

/**
 * Initializes a ValueArray by setting its capacity, count, and pointer to NULL.
 * 
 * This function sets up the initial state of a ValueArray, which is used to 
 * store an array of values. It ensures the array is ready for future use.
 *
 * @param array A pointer to the ValueArray to be initialized.
 * @return void This function does not return a value.
 */
void initValueArray(ValueArray* array){
    array -> values = NULL;
    array -> capacity = 0;
    array ->count = 0;
}

/**
 * Adds a value to the ValueArray, dynamically resizing the array if necessary.
 * 
 * If the ValueArray has reached its current capacity, the function reallocates 
 * memory to expand the array before adding the new value.
 *
 * @param array A pointer to the ValueArray where the value will be added.
 * @param value The value to be added to the array.
 * @return void This function does not return a value.
 */
void writeValueArray(ValueArray* array, Value value){
    if(array->capacity < array->count + 1){
        int oldCapacity = array->capacity;
        array->capacity = GROW_CAPACITY(oldCapacity);
        array->values = GROW_ARRAY(Value, array->values, oldCapacity, array->capacity);
    }

    array->values[array->count] = value;
    array->count++;
}

/**
 * Frees the memory allocated for the ValueArray.
 * 
 * This function releases the memory associated with the values stored in the ValueArray,
 * and then reinitializes the array to its default state.
 *
 * @param array A pointer to the ValueArray whose memory is to be freed.
 * @return void This function does not return a value.
 */
void freeValueArray(ValueArray* array){
    FREE_ARRAY(Value, array->values, array->capacity);
    initValueArray(array);
}

/**
 * Prints the provided Value in a human-readable format.
 * 
 * This function takes a Value (typically a numerical value) and prints it using
 * a floating-point format.
 *
 * @param value The Value to be printed.
 * @return void This function does not return a value.
 */
void printValue(Value value){
    printf("%g", value);
}

