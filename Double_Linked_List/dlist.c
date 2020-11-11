#include<stdlib.h>
#include<stddef.h>
#include<assert.h>
#include "dlist.h"

Slist slist_new()
{
    Slist s={NULL,NULL,0};
    return s;
}



static Node* slist_new_node(int32_t element)
{
    Node *new_node=(Node *)malloc(sizeof(Node));
    new_node -> data=element;
    new_node->next=NULL;
    new_node->prev=NULL;
    return new_node;
}


uint32_t slist_length(Slist *list)
{
        assert(list!=NULL);
        return list->length;
}


uint32_t slist_lookup(Slist *list,int32_t key)
{
        assert(list!=NULL);
        Node *cur;
        for(cur=list->head;cur!=NULL;cur=cur->next)
        { if(cur->data==key){
          break;

         }
        }
        return (cur!=NULL);
}


Slist* slist_add_tail(Slist *list,int32_t element)
{
        assert(list!=NULL);
        Node *new_node=slist_new_node(element);
        if(list->tail!=NULL){
                list->tail->next=new_node;
                //list->tail->prev=new_node;
		new_node->prev=list->tail;
		list->tail=new_node;
        }
        else{
                list->tail=list->head=new_node;
        }
        ++list->length;
        return list;
}


Slist* slist_delete_tail(Slist *list)
{
        assert(list!=NULL);
        Node *cur,*temp;
	temp=list->tail;
        if(list->tail!=NULL)
        {
            list->tail=cur;
            cur = list->tail->prev;
	    cur->next=NULL;

	    --list->length;
        }
        return list;
}

Slist* slist_add_head(Slist *list,int32_t element)
{
	assert(list!=NULL);
	Node *temp;
	temp= list->head;
    if(list->length == 0){
        Node *new_node = slist_new_node(element);
        list->head = new_node;
        list->tail = new_node;
        list->length = 1;
    }
    else{
	Node *new_node = slist_new_node(element);
	temp->prev = new_node;
	new_node->next = temp;
	++list->length;
	list->head = new_node;
}
	return list;
}


Slist* slist_delete_head(Slist *list)
{
	assert(list!=NULL);
    Node *temp;
    temp = list->head->next;
    if(list->length==1)
    {
        list->head= NULL;
        list->tail= NULL;
        list->length =0;
    }
	else{
    list->head = temp;
    --list->length;
}
    return list;

}
