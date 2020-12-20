#include<stddef.h>
#include<stdlib.h>
#include<stdint.h>
#include<stdio.h>
#include<assert.h>
#include "queue.h"
Queue queue_new(uint32_t size)
{
    size = (size>0 && size<MAX_DEPTH)?size:MAX_DEPTH;
    Queue q = {size,0,0,0,{}}; 
    return q;
}

uint32_t queue_full(Queue *q)
{
    assert(q!=NULL);
    return (q->count == q->size);
}

uint32_t queue_empty(Queue *q)
{
    assert(q!=NULL);
    return (q->count ==0);
}

Queue* queue_add(Queue *q,DATA_TYPE element,Queue_Result *res)
{
    assert(q!=NULL);
    if(q->count < q->size)
    {


        q->data[q->head]= element;
        q->head = (q->head+1)% q->size;
        ++q->count;
        res->status = QUEUE_OK;
    }
    else{
        res->status = QUEUE_FULL;
    }
    assert(res->status == QUEUE_OK || q->count == q->size);
    return q;
}

Queue* queue_delete(Queue *q,Queue_Result *res)
{
    assert(q!=NULL);
    if(q->count>0)
    {
        res->data = q->data[q->tail];

        q->tail= (q->tail+1)%q->size;
        --q->count;
        res->status = QUEUE_OK;

    }
    else{
        res->status = QUEUE_EMPTY;
    }
    assert(res->status == QUEUE_OK || q->count ==0);
    return q;
}
