#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED

#include <stdint.h>
#include "appconst.h"

typedef struct _heap_ Heap;

struct _heap_{
  uint32_t size;
  int32_t data[HEAP_MAX_SIZE];
};


Heap heap_new(int32_t data[], uint32_t len);
Heap* heap_sort(Heap *heap);
Heap* heap_insert(Heap *heap, int32_t key);
int8_t heap_test(Heap *heap);
int32_t heap_get_max(Heap *heap);
int32_t heap_extract_max(Heap *heap);
uint32_t heap_size(Heap *heap);

#endif // HEAP_H_INCLUDED

