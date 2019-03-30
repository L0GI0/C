#include <stdio.h>
#include <stdlib.h>
#include "BST.h"


tleaf *create_leaf(tleaf *parent, int value){

	tleaf *new = (tleaf *) malloc (sizeof(tleaf));
	new->left = new->right = NULL;
	new->parent = parent;
	new->value = value;
	return new;
}

void add_leaf(tleaf **root, tleaf *previous, int value){

		if(!(*root)){
			(*root) = create_leaf(previous, value);
			return;
		}
		if((*root)->value > value)
			add_leaf(&(*root)->left, *root, value);
		else add_leaf(&(*root)->right, *root, value);
}

void in_order(tleaf *leaf){
	if(!leaf)
		return;	
	in_order(leaf->left);
	printf("%d ", leaf->value);
	in_order(leaf->right);
}

tleaf *tree_min(tleaf *leaf){
	if(!(leaf->left))
		return leaf;
	return tree_min(leaf->left);

}

tleaf *tree_max(tleaf *leaf){
	if(!(leaf->right))
		return leaf;
	return tree_max(leaf->right);
}

tleaf *tree_search_iteration(tleaf *leaf, int value){

	while( leaf && leaf->value != value){
		if(leaf->value > value)
			leaf = leaf->left;
		else leaf = leaf->right;
	}
	if(!leaf){
		fprintf(stderr,"There is no such leaf \n");
		return NULL;
	}
	else return leaf;
}

tleaf *tree_search_recursion(tleaf *leaf, int value){

	if(!leaf){
		fprintf(stderr,"There is no such leaf \n");
		return NULL;
	}
	if(leaf->value == value)
		return leaf;
	if(leaf->value > value)
		tree_search_recursion(leaf->left, value);
	else tree_search_recursion(leaf->right, value);
	return NULL;
}

tleaf *predecessor(tleaf *leaf){
	if (leaf->left)
		return tree_max(leaf->left);
	while( leaf->parent && leaf->parent->left == leaf)
		leaf = leaf->parent;
	if(!leaf->parent){
		fprintf(stderr, "This node has no precedessor\n");
		return NULL;
	}
	return leaf;
}

tleaf *successor(tleaf *leaf){
	if(leaf->right)
		return tree_min(leaf->right);
	while( leaf->parent && leaf->parent->right == leaf)
		leaf = leaf->parent;
	if(!leaf->parent){
		fprintf(stderr, " This node has no successor \n");
		return NULL;
	}
	return leaf;
}