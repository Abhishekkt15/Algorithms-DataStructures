#include <stdint.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "airportevent.h"

static void _swap_(Event *num1, Event *num2){
  Event temp;
  temp = *num1;
  *num1 = *num2;
  *num2 = temp;
}


static void _heapify_(Event data[], uint32_t len, uint32_t parent) {
   assert(len > 0 && len < HEAP_MAX_SIZE && parent > 0);

   uint32_t child = 2 * parent;

   while (child <= len) {
      if(child + 1 <= len){
           if(data[child + 1].timeStamp < data[child].timeStamp){
              ++child;
        }
      }
      if(data[parent].timeStamp <= data[child].timeStamp){
           break;
      }
      _swap_(&data[parent], &data[child]);
      parent = child;
      child = 2 * parent;

  }
}

static void _test_heap_(Event data[], uint32_t len){
       for(uint32_t child = len; child > 1; --child){
         assert(data[child].timeStamp >= data[child/2].timeStamp);
   }
}


eventsHeap eventsHeap_new(Event data[], uint32_t len) {
   assert(len > 0 && len < HEAP_MAX_SIZE);

   eventsHeap eventsheap;

   for (uint32_t idx = len / 2; idx > 0; --idx){
      _heapify_(data, len, idx);
   }
   eventsheap.size = len;
   memcpy(eventsheap.data, data, (len+1) * sizeof(Event));
   _test_heap_(eventsheap.data, eventsheap.size);

   return eventsheap;
}


uint32_t eventsHeap_size(eventsHeap *eventsheap){
   assert(eventsheap != NULL);

   return eventsheap->size;
}



eventsHeap* eventsHeap_insert(eventsHeap *eventsheap, Event key) {
          assert (eventsheap->size > 0 && eventsheap->size+1 < HEAP_MAX_SIZE);
          ++eventsheap->size;
          uint32_t parent = eventsheap->size/2;
          uint32_t loc = eventsheap->size;
          while ( loc > 1 && eventsheap->data[parent].timeStamp > key.timeStamp) {
                   eventsheap->data[loc] = eventsheap->data[parent];
                   loc = parent;
                   parent = parent/2;
           }
           eventsheap->data[loc] = key;
           return eventsheap;
}

int8_t eventsHeap_test(eventsHeap *eventsheap){
   assert(eventsheap != NULL && eventsheap->size > 0);

   for(uint32_t child = eventsheap->size; child > 1; --child){
         if(eventsheap->data[child].timeStamp < eventsheap->data[child/2].timeStamp){
           return 0;
         }
   }

   return 1;
}


Event event_smallest_timestamp(eventsHeap *eventsheap){
   assert(eventsheap != NULL && eventsheap->size > 0);

   Event min;
   min = eventsheap->data[1];

   _swap_(&eventsheap->data[eventsheap->size], &eventsheap->data[1]);
   eventsheap->data[eventsheap->size].planeNumber = 0;
   eventsheap->data[eventsheap->size].timeStamp = 0;
   strcpy(eventsheap->data[eventsheap->size].eventStatus, "");
   --eventsheap->size;

   for (uint32_t idx = (eventsheap->size -1) / 2; idx > 0; --idx){
      _heapify_(eventsheap->data, eventsheap->size, idx);
   }

   return min;
}
