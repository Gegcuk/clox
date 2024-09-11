#include <stdlib.h>

#include "chunk.h"
#include "memory.h"

/**
 * Initializes a chunk of bytecode by setting its count and capacity to zero.
 * 
 * This function prepares a chunk for use by setting initial values and 
 * nullifying the code array pointer.
 *
 * @param chunk A pointer to the chunk to be initialized.
 * @return void This function does not return a value.
 */
void initChunk (Chunk* chunk){
    chunk->count = 0;
    chunk->capacity = 0;
    chunk->code = NULL;
    initValueArray(&chunk->constants);
}

/**
 * Frees the memory allocated for a chunk of bytecode.
 * 
 * This function releases any dynamically allocated memory in the chunk 
 * and resets it to its initial state.
 *
 * @param chunk A pointer to the chunk whose memory is to be freed.
 * @return void This function does not return a value.
 */
void freeChunk (Chunk* chunk){
    FREE_ARRAY(uint8_t, chunk->code, chunk->capacity);
    freeValueArray(&chunk->constants);
    initChunk(chunk);
}

/**
 * Writes a byte (instruction) into the chunk of bytecode.
 * 
 * If the chunk does not have enough capacity, the function resizes 
 * the chunk's memory allocation to accommodate the new byte.
 *
 * @param chunk A pointer to the chunk where the byte should be written.
 * @param byte The byte (instruction) to be added to the chunk.
 * @return void This function does not return a value.
 */
void writeChunk(Chunk* chunk, uint8_t byte){
    if(chunk->capacity < chunk->count + 1){
        int oldCapacity = chunk->capacity;
        chunk->capacity = GROW_CAPACITY(oldCapacity);
        chunk->code = GROW_ARRAY(uint8_t, chunk->code, oldCapacity, chunk->capacity);
    }

    chunk->code[chunk->count] = byte;
    chunk->count++;
}

int addConstant(Chunk* chunk, Value value){
    writeValueArray(&chunk->constants, value);
    return chunk->constants.count-1;
}