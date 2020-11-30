/* THIS CODE IS IMPLEMENTING QUEUE OPERATIONS
    Author: ABHISHEK K T
    Reg no: 201051007
    Department: ME MACHINE LEARNING
    THIS IS AN ASSERT BASED CODE
*/


#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include<assert.h>

int main()
{
   Queue queue = queue_new(10);
   Queue *q = &queue;

   Queue_Result res;

   q = queue_add(q,10,&res);
   assert(q->count==1);
   assert(q->data[q->head-1] == 10);
    q = queue_add(q,20,&res);
     q = queue_add(q,30,&res);
    assert(q->data[q->head-1]==30);
    assert(q->data[q->tail]==10);

    q = queue_delete(q,&res);
    assert(res.data==10);
    assert(q->data[q->tail]==20);
    return 0;
}
