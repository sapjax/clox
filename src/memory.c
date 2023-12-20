
#include "memory.h"
#include <stdlib.h>

/*
        oldSize          newSize               Operation
        0                Non-zero              Allocate new block.
        Non-zero         0                     Free allocation.
        Non-zero         Smaller than oldSize  Shrink existing allocation.
        Non-zero         Larger than oldSize   Grow existing allocation.
*/

void* rellocate(void* pointer, size_t oldSize, size_t newSize) {
  if (newSize == 0) {
    free(pointer);
    return NULL;
  }

  void* result = realloc(pointer, newSize);
  if (result == NULL)
    exit(1);
  return result;
}