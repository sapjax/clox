#ifndef __MEMORY__H__
#define __MEMORY__H__

#include "common.h"

#define GROW_CAPACITY(capacity) ((capacity) < 8 ? 8 : (capacity) * 2)

#define GROW_ARRAY(type, pointer, oldCount, newCount) \
  (type*)rellocate(                                   \
      pointer, sizeof(type) * (oldCount), sizeof(type) * (newCount))

#define FREE_ARRAY(type, pointer, oldCount) \
  rellocate(pointer, sizeof(type) * (oldCount), 0)

void* rellocate(void* pointer, size_t oldSize, size_t newSize);

#endif  //!__MEMORY__H__