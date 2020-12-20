#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include "bst.h"
#define DATA_TYPE Node*
#include "queue.h"


Tree tree_new()
{
Tree root ={NULL,0};
return root;
}

static Node* make_new_node(int32_t element)
{
Node *new_node = (Node*) malloc(sizeof(Node));
new_node->data= element;
new_node->right=NULL;
new_node->left = NULL;
return new_node;
}

Tree* add_node(Tree *t,int32_t element)
{
assert(t!=NULL);
Node *cur,*parent;
cur=parent = t->root;
while(cur!=NULL && cur->data!=element)
{
parent = cur;
if(cur->data<element)
{
cur = cur->right; 
}
else if(cur->data>element)
{
cur=cur->left;
}
}

if(cur==NULL)
{
Node *new_node = make_new_node(element);
if(parent==NULL)
{
t->root = new_node;
}
else if(parent->data<element)
{
parent->right = new_node;
}
else if(parent->data>element)
{
parent->left = new_node;
}
t->count++;

}
return t;
}



static Node* find_minimum(Node *n)
{
if(n->left == NULL)
{
return n;
}
else
{
return find_minimum(n->left);
}
}

static Node* _delete_(Tree *t,Node *n ,int32_t element)
{
Node *temp;
if(n==NULL)
{
return n;
}
else if(element>n->data)
{
n->right= _delete_(t,n->right,element); // second iteration
}
else if(element<n->data)
{
n->left= _delete_(t,n->left,element);  // first iteration
}
else if(n->right && n->left)
{
temp = find_minimum(n->right);
n->data = temp->data;
n->right = _delete_(t,n->right,n->data);
}
else
{
temp=n;
if(n->right == NULL)
{
n = n->left; //to save null to parent of child having zero leaf
}
else
{
n = n -> right; //to save null to parent of child having zero leaf
}
free(temp);
t->count--;
}
return n;
}

Tree* delete_node(Tree *t,int32_t element)
{
	assert(t!=NULL);
	t->root = _delete_(t,t->root,element);
	return t;
}



int32_t lookup(Tree *t,int32_t element)
{
assert(t!=NULL);
Node *temp = t->root;
while(temp!=NULL && temp->data!=element)
{
if(temp->data>element)
{
temp = temp->left;
}
else if(temp->data<element)
{
temp=temp->right;
}
}
return (temp!=NULL);
}


uint32_t nodes_count(Tree *t)
{
assert(t!=NULL);
return t->count;
}

static void _inorder_(Node *n)
{
if(n)
{
_inorder_(n->left);
printf("%d\t",n->data);
_inorder_(n->right);
}
}

void tree_inorder(Tree *t)
{
	assert(t!=NULL);
	_inorder_(t->root);
}

static void _preorder_(Node *n)
{
if(n)
{
printf("%d\t",n->data);
_preorder_(n->left);
_preorder_(n->right);
}
}

void tree_preorder(Tree *t)
{
	assert(t!=NULL);
	_preorder_(t->root);
}

static void _postorder_(Node *n)
{
if(n)
{
_postorder_(n->left);
_postorder_(n->right);
printf("%d\t",n->data);
}
}

void tree_postorder(Tree *t)
{
	assert(t!=NULL);
	_postorder_(t->root);
	printf("\n");
}


void tree_levelorder(Tree *t)
{
	assert(t->root!=NULL);
	Node *temp;
	Queue Tree_queue = queue_new(t->count);
	Queue *queue = &Tree_queue;
	Queue_Result *res = (Queue_Result*) malloc(sizeof(Queue_Result));
	queue = queue_add(queue,t->root,res);
	while(queue->count!=0)
	{
		queue_delete(queue,res);
		temp = res->data;

		
		if(temp->left!=NULL)
		{
			queue_add(queue,temp->left,res);
		}
		if(temp->right!=NULL)
		{
			queue_add(queue,temp->right,res);
		}
		printf("%d \t",temp->data);
	}
	printf("\n");
}


static int32_t max_height(Node *n)
{
int32_t left_height=0;
int32_t right_height = 0;

if(n == NULL)
{
return 0;
}
else
{

if(n->left!=NULL){
left_height = max_height(n->left);
}
if(n->right!=NULL){
right_height = max_height(n->right);

}
if(left_height>right_height)
{
return left_height+1;
}
else
{
return right_height+1;
}
}
}


int32_t tree_height(Tree *t)
{
assert(t!=NULL);

int32_t max = max_height(t->root);
return max;
}


int32_t find_min(Tree *t)
{
assert(t!=NULL);
Node *temp=t->root;
while(temp->left!=NULL)
{
temp= temp->left;
}
return(temp->data);
}

int32_t find_max(Tree *t)
{
assert(t!=NULL);
Node *temp=t->root;
while(temp->right!=NULL)
{
temp = temp->right;
}
return(temp->data);
}

static void _ascending_(Node *n)
{
if(n)
{
_ascending_(n->left);
printf("%d\t",n->data);
_ascending_(n->right);
}
}

void tree_ascending(Tree *t)
{
	assert(t!=NULL);
	_ascending_(t->root);
}

static void _descending_(Node *n)
{
if(n)
{
_descending_(n->right);
printf("%d\t",n->data);
_descending_(n->left);
}
}

void tree_descending(Tree *t)
{
	assert(t!=NULL);
	_descending_(t->root);
}


static int32_t _terminals_(Node *n)
{
	int32_t count1 = 0;
	int32_t count2 = 0;

	if(n==NULL)
		{return 0;}
	if (n->left==NULL && n->right==NULL)
	{
		return 1;
	}
	else{
	if(n->left!=NULL)
	{
	count1 = _terminals_(n->left);
	}
	if(n->right!=NULL)
	{
	count2 = _terminals_(n->right);
	}


	return count1+count2;
}
}

int32_t terminal_nodes(Tree *t)
{
	assert(t!=NULL);
	int32_t count=0;
	count = _terminals_(t->root);
	return count;
}
