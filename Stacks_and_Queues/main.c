/* THIS CODE IS IMPLEMENTING STACKS AND QUEUES OPERATIONS USING ASSERTION

    Author: ABHISHEK K T
    Reg no: 201051007
    Department: ME MACHINE LEARNING

*/

#include "stack.h"
#include "queue.h"
#include<stdint.h>
#include<assert.h>
#include<stddef.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>


int balancing_symbols(char c[10])
{

	Stack s = stack_new(5);
	Stack *stk = &s;

	Stack_Result res;
	//char c[10] = d;
	for(int i=0;i<strlen(c);i++)
	{
		//printf("%c",c[i]);
		if(c[i] == '[' || c[i] == '(' || c[i] == '{')
		{
			stk = stack_push(stk,c[i],&res);
			continue;
		}
		else if(c[i] == ']' && stk->data[stk->top]=='[')
		{
			stk = stack_pop(stk,&res);
			continue;
		}
		else if(c[i] == ')' && stk->data[stk->top]=='(')
		{
			stk = stack_pop(stk,&res);
			continue;
		}
		else if(c[i] == '}' && stk->data[stk->top]=='{')
		{
			stk = stack_pop(stk,&res);
			continue;
		}
		else
		{
			assert(stk->top==2 || stk->top == -1);
			return 0;//if first symbol is },)or] then it will come out of function.
		}

	}
	stk = stack_peek(stk,&res);
	assert(stk->top == -1);

	return 0;
}

int postfix(char p[20])
{
	Stack s = stack_new(5);
	Stack *stk = &s;

	Stack_Result res;
	for(int i=0;i<strlen(p);i++)
    {
        if(isdigit(p[i]))
        {
            stk=stack_push(stk,p[i],&res);
         }
        else
        {
           char a,b;
            int c=0;
            a = stk->data[stk->top];
            stk = stack_pop(stk,&res);
            b = stk->data[stk->top];
            stk = stack_pop(stk,&res);
            if(p[i]=='+')
            {
            c = a -'0' + b - '0';
            //printf("%d",c);
            }
            else if(p[i]=='-')
            {
                c = (b-'0') - (a-'0');
            }
            else if(p[i]=='*')
            {
                c = (b-'0') * (a-'0');
            }
            else if(p[i]=='/')
            {
                c = (b-'0')/(a-'0');
            }
            //char buffer[2];
            //char pf = c+'0';
           //printf("%c",buffer[1]);

            char pf = c+'0';
            stk = stack_push(stk,pf,&res);


            //assert(res.data == '11');
        }
    }

stk = stack_peek(stk,&res);
assert(res.data=='6');
//printf(stk->data[stk->top]);

}




void constant_memory()
{
Queue k= queue_new(10);
Queue *q=&k;
Queue_Result Qres;

q=queue_add(q,10,&Qres);
q=queue_add(q,20,&Qres);
q=queue_add(q,30,&Qres);
q=queue_add(q,40,&Qres);

assert(q->count==4);
int d2count=1;
int d3count=q->count;

while(d2count<=d3count)
{
int dcount=1;
while(dcount<q->count)
{
	q = queue_delete(q,&Qres);
	q = queue_add(q,Qres.data,&Qres);
	dcount++;
}
	q = queue_delete(q,&Qres);

d2count++;
}
assert(Qres.data==10);
}

void stackTOqueue()
{
	Stack stk = stack_new(10);
Stack *s=&stk;
Stack_Result Sres;

Queue k= queue_new(10);
Queue *q=&k;
Queue_Result Qres;

s = stack_push(s,93,&Sres);
s = stack_push(s,53,&Sres);
s = stack_push(s,73,&Sres);
s = stack_push(s,83,&Sres);

int element = 53;
int count = 0;
int i=0;
while(i<=s->top+1)
{
s = stack_peek(s,&Sres);
if(Sres.data==element)
{
	break;
}
else
{
	s = stack_pop(s,&Sres);
	q = queue_add(q,Sres.data,&Qres);
	count++;
}
i++;
}

int dcount=count;
int d1count=count;
while(count!=0)
{
	q= queue_delete(q,&Qres);
	s= stack_push(s,Qres.data,&Sres);
	count--;
}
s = stack_peek(s,&Sres);
assert(Sres.data==73);

while(dcount!=0)
{
	s=stack_pop(s,&Sres);
	q=queue_add(q,Sres.data,&Qres);
	dcount--;
}

s = stack_peek(s,&Sres);
assert(Sres.data==53);


while(d1count!=0)
{
	q= queue_delete(q,&Qres);
	s= stack_push(s,Qres.data,&Sres);
	d1count--;
}

s = stack_peek(s,&Sres);
assert(Sres.data==83);

}

/*Stack* addQueue(Stack *s1,int32_t element,Stack_Result Sres1)
{

	s1=stack_push(s1,element,&Sres1);
	return s1;
}
*/
Stack* deleteQueue(Stack *s1,Stack *s2,Stack_Result Sres1,Stack_Result Sres2)
{
	while(s1->top>-1)
	{
	s1 = stack_pop(s1,&Sres1);
	int32_t popelement = Sres1.data;
	s2 = stack_push(s2,popelement,&Sres2);
	}
	s2 = stack_pop(s2,&Sres2);
	return s2;
}


void queueUsingStacks()
{
	Stack stk1 = stack_new(10);
	Stack *s1=&stk1;
	Stack_Result Sres1;

	s1 = stack_push(s1,10,&Sres1); //it takes only one time to push the values
	s1 = stack_push(s1,20,&Sres1);
	s1 = stack_push(s1,50,&Sres1);

	Stack stk2 = stack_new(10);
	Stack *s2=&stk2;
	Stack_Result Sres2;


	s2 = deleteQueue(s1,s2,Sres1,Sres2);
	s1 = stack_peek(s1,&Sres1);
	assert(s1->top==-1);

	s2 = stack_peek(s2,&Sres2);
	assert(Sres2.data==20); //10 is deleted using queue.

}




int main()

{

//1.Check balancing of symbols ( like ‘{‘, ‘(‘, ‘[‘ ) and their order using stack.

	char c[10] = "}((]";
	char c1[20] = "[({})]";

  	balancing_symbols(c);
	balancing_symbols(c1);

//2.Evaluate postfix expression using stack.

    char p[20]="423+1*+3-";
    postfix(p);

/*3.Design a queue to which stores process details like process id, arrival time, execution time and priority.
	Determine the turn-around time and waiting time for each jobs for following scheduling algorithms.
        a.	First Come First Serve
        b.	Shortest Job First  */

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

/*4. Design a stack using a single queue as an instance variable,
and only constant additional local memory within the method bodies.*/

    constant_memory();

/*5.Suppose you have a stack S containing n elements and a queue Q that is initially empty.
Write function that use Q to scan S to see if it contains a certain element x, with the additional
constraint that your algorithm must return the elements back to S in their original order. You
may use S, Q and a constant number of other variables.*/
    
    stackTOqueue();

//6.Design a queue using two stacks as instance variables, such that all queue operations execute in amortized O(1) time.
    
    queueUsingStacks();


return 0;
}
