#include "common.h"
#include "chunk.h"
#include "debug.h"


/**
 * The main entry point of the program.
 * 
 * Initializes a chunk of bytecode, writes a test instruction (OP_RETURN), 
 * disassembles the chunk to print its contents, and then frees the memory.
 *
 * @param argc The argument count from the command line (unused).
 * @param argv The argument vector from the command line (unused).
 * @return int Returns 0 upon successful execution.
 */
int main(int argc, const char* argv[]){
    Chunk chunk;
    initChunk(&chunk);
    writeChunk(&chunk, OP_RETURN);

    disassembleChunk(&chunk, "test chunk");
    freeChunk(&chunk);
    
    return 0;
}