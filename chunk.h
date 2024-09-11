#ifndef clox_chunk_c
#define clox_chunk_c

#include "common.h"
#include "value.h"

/**
 * Enumeration of the different operation codes (opcodes) used in the bytecode.
 * 
 * OP_CONSTANT: Refers to a constant value in the constants array.
 * OP_RETURN: Marks the end of a function or program execution.
 */
typedef enum {
    OP_CONSTANT,  /**< Refers to a constant value in the constants array. */
    OP_RETURN,    /**< Marks the end of a function or program execution. */
} OpCode;

/**
 * A struct representing a chunk of bytecode.
 * 
 * The chunk contains dynamically allocated arrays to store bytecode instructions,
 * the line numbers corresponding to each instruction, and an array of constants used by the bytecode.
 */
typedef struct {
    int count;          /**< Number of bytecode instructions in the chunk. */
    int capacity;       /**< The total allocated capacity of the bytecode array. */
    uint8_t* code;      /**< Dynamically allocated array holding the bytecode instructions. */
    int* lines;         /**< Array storing line numbers corresponding to each instruction. */
    ValueArray constants; /**< Array holding constants referenced by the bytecode. */
} Chunk;

/**
 * Initializes a Chunk by setting its initial values and preparing it for use.
 * 
 * @param chunk A pointer to the Chunk to be initialized.
 * @return void This function does not return a value.
 */
void initChunk(Chunk* chunk);

/**
 * Frees the memory allocated for a Chunk, including its bytecode and constants.
 * 
 * @param chunk A pointer to the Chunk whose memory is to be freed.
 * @return void This function does not return a value.
 */
void freeChunk(Chunk* chunk);

/**
 * Writes a byte (instruction) and its corresponding line number into the chunk of bytecode.
 * 
 * If the chunk's capacity is not large enough, this function reallocates memory to expand it.
 *
 * @param chunk A pointer to the Chunk where the byte and line will be added.
 * @param byte The byte (instruction) to be added to the Chunk.
 * @param line The line number corresponding to the byte being added.
 * @return void This function does not return a value.
 */
void writeChunk(Chunk* chunk, uint8_t byte, int line);

/**
 * Adds a constant value to the chunk's constants array and returns its index.
 * 
 * This function dynamically grows the constants array if needed and stores the new value in the chunk.
 *
 * @param chunk A pointer to the Chunk whose constants array will be updated.
 * @param value The constant value to be added to the array.
 * @return int The index of the added constant in the constants array.
 */
int addConstant(Chunk* chunk, Value value);

#endif