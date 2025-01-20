#ifndef clox_chunk_h
#define clox_chunk_h

// Include common definitions and utility macros/functions for portability and standard functionality.
#include "common.h"

// Include the definition of `Value` and `ValueArray` types, used for storing and managing constant values.
#include "value.h"

// Enum representing the various operation codes (opcodes) used in the virtual machine's bytecode.
// These opcodes are used to identify the operations to be performed during execution.
typedef enum {
    OP_CONSTANT, // Push a constant value onto the stack.
    OP_ADD,
    OP_SUBTRACT,
    OP_MULTIPLY,
    OP_DIVIDE,
    OP_NEGATE,
    OP_RETURN,   // Return from the current function or script execution.
} OpCode;

// Structure representing a "Chunk" of bytecode, which is a sequence of instructions (opcodes) and their associated metadata.
// This structure is used to store and manage the bytecode for a function or script in the virtual machine.
typedef struct {
    int count;           // The number of bytes currently stored in the `code` array.
    int capacity;        // The total capacity of the `code` array, dynamically resized as needed.
    uint8_t* code;       // Pointer to the array of bytecode instructions.
    int* lines;          // Pointer to the array of line numbers, corresponding to each instruction in `code`.
    ValueArray constants; // Array of constants used in the chunk, such as numbers or strings.
} Chunk;

// Initializes a `Chunk` structure, preparing it for use by setting initial values and allocating resources as necessary.
// This function ensures the chunk is in a consistent and ready state for further operations.
void initChunk(Chunk* chunk);

// Frees the resources associated with a `Chunk` structure, including memory allocated for code, lines, and constants.
// This function prevents memory leaks and resets the chunk to an initialized state.
void freeChunk(Chunk* chunk);

// Appends a single byte (instruction) and its associated line number to a `Chunk`.
// This function dynamically resizes the storage as needed and updates the metadata.
void writeChunk(Chunk* chunk, uint8_t byte, int line);

// Adds a constant value to the chunk's constants array and returns its index.
// This function enables efficient storage and reuse of constant values during execution.
int addConstant(Chunk* chunk, Value value);

#endif // End of include guard