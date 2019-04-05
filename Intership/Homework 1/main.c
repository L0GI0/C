#include <stdio.h>
#include <stdlib.h>
#include "Task1.h"

int main(void){
	
 	//Creating a tree 
 	tnode *root = createLeaf(11,NULL);
	int tab[]={15,5,16,20,3,12,18,23,10,13,6,7};
	for (unsigned int i = 0; i < sizeof(tab)/sizeof(tab[0]); i++)
		addLeaf(tab[i],&root,root);

	//Prints BST in order 
	inOrder(root);

	/*Task 1 (Calling the functions)*/
	/************************/
	/*v1*/ (isSorted_1(root)) ? (printf("Is sorted\n")) : (printf("Not sorted\n"));

	/*v2*/ (isSorted_2(root)) ? (printf("Is sorted\n")) : (printf("Not sorted\n"));

	/*v3*/ (isSorted_3(root)) ? (printf("Is sorted\n")) : (printf("Not sorted\n"));

	//Breaking BST tree property, eg: 
	root->left->value = 100;

	/*v1*/ (isSorted_1(root)) ? (printf("Is sorted\n")) : (printf("Not sorted\n"));

	/*v2*/ (isSorted_2(root)) ? (printf("Is sorted\n")) : (printf("Not sorted\n"));

	/*v3*/ (isSorted_3(root)) ? (printf("Is sorted\n")) : (printf("Not sorted\n"));

	/************************/

}