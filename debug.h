#ifndef clox_debug_h
#define clox_debug_h

#include "chunk.h"

/**
 * Disassembles and prints the contents of a chunk of bytecode.
 * 
 * This function iterates over the bytecode in the chunk, disassembling each instruction
 * and printing it in a human-readable format. It provides a formatted breakdown of the
 * instructions for debugging or analysis.
 *
 * @param chunk A pointer to the chunk of bytecode to disassemble.
 * @param name A string that names the chunk, printed as a header.
 * @return void This function does not return a value.
 */
void disassembleChunk(Chunk* chunk, const char* name);

/**
 * Disassembles a single instruction from the chunk of bytecode.
 * 
 * Reads the instruction at the given offset, decodes it, and prints the corresponding
 * operation in a human-readable format. The function handles known opcodes, and 
 * it moves the offset forward after processing each instruction.
 *
 * @param chunk A pointer to the chunk containing the instruction.
 * @param offset The position in the chunk from which to read the instruction.
 * @return int Returns the offset of the next instruction to be processed.
 */
int disassembleInstruction(Chunk* chunk, int offset);

/**
 * Prints a simple instruction that does not reference any constants or additional data.
 * 
 * This function is used for disassembling straightforward instructions (like OP_RETURN)
 * that don't involve arguments or constants. It prints the instruction name and returns
 * the updated offset.
 *
 * @param name A string representing the name of the instruction.
 * @param offset The position in the chunk where the instruction is located.
 * @return int Returns the offset of the next instruction to be processed.
 */
static int simpleInstruction(const char* name, int offset);

/**
 * Disassembles and prints an instruction that refers to a constant in the constants array.
 * 
 * This function handles instructions like OP_CONSTANT, which reference a constant.
 * It retrieves the constant's index from the bytecode and prints the instruction name
 * along with the corresponding constant value.
 *
 * @param name A string representing the name of the instruction being disassembled.
 * @param chunk A pointer to the chunk containing the instruction and constants.
 * @param offset The position in the chunk where the instruction is located.
 * @return int Returns the offset of the next instruction to be processed.
 */
static int constantInstruction(const char* name, Chunk* chunk, int offset);

#endif