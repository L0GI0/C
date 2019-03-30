#ifndef _TREE_H
#define _TREE_H

typedef struct tnode{
	int value;
	struct tnode * left;
	struct tnode * rigth;
	struct tnode * parent;
}tnode;

tnode *createLeaf(int value, tnode *parent);
void addLeafRecursion(int value, tnode **root, tnode *current);
void inOrder(tnode *root);

//other prototypes
#endif