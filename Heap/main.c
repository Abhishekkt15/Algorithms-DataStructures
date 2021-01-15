#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <assert.h>
#include "heap.h"
#include "string.h"
#include "priorityqueue_heap.h"
#include "airportevent.h"

/* 1. Build maximum heap with required methods. It should support the behaviors like adding element,
      getting maximum element, extracting maximum element, count number of elements and to check the
      method to test the heap order property.*/
// Create new Heap and count the number of elements in it
void test_newheap(){
   int32_t data[] = {0, 10, 19, 39, 40, 90, 70, 64, 26, 5, 80};
   Heap h1 = heap_new(data, 10);
   Heap *heap = &h1;

   assert(heap_size(heap) == 10);
}

// Insert the new element to the Heap
void test_insert(){
   int32_t data[] = {0, 10, 19, 39, 40, 90, 70, 64, 26, 5, 80};
   Heap h1 = heap_new(data, 10);
   Heap *heap = &h1;

   assert(heap_size(heap) == 10);


   heap = heap_insert(heap, 50);
   assert(heap_test(heap) == 1);


   heap = heap_insert(heap, 100);
   assert(heap_test(heap) == 1);

}

// Test the Max Heap property
void test_heap_test(){
   int32_t data[] = {0, 10, 19, 39, 40, 90, 70, 64, 26, 5, 80};
   Heap h1 = heap_new(data, 10);
   Heap *heap = &h1;

   assert(heap_size(heap) == 10);
   assert(heap_test(heap) == 1);
}

// Get the max element from the Heap
void test_get_max(){
   int32_t data[] = {0, 10, 19, 39, 40, 90, 70, 64, 26, 5, 80};
   Heap h1 = heap_new(data, 10);
   Heap *heap = &h1;

   assert(heap_size(heap) == 10);

   assert(heap_get_max(heap) == 90);

}

// Extract the max element from the Heap
void test_heap_extract_max(){
   int32_t data[] = {0, 10, 19, 39, 40, 90, 70, 64, 26, 5, 80};
   Heap h1 = heap_new(data, 10);
   Heap *heap = &h1;

   assert(heap_size(heap) == 10);

   assert(heap_extract_max(heap) == 90);

}

/* 2. Modify Q2 to sort the input in ascending order. */
void test_sort(){
   int32_t data[] = {0, 10, 19, 39, 40, 90, 70, 64, 26, 5, 80};
   Heap h1 = heap_new(data, 10);
   Heap *heap = &h1;

   assert(heap_size(heap) == 10);

   heap = heap_sort(heap);
   assert(heap->data[1] == 5);
   assert(heap->data[10] == 90);

}

/* 3. Build priority queue to handle real time tasks. Tasks can arrive at time.
      The attributes of tasks are task-id, priority, arrival time, execution time and deadline.
      Compute waiting time, turnaround time for each job. Check whether jobs are completed within
      the deadline specified.  It is treated that 10 is maximum priority and 1 is least priority.
*/

void test_tasksHeap() {
   Task data[6];
   Task task;

   data[0].task_id = 0;
   data[0].priority = 0;
   data[0].arrival_time = 0;
   data[0].execution_time = 0;
   data[0].deadline = 0;
   data[0].waiting_time = 0;
   data[0].turnaround_time = 0;

   data[1].task_id = 101;
   data[1].priority = 3;
   data[1].arrival_time = 0;
   data[1].execution_time = 11;
   data[1].deadline = 37;
   data[1].waiting_time = 0;
   data[1].turnaround_time = 0;

   data[2].task_id = 102;
   data[2].priority = 1;
   data[2].arrival_time = 5;
   data[2].execution_time = 28;
   data[2].deadline = 75;
   data[2].waiting_time = 0;
   data[2].turnaround_time = 0;

   data[3].task_id = 103;
   data[3].priority = 4;
   data[3].arrival_time = 12;
   data[3].execution_time = 2;
   data[3].deadline = 29;
   data[3].waiting_time = 0;
   data[3].turnaround_time = 0;

   data[4].task_id = 104;
   data[4].priority = 2;
   data[4].arrival_time = 2;
   data[4].execution_time = 10;
   data[4].deadline = 50;
   data[4].waiting_time = 0;
   data[4].turnaround_time = 0;

   data[5].task_id = 105;
   data[5].priority = 5;
   data[5].arrival_time = 9;
   data[5].execution_time = 16;
   data[5].deadline = 24;
   data[5].waiting_time = 0;
   data[5].turnaround_time = 0;


   TasksHeap h1 = tasksHeap_new(data, 5);
   TasksHeap *tasksheap = &h1;

   assert(tasksHeap_size(tasksheap) == 5);

// Checking waiting time, turnaround time for each job and jobs are completed within the deadline specified
   task = task_high_priority(tasksheap);
   assert(task.turnaround_time == 16);
   assert(task.waiting_time == 0);
   assert(taskCompletedWithinDeadline(tasksheap, task) == 1);

   task = task_high_priority(tasksheap);
   assert(task.turnaround_time == 15);
   assert(task.waiting_time == 13);
   assert(taskCompletedWithinDeadline(tasksheap, task) == 0);

   task = task_high_priority(tasksheap);
   assert(task.turnaround_time == 38);
   assert(task.waiting_time == 27);
   assert(taskCompletedWithinDeadline(tasksheap, task) == 1);
// Checking waiting time, turnaround time for each job and jobs are completed within the deadline specified

// New Task insert
   task.task_id = 106;
   task.priority = 6;
   task.arrival_time = 4;
   task.execution_time = 10;
   task.deadline = 20;
   task.waiting_time = 0;
   task.turnaround_time = 0;
   tasksheap = tasksHeap_insert(tasksheap, task);
   assert(tasksHeap_size(tasksheap) == 3);

   task.task_id = 107;
   task.priority = 4;
   task.arrival_time = 8;
   task.execution_time = 4;
   task.deadline = 30;
   task.waiting_time = 0;
   task.turnaround_time = 0;
   tasksheap = tasksHeap_insert(tasksheap, task);
   assert(tasksHeap_size(tasksheap) == 4);
// New Task insert

}


/* 4. An airport is developing a computer simulation of air-traffic control that handles events
      such as landings and takeoffs. Each event has a time stamp that denotes the time when the
      event will occur with additional information like, plane number, takeoff or landing. The simulation
      program needs to efficiently perform the following two fundamental operations:
      1. Insert an event with a given time stamp, aircraft number, takeoff / landing (add a future event).
      2. Extract the event with smallest time stamp (that is, determine the next event to process).
         Design and implement suitable data structures that work efficiently in terms of time.
*/


void test_neweventsHeap(){
   Event data[5];

   data[0].planeNumber = 0;
   data[0].timeStamp = 0;
   strcpy(data[0].eventStatus, "");

   data[1].planeNumber = 1;
   data[1].timeStamp = 200;
   strcpy(data[1].eventStatus, "landing");

   data[2].planeNumber = 2;
   data[2].timeStamp = 500;
   strcpy(data[2].eventStatus, "takeoff");

   data[3].planeNumber = 3;
   data[3].timeStamp = 100;
   strcpy(data[3].eventStatus, "takeoff");

   data[4].planeNumber = 4;
   data[4].timeStamp = 150;
   strcpy(data[4].eventStatus, "landing");

   eventsHeap h1 = eventsHeap_new(data, 4);
   eventsHeap *eventsheap = &h1;

   assert(eventsHeap_size(eventsheap) == 4);

}

// 1. Insert an event with a given time stamp, aircraft number, takeoff / landing (add a future event).
void test_eventsHeap_insert(){
   Event data[5];
   Event key;

   data[0].planeNumber = 0;
   data[0].timeStamp = 0;
   strcpy(data[0].eventStatus, "");

   data[1].planeNumber = 1;
   data[1].timeStamp = 200;
   strcpy(data[1].eventStatus, "landing");

   data[2].planeNumber = 2;
   data[2].timeStamp = 500;
   strcpy(data[2].eventStatus, "takeoff");

   data[3].planeNumber = 3;
   data[3].timeStamp = 100;
   strcpy(data[3].eventStatus, "takeoff");

   data[4].planeNumber = 4;
   data[4].timeStamp = 150;
   strcpy(data[4].eventStatus, "landing");

   eventsHeap h1 = eventsHeap_new(data, 4);
   eventsHeap *eventsheap = &h1;

   assert(eventsHeap_size(eventsheap) == 4);

   key.planeNumber = 5;
   key.timeStamp = 20;
   strcpy(key.eventStatus, "takeoff");

   eventsheap = eventsHeap_insert(eventsheap, key);
   assert(eventsHeap_test(eventsheap) == 1);

   key.planeNumber = 6;
   key.timeStamp = 50;
   strcpy(key.eventStatus, "takeoff");

   eventsheap = eventsHeap_insert(eventsheap, key);
   assert(eventsHeap_test(eventsheap) == 1);
}

void test_eventsHeap_test(){
   Event data[5];

   data[0].planeNumber = 0;
   data[0].timeStamp = 0;
   strcpy(data[0].eventStatus, "");

   data[1].planeNumber = 1;
   data[1].timeStamp = 200;
   strcpy(data[1].eventStatus, "landing");

   data[2].planeNumber = 2;
   data[2].timeStamp = 500;
   strcpy(data[2].eventStatus, "takeoff");

   data[3].planeNumber = 3;
   data[3].timeStamp = 100;
   strcpy(data[3].eventStatus, "takeoff");

   data[4].planeNumber = 4;
   data[4].timeStamp = 150;
   strcpy(data[4].eventStatus, "landing");

   eventsHeap h1 = eventsHeap_new(data, 4);
   eventsHeap *eventsheap = &h1;

   assert(eventsHeap_size(eventsheap) == 4);
   assert(eventsHeap_test(eventsheap) == 1);
}

// 2. Extract the event with smallest time stamp (that is, determine the next event to process).
void test_event_smallest_timestamp(){
   Event data[5];
   Event event;

   data[0].planeNumber = 0;
   data[0].timeStamp = 0;
   strcpy(data[0].eventStatus, "");

   data[1].planeNumber = 1;
   data[1].timeStamp = 200;
   strcpy(data[1].eventStatus, "landing");

   data[2].planeNumber = 2;
   data[2].timeStamp = 500;
   strcpy(data[2].eventStatus, "takeoff");

   data[3].planeNumber = 3;
   data[3].timeStamp = 100;
   strcpy(data[3].eventStatus, "takeoff");

   data[4].planeNumber = 4;
   data[4].timeStamp = 150;
   strcpy(data[4].eventStatus, "landing");

   eventsHeap h1 = eventsHeap_new(data, 4);
   eventsHeap *eventsheap = &h1;

   assert(eventsHeap_size(eventsheap) == 4);

   event = event_smallest_timestamp(eventsheap);
   assert(event.timeStamp == 100 && event.planeNumber == 3);
}


int main(){

   test_newheap();
   test_sort();
   test_insert();
   test_heap_test();
   test_get_max();
   test_heap_extract_max();
   test_tasksHeap();
   test_neweventsHeap();
   test_eventsHeap_insert();
   test_eventsHeap_test();
   test_event_smallest_timestamp();

   return 0;
}
