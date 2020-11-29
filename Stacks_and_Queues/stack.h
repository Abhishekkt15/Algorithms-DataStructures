/* THIS IS A HEADER FILES THAT CONTAINS ALL THE STRUCTURES AND FUNCTION DECLARATION

     Author: ABHISHEK K T
     Reg no: 201051007
     Department: ME MACHINE LEARNING
*/


#ifndef INCLUDED_STACK_
#define INCLUDED_STACK_
#include<stdint.h>
#define MAX_DEPTH 32
#include<stddef.h>
#include<stdlib.h>

#define STACK_OK 1
#define STACK_FULL 2
#define STACK_EMPTY 3

typedef struct _stack_ Stack;
typedef struct _stackResult_ Stack_Result;

struct _stack_
{
	char data[MAX_DEPTH];
	int32_t top;
	int32_t size;

};

struct _stackResult_
{
	char data;
	int32_t status;
};

Stack stack_new(int32_t size);
Stack* stack_push(Stack *stk,char data,Stack_Result * res);
Stack* stack_pop(Stack *stk,Stack_Result *res);
Stack* stack_peek(Stack *stk,Stack_Result *res);

#endif
