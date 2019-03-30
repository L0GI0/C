#include <stdio.h>
#include <stdlib.h>
#include "drzewoBST.h"


tnode *createLeaf(int value, tnode *parent){

	tnode *new = (tnode *) malloc(sizeof(tnode));
	if(!new){
		puts("Cant create new leaf");
		exit(EXIT_FAILURE);
	}
	new->right = new->left = NULL;
	new->value = value;
	new->parent = parent;
	return new;
}


void addLeaf(int value, tnode **root, tnode *current){

	if(!(*root)){
		*root = createLeaf(value, current);
		return; 
	}
	if((*root)->value > value)
		addLeaf(value,&(*root)->left, *root);
	else
		addLeaf(value,&(*root)->right, *root);
}

void inOrder(tnode *leaf){
	if(!leaf)
		return;
	inOrder(leaf->left);
	printf("%d\n",leaf->value);
	inOrder(leaf->right);
}

void preOrder(tnode *leaf){
	if(!leaf)
		return;
	printf("%d\n",leaf->value);
	inOrder(leaf->left);
	inOrder(leaf->right);
}

void postOrder(tnode *leaf){
	if(!leaf)
		return;
	inOrder(leaf->left);
	inOrder(leaf->right);
	printf("%d\n",leaf->value);
}

tnode *treeMinRecursion(tnode *leaf){
	if(leaf->left)
	return treeMinRecursion(leaf->left);
	return leaf;
	
}

tnode *treeMaxRecursion(tnode *leaf){
	if(leaf->right)
	return treeMaxRecursion(leaf->right);
	return leaf;

}

tnode *treeMaxIteration(tnode *leaf){
	while(leaf->right)
		leaf = leaf->right;
	return leaf;
}

tnode *treeMinIteration(tnode *leaf){
	while(leaf->left)
		leaf = leaf->left;
	return leaf;
}

tnode *treeSearchIteration(int value, tnode *leaf){
	while(leaf){
		if (leaf->value == value)
			break;
		else if(leaf->value > value )
			leaf = leaf->left;
	 	else leaf = leaf->right;
	}
	if(!leaf){
		puts("Cant find such leaf");
		return NULL;
	}
	return leaf;
}

tnode *treeSearchRecursion(int value, tnode *leaf){
		if(!leaf){
			puts("Cant find such leaf");
			return NULL;
		}
		if(leaf->value == value)
			return leaf;

		if(leaf->value > value)
			return treeSearchRecursion(value, leaf->left);
		else return treeSearchRecursion(value, leaf->right);
}	

tnode *successor(tnode *leaf){
	if(leaf->right)
		return treeMinRecursion(leaf->right);
	else while( leaf->parent && leaf == leaf->parent->right )
		leaf = leaf->parent;
      
	return leaf->parent;
}

tnode *predecessor(tnode *leaf){

	if(leaf->left)
		return treeMaxRecursion(leaf->left);
	else while( leaf->parent && leaf == leaf->parent->left )
		leaf = leaf->parent;
	return leaf->parent;
}

void leftRotate(tnode **root, tnode *x){
	tnode *y = x->right;
	x->right = y->left;
	if(y->left)
		y->left->parent = x;
	y->parent = x->parent;
	if(!x->parent)
		*root = y;
	else if(x->parent->left == x)
		x->parent->left = y;
	else x->parent->right = y;
	y->left = x;
	x->parent = y;
}


