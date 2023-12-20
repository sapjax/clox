#ifndef __DEBUG__H__
#define __DEBUG__H__

#include "chunk.h"

void disassembleChunk(Chunk* chunk, const char* name);
int disassembleInstruction(Chunk* chunk, int offset);

#endif  //!__DEBUG__H__