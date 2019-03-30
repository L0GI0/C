#include <stdio.h>
#include <stdlib.h>
#include "drzewoBST.h"

tnode *createLeaf(int value, tnode *parent){

	tnode *new = malloc(sizeof(tnode));
	if(!new){
		puts("Can't create a Leaf");
		return NULL;
	}
	new->value = value;
	new->rigth = new->left = NULL;
	new->parent = parent;

	return new;
}

void addLeafRecursion(int value, tnode **root, tnode *current){
		if(*root == NULL){
		*root = createLeaf(value, current);
		return;
	}
	if((*root)->value > value)
		addLeafRecursion(value, &(*root)->left, *root);
	else 
		addLeafRecursion(value, &(*root)->rigth, *root);
		
}

void inOrder(tnode *root){
	if(root){ 
	inOrder(root->left);
	printf("%d\n", root->value);
	inOrder(root->rigth	);
}
}
