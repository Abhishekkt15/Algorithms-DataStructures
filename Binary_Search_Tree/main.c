#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
#include<assert.h>
#include "bst.h" 


int main() 
{
Tree bst = tree_new();
Tree *tree = &bst;

//1. Design a BST class with methods to add element, search element, number of elements and delete requested element

tree = add_node(tree,50);
tree = add_node(tree,20);
tree = add_node(tree,30);
tree = add_node(tree,60);
tree = add_node(tree,70);
tree = add_node(tree,35);
tree = add_node(tree,40);

assert(tree->count == 7);

assert(lookup(tree,50)==1);
assert(lookup(tree,90)==0);

tree = delete_node(tree,35);
assert(tree->count == 6);

tree = delete_node(tree,35);


//2. Add methods to in-order, pre-order, post-order and level-order traversals

printf("In-order: ");
tree_inorder(tree); //20 30 40 50 60 70
printf("\nPre-order: ");
tree_preorder(tree);
printf("\nPost-order: ");
tree_postorder(tree);
printf("\nlevel-order: ");
tree_levelorder(tree);
printf("\n");

//3. Add method to find the height of binary search tree

assert(tree_height(tree)==4);

//4. Add method to count the number of terminal nodes in BST

assert(terminal_nodes(tree)==2);
tree = add_node(tree,25);

assert(terminal_nodes(tree)==3);
tree = add_node(tree,55);

assert(terminal_nodes(tree)==4);
tree = add_node(tree,58);
assert(terminal_nodes(tree)==4);


//5. Add methods to find max and min element in BST

assert(find_min(tree)==20);
assert(find_max(tree)==70);

//6. Add method to display elements in ascending order

printf("\n");
printf("Ascending Order: ");
tree_ascending(tree);

//7. Add method to display elements in descending order

printf("\n");
printf("Descending Order: ");
tree_descending(tree); // 70 60 50 40 30 20

return 0 ;

}
