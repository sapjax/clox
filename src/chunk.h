#ifndef __CHUNK__H__
#define __CHUNK__H__

#include "common.h"
#include "value.h"

typedef enum { OP_RETURN, OP_CONSTANT } OpCode;

typedef struct {
  int count;
  int capacity;
  uint8_t* code;
  ValueArray constants;
  int* lines;

} Chunk;

void initChunk(Chunk* chunk);
void writeChunk(Chunk* chunk, uint8_t byte, int line);
int addConstant(Chunk* chunk, Value value);
void freeChunk(Chunk* chunk);

#endif  //!__CHUNK__H__