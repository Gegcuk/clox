#ifndef clox_chunk_c
#define clox_chunk_c

#include "common.h"
typedef enum{
    OP_RETURN,
} OpCode;

typedef struct {
    int count;
    int capacity;
    uint8_t* code;
} Chunk;

#endif