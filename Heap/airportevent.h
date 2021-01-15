#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED
#include <stdint.h>
#include "appconst.h"

typedef struct _event_ Event;

struct _event_{
  int32_t planeNumber;
  int32_t timeStamp;
  char eventStatus[7];
};

typedef struct _eventsheap_ eventsHeap;

struct _eventsheap_{
  uint32_t size;
  Event data[HEAP_MAX_SIZE];
};


eventsHeap eventsHeap_new(Event data[], uint32_t len);
eventsHeap* eventsHeap_insert(eventsHeap *eventsheap, Event key);
int8_t eventsHeap_test(eventsHeap *eventsheap);
Event event_smallest_timestamp(eventsHeap *eventsheap);
uint32_t eventsHeap_size(eventsHeap *eventsheap);

#endif // HEAP_H_INCLUDED

