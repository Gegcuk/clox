#include <stdio.h>

#include "debug.h"
#include "value.h"

/**
 * Disassembles and prints the contents of a chunk of bytecode.
 * 
 * This function iterates over the bytecode in the chunk, processing each instruction 
 * and printing it in a human-readable format. It provides a formatted breakdown of 
 * the instructions for debugging or analysis.
 *
 * @param chunk A pointer to the chunk of bytecode to disassemble.
 * @param name A string representing the name of the chunk, printed as a header for context.
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
 * Reads the byte at the given offset in the chunk, determines the type of instruction, 
 * and prints it in a readable format. It handles recognized opcodes such as OP_CONSTANT 
 * and OP_RETURN. If the instruction is unknown, it prints an error message.
 * 
 * @param chunk A pointer to the chunk containing the instruction.
 * @param offset The position in the chunk from which to read the instruction.
 * @return int Returns the offset of the next instruction to be processed.
 */
int disassembleInstruction(Chunk* chunk, int offset){
    printf("%04d ", offset);
    if(offset > 0 && chunk->lines[offset] == chunk->lines[offset-1]) {
        printf("   | ");
    } else {
        printf("%4d ", chunk->lines[offset]);
    }

    uint8_t instruction = chunk->code[offset];
    switch(instruction) {
        case OP_CONSTANT:
            return constantInstruction("OP_CONSTANT", chunk, offset);
        case OP_RETURN:
            return simpleInstruction("OP_RETURN", offset);
        default:
            printf("Unknown opcode %d\n", instruction);
            return offset + 1;
    }
}

/**
 * Disassembles and prints an instruction that refers to a constant.
 * 
 * This function processes an instruction that references a constant (e.g., OP_CONSTANT). 
 * It retrieves the constant index from the next byte and prints both the name of the 
 * instruction and the value of the constant.
 * 
 * @param name A string representing the name of the instruction being disassembled.
 * @param chunk A pointer to the chunk containing the instruction and constants.
 * @param offset The position in the chunk where the instruction is located.
 * @return int Returns the offset of the next instruction to be processed.
 */
static int constantInstruction(const char* name, Chunk* chunk, int offset){
    uint8_t constant = chunk->code[offset + 1];
    printf("%-16s %4d '", name, constant);
    printValue(chunk->constants.values[constant]);
    printf("'\n");
    return offset + 2;
}

/**
 * Prints a simple instruction that does not reference any constants or additional data.
 * 
 * This function is used for instructions that are standalone, such as OP_RETURN, 
 * which don't have any arguments. It prints the instruction name and moves to the next.
 *
 * @param name A string representing the name of the instruction.
 * @param offset The position in the chunk where the instruction is located.
 * @return int Returns the offset of the next instruction to be processed.
 */
static int simpleInstruction(const char* name, int offset){
    printf("%s\n", name);
    return offset + 1;
}