#ifndef _INCLUDED_BST_
#define _INCLUDED_BST_
#include<stdint.h>

#include<assert.h>

typedef struct _tree_ Tree;
typedef struct _node_ Node;

struct _tree_
{
Node *root;
int32_t count;
};

struct _node_
{
int32_t data;
Node *left;
Node *right;
};

Tree tree_new();
Tree* add_node(Tree *t,int32_t element);
Tree* delete_node(Tree *t,int32_t element);
int32_t lookup(Tree *t,int32_t element);
uint32_t nodes_count(Tree *t);
void tree_inorder(Tree *t);
void tree_preorder(Tree *t);
void tree_postorder(Tree *t);
void tree_levelorder(Tree *t);
int32_t tree_height(Tree *t);
int32_t find_min(Tree *t);
int32_t find_max(Tree *t);
void tree_ascending(Tree *t);
void tree_descending(Tree *t);
int32_t terminal_nodes(Tree *t);


#endif
