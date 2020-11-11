  
/* THIS IS A HEADER FILES THAT CONTAINS ALL THE STRUCTURES AND FUNCTION DECLARATION
 
     Author: ABHISHEK K T
     Reg no: 201051007
     Department: ME MACHINE LEARNING
*/

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

Slist slist_new();
uint32_t slist_length(Slist *list);
uint32_t slist_lookup(Slist *list,int32_t key);
Slist* slist_add_head(Slist *list,int32_t element);
Slist* slist_add_tail(Slist *list,int32_t element);
Slist* slist_delete_head(Slist *list);
Slist* slist_delete_tail(Slist *list);
int32_t slist_min(Slist *list);
int32_t slist_max(Slist *list);
Slist* slist_spec_ele(Slist *list, int32_t element,int32_t spec_ele);
Slist* slist_spec_ele_delete(Slist *list, int32_t spec_ele);
uint32_t list_compare(Slist *list1,Slist *list2);
Slist* reverse_list(Slist *list);
Slist* union_twolist(Slist *union_list,Slist *list1,Slist *list2);
Slist* intersection_twolist(Slist *intersection_list,Slist *list1,Slist *list2);
Slist* unique_slist(Slist* list,uint32_t element);
Slist* slist_display(Slist *list);
#endif
