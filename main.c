#include "common.h" // Include common utilities and definitions for portability and standard functionality.
#include "chunk.h"  // Include the definitions and functions for managing chunks of bytecode.
#include "debug.h"  // Include the debugging utilities for disassembling and analyzing bytecode.
#include "vm.h"

int main(int argc, const char* argv[]) {
    // Entry point of the program. Takes command-line arguments but does not use them in this example.

    initVM();

    Chunk chunk;             // Declare a `Chunk` structure to hold the bytecode and associated metadata.
    initChunk(&chunk);       // Initialize the chunk to prepare it for storing instructions and constants.

    // Add a constant value (1.2) to the chunk's constants array and store its index.
    // This value can be referenced later by the bytecode.
    int constant = addConstant(&chunk, 1.2);

    // Write the `OP_CONSTANT` instruction to the chunk, specifying the line number 123.
    // This instruction tells the virtual machine to push a constant onto the stack.
    writeChunk(&chunk, OP_CONSTANT, 123);

    // Write the index of the constant value to the chunk, on the same line (123).
    // This index is used by the `OP_CONSTANT` instruction to reference the correct value.
    writeChunk(&chunk, constant, 123);

    // Write the `OP_RETURN` instruction to the chunk, specifying the line number 123.
    // This instruction signals the end of execution or the return from a function.
    writeChunk(&chunk, OP_RETURN, 123);

    // Disassemble the chunk, printing its contents in a human-readable format for debugging.
    // The name "test chunk" is used as a header in the output.
    disassembleChunk(&chunk, "test chunk");

    freeVM();

    // Free the memory used by the chunk, including its code, line numbers, and constants.
    // This step is crucial to avoid memory leaks.
    freeChunk(&chunk);

    return 0; // Indicate that the program executed successfully.
}