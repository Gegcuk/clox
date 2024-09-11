#include <stdlib.h>

#include "chunk.h"
#include "memory.h"

/**
 * Initializes a chunk of bytecode by setting its count, capacity, and pointers
 * to code and line arrays to zero or NULL. It also initializes the constants array.
 * 
 * This function prepares a chunk for use by setting up the necessary initial values.
 *
 * @param chunk A pointer to the chunk to be initialized.
 * @return void This function does not return a value.
 */
void initChunk (Chunk* chunk){
    chunk->count = 0;
    chunk->capacity = 0;
    chunk->code = NULL;
    chunk->lines = NULL;
    initValueArray(&chunk->constants);
}

/**
 * Frees the memory allocated for a chunk of bytecode, including the arrays
 * for code, lines, and constants. It resets the chunk to its initial state.
 * 
 * This function ensures that all dynamically allocated memory in the chunk is
 * released, and the chunk is re-initialized for potential reuse.
 *
 * @param chunk A pointer to the chunk whose memory is to be freed.
 * @return void This function does not return a value.
 */
void freeChunk (Chunk* chunk){
    FREE_ARRAY(uint8_t, chunk->code, chunk->capacity);
    FREE_ARRAY(int, chunk->lines, chunk->capacity);
    freeValueArray(&chunk->constants);
    initChunk(chunk);
}

/**
 * Writes a byte (instruction) into the chunk of bytecode along with the corresponding
 * line number. If the chunk does not have enough capacity, it resizes its memory 
 * allocation to accommodate the new byte and line.
 * 
 * This function dynamically grows the chunk's code and line arrays as needed.
 *
 * @param chunk A pointer to the chunk where the byte and line should be written.
 * @param byte The byte (instruction) to be added to the chunk.
 * @param line The line number corresponding to the byte being added.
 * @return void This function does not return a value.
 */
void writeChunk(Chunk* chunk, uint8_t byte, int line){
    if(chunk->capacity < chunk->count + 1){
        int oldCapacity = chunk->capacity;
        chunk->capacity = GROW_CAPACITY(oldCapacity);
        chunk->code = GROW_ARRAY(uint8_t, chunk->code, oldCapacity, chunk->capacity);
        chunk->lines = GROW_ARRAY(int, chunk->lines, oldCapacity, chunk->capacity);
    }

    chunk->code[chunk->count] = byte;
    chunk->lines[chunk->count] = line;
    chunk->count++;
}

/**
 * Adds a constant value to the chunk's constants array and returns the index
 * of the constant in the array. The constants array will grow dynamically 
 * if necessary.
 * 
 * This function allows for the efficient storage and retrieval of constant values 
 * that are used in the bytecode.
 *
 * @param chunk A pointer to the chunk whose constants array will be updated.
 * @param value The constant value to be added to the array.
 * @return int The index of the added constant in the constants array.
 */
int addConstant(Chunk* chunk, Value value){
    writeValueArray(&chunk->constants, value);
    return chunk->constants.count-1;
}