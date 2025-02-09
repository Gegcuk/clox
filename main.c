#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h" // Include common utilities and definitions for portability and standard functionality.
#include "chunk.h"  // Include the definitions and functions for managing chunks of bytecode.
#include "debug.h"  // Include the debugging utilities for disassembling and analyzing bytecode.
#include "vm.h"

static void repl(){
    char line[1024];
    for(;;){
        printf("> ");
        if (!fgets(line, sizeof(line), stdin)){
            printf("\n");
            break;
        }

        interpret(line);
    }
}

static char* readFile(const char* path){
    FILE* file = fopen(path, "rb");

    fseek(file, 0L, SEEK_END);
    size_t fileSize = ftell(file);
    rewind(file);

    char* buffer = (char*)malloc(fileSize + 1);
    size_t bytesRead = fread(buffer, sizeof(char), fileSize, file);
    buffer[bytesRead] = '\0';

    fclose(file);
    return buffer;
}

static void runFile(const char* path){
    char* source = readFile(path);
    InterpretResult result = interpret(source);
    free(source);

    if (result == INTERPRET_COMPILE_ERROR) exit(65);
    if (result == INTERPRET_RUNTIME_ERROR) exit(70);
}

int main(int argc, const char* argv[]) {
    // Entry point of the program. Takes command-line arguments but does not use them in this example.

    initVM();

    if (argc == 1){
        repl();
    } else if (argc == 2){
        runFile(argv[1]);
    } else {
        fprintf(stderr, "Usage: clox[path]\n");
        exit(64);
    }
    freeVM();
    return 0; // Indicate that the program executed successfully.
}