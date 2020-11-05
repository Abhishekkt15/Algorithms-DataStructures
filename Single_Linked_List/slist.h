#ifndef _INCLUDED_SLIST
#define _INCLUDED_SLIST
#include<stdint.h>


typedef struct _node_ Node;
typedef struct _slist_ Slist;


struct _node_{
int32_t data;
Node *next;
};


struct _slist_{
Node *head;
Node *tail;
uint32_t length;
};
