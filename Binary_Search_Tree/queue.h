#ifndef INCLUDED_QUEUE_
#define INCLUDED_QUEUE_
#include<stdint.h>

#ifndef DATA_TYPE
#define DATA_TYPE void*
#endif 

#define MAX_DEPTH 32
#include<stddef.h>
#include<stdlib.h>

#define QUEUE_OK 1
#define QUEUE_FULL 2
#define QUEUE_EMPTY 3

typedef struct _queue_ Queue;
typedef struct _queueResult_ Queue_Result;

struct _queue_
{
	int32_t size;
	int32_t count;
	int32_t head;
	int32_t tail;
	DATA_TYPE data[MAX_DEPTH];
};

struct _queueResult_
{
    DATA_TYPE data;
    int32_t status;
};

Queue queue_new(uint32_t size);
uint32_t queue_full(Queue *q);
uint32_t queue_empty(Queue *q);

Queue* queue_add(Queue *q, DATA_TYPE element, Queue_Result *res);
Queue* queue_delete(Queue *q,Queue_Result *res);

#endif
