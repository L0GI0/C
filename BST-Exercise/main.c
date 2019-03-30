#include <stdio.h>
#include <stdlib.h>
#include "BST.h"

int main(void){

	int i;
	tleaf *root = NULL;
	int values[] = {5, 12, 43, 55, 98, 54, 23, 74, 19};
	for (i = 0; i < sizeof(values)/sizeof(int); i++)
		add_leaf(&root, root, values[i]);
	in_order(root);
	putchar('\n');
	printf("Tree min value: %d \n", tree_min(root)->value);
	printf("Tree max value: %d \n", tree_max(root)->value);


	tleaf *found = tree_search_iteration(root, 43);
	if(found)
		printf("%d \n", found->value);
	found = tree_search_iteration(root, 14);
	found = tree_search_recursion(root, 98);
	if(found)
		printf("%d \n", found->value);
	found = tree_search_recursion(root, 15);
	found = predecessor(tree_search_recursion(root, 5));
	if (found)
		printf("Predecessor of node with value 23 is node with value %d \n", found->value);
	found = successor(tree_search_iteration(root, 98));
	if(found)
		printf("Successor of node with value 5 is node with value %d \n", found->value);
	return 0;
}
