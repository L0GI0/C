#include <stdio.h>
#include <stdlib.h>
#include "drzewoBST.h"

int main(void){
	printf("Make file test\n");
 	int i;
 	tnode *root = createLeaf(11,NULL);
	int tab[]={15,5,16,20,3,12,18,23,10,13,6,7};
	for ( i = 0; i < sizeof(tab)/sizeof(tab[0]); i++)
		addLeaf(tab[i],&root,root);
	inOrder(root);

	tnode *min = treeMinRecursion(root);
	tnode *max = treeMaxRecursion(root);
	printf("Min: %d \n", min->value);
	printf("Max: %d\n", max->value);
	min = treeMinIteration(root);
 	max = treeMaxIteration(root);
	printf("Min: %d \n", min->value);
	printf("Max: %d\n", max->value);
	tnode *node;
	puts("Parents of every node");
	for (i = 0; i < sizeof(tab)/sizeof(tab[i]); i++){
		node = treeSearchRecursion(tab[i],root);
		printf("Parents of: %d\n", node->value);
		while(node->parent){
		printf("%d\n", node->parent->value);
		node = node->parent;
	}
	}
	puts("Parent of root");
	if(root->parent == NULL)
	printf("is NULL");
	if ((treeSearchIteration(23, root)->left))
	printf("Left of node 23 %d", (treeSearchIteration(23, root)->left->value));
		


	/*
	puts("Iteration search: ");
	tnode *search = treeSearchIteration(11, root);
	
	if(search)
	printf("Wanted node: %d\n",search->value);
	
	search = treeSearchIteration(5, root);
	if(search)
	printf("Wanted node: %d\n",search->value);
	putchar('\n');	
	puts("Recursion search: ");

	search = treeSearchRecursion(14, root);
	if(search)
	printf("Wanted node: %d\n",search->value);
	
	search = treeSearchIteration(20, root);
	if(search)
	printf("Wanted node: %d\n",search->value);

	tnode *suc = successor(search);
	if(suc)
		printf("Succesor of %d is %d \n", search->value, suc->value);
	else printf("There is no successor of %d node\n", search->value);

	tnode *pred = predecessor(search);
	if(pred)
		printf("Predecessor of %d is %d \n", search->value, pred->value);
	else printf("There is no predecessor of %d node\n", search->value);
*/
	puts("Succesor of every node in specified BST tree :");
	for ( i = 0 ; i < sizeof(tab)/sizeof(tab[0]); i++){
		if(successor(treeSearchRecursion(tab[i], root)) == NULL){
			printf("Node %d doesnt have successor\n", tab[i]);
			continue;
		}
		printf("Successor of %d is %d\n", (treeSearchIteration(tab[i], root))->value, successor(treeSearchIteration(tab[i], root))->value);
	}

	putchar('\n');
	puts("Predecessor of every node in specified BST tree :");
	for ( i = 0 ; i < sizeof(tab)/sizeof(tab[0]); i++){
		if((predecessor(treeSearchIteration(tab[i], root))) == NULL){
			printf("Node %d doesnt have predecessor\n", tab[i]);
			continue;
		}
		printf("Successor of %d is %d\n", (treeSearchIteration(tab[i], root))->value, predecessor(treeSearchIteration(tab[i], root))->value);
	}

	leftRotate(&root, treeSearchIteration(tab[5], root));
	inOrder(root);

	printf("Parents of every node after left rotate of node %d\n", tab[5]);
	for (i = 0; i < sizeof(tab)/sizeof(tab[i]); i++){
		node = treeSearchRecursion(tab[i],root);
		printf("Parents of: %d\n", node->value);
		while(node->parent){
		printf("%d\n", node->parent->value);
		node = node->parent;
	}
	}

}