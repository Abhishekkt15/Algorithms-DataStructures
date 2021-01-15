#ifndef PRIORITYQUEUEHEAP_H_INCLUDED
#define PRIORITYQUEUEHEAP_H_INCLUDED

#include <stdint.h>
#include "appconst.h"

typedef struct _task_ Task;

struct _task_{
  int32_t task_id;
  uint8_t priority;
  uint16_t arrival_time;
  uint16_t execution_time;
  uint16_t deadline;
  uint16_t waiting_time;
  uint16_t turnaround_time;
};

typedef struct _tasksheap_ TasksHeap;

struct _tasksheap_{
  uint32_t size;
  Task data[HEAP_MAX_SIZE];
  uint32_t completion_time;
};


TasksHeap tasksHeap_new(Task data[], uint32_t len);
TasksHeap* tasksHeap_insert(TasksHeap *tasksheap, Task key);

Task task_high_priority(TasksHeap *tasksheap);
uint32_t tasksHeap_size(TasksHeap *tasksheap);
uint32_t taskCompletedWithinDeadline(TasksHeap *tasksheap, Task task);

#endif // PRIORITYQUEUEHEAP_H_INCLUDED

