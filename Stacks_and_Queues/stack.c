/*  THIS FILE CONTAINS ALL THE FUNCTION DEFINATIONS

    Author: ABHISHEK K T
    Reg no: 201051007
    Department: ME Machine Learning
*/


#include<stdint.h>
#include "stack.h"
#include<assert.h>
#include<stddef.h>
#include<stdlib.h>


Stack stack_new(int32_t size)
{
	size = (size>0 && size<MAX_DEPTH)?size:MAX_DEPTH;
    Stack stk = {" ",-1,size};
    return stk;
}

int32_t stack_full(const Stack *stk)
{
	assert(stk!=NULL);
	return(stk->top+1 == stk->size);
}

int32_t stack_empty(const Stack *stk)
{
	assert(stk!=NULL);
	return(stk->top==-1);
}

Stack* stack_push(Stack *stk,char element,Stack_Result * res)
{
	assert(stk!=NULL);
	if(stk->top+1<stk->size)
	{
		//stk->top++;
		stk->data[++stk->top]=element;

		res->data=element;
		res->status = STACK_OK;
	}
	else{
		res->status = STACK_FULL;
	}
	assert(res->status == STACK_OK || stk->top+1 == stk->size);
	return stk;
}

Stack* stack_pop(Stack *stk,Stack_Result *res)
{
	assert(stk!=NULL);
	if(stk->top>-1)
	{
		res->data= stk->data[stk->top];
		res->status = STACK_OK;
		--stk->top;
	}
	else
	{
		res->status = STACK_EMPTY;
	}
	assert(res->status == STACK_OK || stk->top==-1);
	return stk;
}

Stack* stack_peek(Stack* stk, Stack_Result *res)
{
	assert(stk!= NULL);
	if(stk->size>-1)
	{
	res->data = stk->data[stk->top];
	res->status = STACK_OK;
}
else
{
	res->status= STACK_EMPTY;
}
	return stk;

}
