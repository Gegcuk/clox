#include <stdio.h>

#include "debug.h"

/**
 * Disassembles and prints the contents of a chunk of bytecode.
 * 
 * Iterates over the bytecode instructions in the chunk, disassembling each one.
 *
 * @param chunk A pointer to the chunk of bytecode to disassemble.
 * @param name A string that names the chunk, printed as a header.
 * @return void This function does not return a value.
 */
void disassembleChunk(Chunk* chunk, const char* name){
    printf("== %s ==\n", name);

    for( int offset = 0; offset < chunk->count;){
        offset = disassembleInstruction(chunk, offset);
    }
}

/**
 * Disassembles a single instruction from the chunk of bytecode.
 * 
 * Reads the instruction at the given offset and prints its corresponding operation.
 * If the instruction is recognized (e.g., OP_RETURN), it is printed in a readable format.
 *
 * @param chunk A pointer to the chunk containing the instruction.
 * @param offset The position in the chunk from which to read the instruction.
 * @return int Returns the offset of the next instruction to be processed.
 */
int disassembleInstruction(Chunk* chunk, int offset){
    printf("%04d ", offset);

    uint8_t instruction = chunk->code[offset];
    switch(instruction) {
        case OP_RETURN:
            return simpleInstruction("OP_RETURN", offset);
        default:
            printf("Unknown opcode %d\n", instruction);
            return offset + 1;
    }
}

/**
 * Prints a simple instruction that does not require additional parameters.
 * 
 * Used to handle instructions like OP_RETURN that are straightforward.
 *
 * @param name A string representing the name of the instruction.
 * @param offset The position in the chunk where the instruction is located.
 * @return int Returns the offset of the next instruction to be processed.
 */
static int simpleInstruction(const char* name, int offset){
    printf("%s\n", name);
    return offset + 1;
}