#include<stdlib.h>
#include<stddef.h>
#include<assert.h>
#include "slist.h"
#include<stdio.h>


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
    return new_node;
}


Slist* slist_add_head(Slist *list,int32_t element)
{
assert(list!=NULL);
Node *new_node=slist_new_node(element);
new_node->next=list->head;
list->head=new_node;
if(list->tail ==NULL)
    {
        list->tail=new_node;
    }
++list->length;
assert((list->length==1 && list->head==list->tail) || (list->length>0 && list->head!=list->tail));
return list;
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


Slist* slist_delete_head(Slist *list)
{
  Node* temp;
  if(list->head!=NULL){
        temp=list->head;
        list->head=list->head->next;
        if(list->head==NULL){
                list->tail=NULL;
        }
        --list->length;
  }free(temp);
  return list;
}


Slist* slist_display(Slist *list){
Node *temp;
int count=0;

    if(list->head == NULL)
    {
        printf("List is empty.");
        return list;
    }

    temp = list->head;
    while(temp != NULL)
    {
        count=count+1;
        printf("Data = %d\n", temp->data);
        temp = temp->next;

     }
     printf("length of list: %d\n",count);
 }


Slist* slist_add_tail(Slist *list,int32_t element)
{
        assert(list!=NULL);
        Node *new_node=slist_new_node(element);
        if(list->tail!=NULL){
                list->tail->next=new_node;
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
        if(list->tail!=NULL)
        {
            temp=list->tail;
            for(cur=list->head;cur->next!=temp;cur=cur->next);
            list->tail=cur;
            cur->next=NULL;
            --list->length;
        }
        return list;
}


int32_t slist_min(Slist *list) {
    Node *temp = list->head;
    int32_t min=temp->data;
    assert(list!=NULL);
    while (temp!=NULL) {
        if (temp -> data < min) {
            min = temp -> data;
        }
        temp = temp -> next;
    }
   return min;
}


int32_t slist_max(Slist *list) {
    Node *temp = list->head;
    int32_t max=0;
    assert(list!=NULL);
    while (temp!=NULL) {
        if (temp -> data > max) {
            max = temp -> data;
        }
        temp = temp -> next;
    }
    return max;
}


Slist* slist_spec_ele(Slist *list, int32_t element,int32_t spec_ele)
{
    assert(list!=NULL);
    Node *new_node=slist_new_node(element);
    Node *temp;
    for(temp=list->head;temp!=NULL;temp=temp->next)
    {
        if(temp->data==spec_ele)
        {
            new_node->next=temp->next;
            temp->next=new_node;
            if(temp->next==NULL)
            {
                assert(temp->next==NULL);
                list->tail=new_node;
            }
        }

    }
    ++list->length;
    return list;

}


Slist* slist_spec_ele_delete(Slist *list, int32_t spec_ele)
{
    assert(list != NULL);
    Node *temp,*prev;
    prev->next = NULL;
    temp=list->head;
    if(list->length == 1){
        list->head=NULL;
        list->tail=NULL;
        list->length = 0;
    }
    else if (temp != NULL && temp->data == spec_ele)
    {
        list->head= temp->next;
	--list->length;
        return list;
    }
    else{
    for(temp=list->head;temp!=NULL;temp=temp->next){


        if(temp->data == spec_ele)
        {
            prev->next=temp->next;
        }
        prev = temp;
    }
    free(temp);
--list->length;
   }

    return list;
}


Slist* reverse_list(Slist *list)
{
assert(list!=NULL);
Node *prev=NULL,*nxt=NULL,*temp,*temp1;
temp=list->head;
temp1= temp;
while(temp!=NULL)
{
    nxt = temp->next;
    temp->next = prev;
    prev = temp;
    temp = nxt;
}
list->tail = temp1;
list->head = prev;
return list;
}


uint32_t list_compare(Slist *list1,Slist *list2)
{
    assert(list1!=NULL);
    assert(list2!=NULL);
    Node *temp1,*temp2;
    temp1=list1->head;
    temp2=list2->head;
    while(temp1!=NULL && temp2!=NULL)
    {
        if(temp1->data == temp2->data)
        {
            return 1;
        }
        else{
            return 0;
        }

        temp1=temp1->next;
        temp2=temp2->next;
    }
    return (list1 == NULL && list2==NULL);
}


Slist* union_twolist(Slist *union_list,Slist *list1,Slist *list2)
{
    assert(list1!=NULL);
    assert(list2!=NULL);

    Node *temp1,*temp2;
    temp1=list1->head;
    temp2=list2->head;

    while(temp1!=NULL)
    {
	if(!(slist_lookup(union_list, temp1->data)))
        {
            union_list = slist_add_tail(union_list,temp1->data);
        }

        temp1=temp1->next;
    }
    while(temp2!=NULL)
    {
        if(!(slist_lookup(list1, temp2->data)))
        {
            union_list = slist_add_tail(union_list,temp2->data);
        }
        temp2=temp2->next;
    }
    return union_list;
}


Slist* intersection_twolist(Slist *intersection_list,Slist *list1,Slist *list2)
{
    assert(list1!=NULL);
    assert(list2!=NULL);

    Node *temp1,*temp2;
    temp1=list1->head;
    temp2=list2->head;
    while(temp1!=NULL)
    {
        if(slist_lookup(list2, temp1->data))
        {
            intersection_list = slist_add_tail(intersection_list,temp1->data);
        }
        temp1=temp1->next;
    }
return intersection_list;
}


Slist* unique_slist(Slist* list,uint32_t element)
{
 assert(list!=NULL);
    Node *temp;
    temp=list->head;


    while(temp!=NULL)
	{if(!(slist_lookup(list,element)))
        {
            list = slist_add_tail(list,element);
        }
temp= temp->next;
}


return list;
}
