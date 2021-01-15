#include <stdint.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "priorityqueue_heap.h"

static void _swap_(Task *num1, Task *num2){
  Task temp;
  temp = *num1;
  *num1 = *num2;
  *num2 = temp;
}


static void _heapify_(Task data[], uint32_t len, uint32_t parent) {
   assert(len > 0 && len < HEAP_MAX_SIZE && parent > 0);

   uint32_t child = 2 * parent;

   while (child <= len) {
      if(child + 1 <= len){
           if(data[child + 1].priority > data[child].priority){
              ++child;
        }
      }
      if(data[parent].priority >= data[child].priority){
           break;
      }
      _swap_(&data[parent], &data[child]);
      parent = child;
      child = 2 * parent;

  }
}

static void _test_heap_(Task data[], uint32_t len){
       for(uint32_t child = len; child > 1; --child){
         assert(data[child].priority <= data[child/2].priority);
   }
}


TasksHeap tasksHeap_new(Task data[], uint32_t len) {
   assert(len > 0 && len < HEAP_MAX_SIZE);

   TasksHeap tasksheap;

   for (uint32_t idx = len / 2; idx > 0; --idx){
      _heapify_(data, len, idx);
   }
   tasksheap.size = len;
   tasksheap.completion_time = 0;
   memcpy(tasksheap.data, data, (len+1) * sizeof(Task));
   _test_heap_(tasksheap.data, tasksheap.size);

   return tasksheap;
}


uint32_t tasksHeap_size(TasksHeap *tasksheap){
   assert(tasksheap != NULL);

   return tasksheap->size;
}



TasksHeap* tasksHeap_insert(TasksHeap *tasksheap, Task key) {
          assert (tasksheap->size > 0 && tasksheap->size+1 < HEAP_MAX_SIZE);
          ++tasksheap->size;
          uint32_t parent = tasksheap->size/2;
          uint32_t loc = tasksheap->size;
          while ( loc > 1 && tasksheap->data[parent].priority < key.priority) {
                   tasksheap->data[loc] = tasksheap->data[parent];
                   loc = parent;
                   parent = parent/2;
           }
           tasksheap->data[loc] = key;
           return tasksheap;
}


Task task_high_priority(TasksHeap *tasksheap) {
   assert(tasksheap != NULL && tasksheap->size > 0);

   Task maxPriorityTask;
   maxPriorityTask = tasksheap->data[1];

   if ((tasksheap->completion_time == 0) && (maxPriorityTask.arrival_time >= 1)) {
      tasksheap->completion_time += maxPriorityTask.execution_time + maxPriorityTask.arrival_time;
      maxPriorityTask.turnaround_time = tasksheap->completion_time - maxPriorityTask.arrival_time;
   } else {
      tasksheap->completion_time += maxPriorityTask.execution_time;
      maxPriorityTask.turnaround_time = tasksheap->completion_time - maxPriorityTask.arrival_time;
      maxPriorityTask.waiting_time = maxPriorityTask.turnaround_time - maxPriorityTask.execution_time;

   }

   _swap_(&tasksheap->data[tasksheap->size], &tasksheap->data[1]);
   tasksheap->data[tasksheap->size].task_id = 0;
   tasksheap->data[tasksheap->size].priority = 0;
   tasksheap->data[tasksheap->size].arrival_time = 0;
   tasksheap->data[tasksheap->size].execution_time = 0;
   tasksheap->data[tasksheap->size].deadline = 0;
   tasksheap->data[tasksheap->size].waiting_time = 0;
   tasksheap->data[tasksheap->size].turnaround_time = 0;

   --tasksheap->size;

   for (uint32_t idx = (tasksheap->size -1) / 2; idx > 0; --idx){
      _heapify_(tasksheap->data, tasksheap->size, idx);
   }

   return maxPriorityTask;
}

uint32_t taskCompletedWithinDeadline(TasksHeap *tasksheap, Task task) {
   assert(tasksheap != NULL);

   if (task.deadline <= tasksheap->completion_time) {
      return 1;
   }

   return 0;
}
