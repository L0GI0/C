#ifndef _TREE_H
#define _TREE_H

//node structure 
typedef struct tnode{

	int value;
	struct tnode *left;
	struct tnode *right;
	struct tnode *parent;
}tnode;


//functions declarations:
tnode *createLeaf(int value, tnode *root);
void addLeaf(int value, tnode **root, tnode *current);
void preOrder(tnode *);
void inOrder(tnode *);
void postOrder(tnode *);

tnode *treeMaxIteration(tnode *);
tnode *treeMinIteration(tnode *);
tnode *treeSearchRecursion(int, tnode *);
tnode *treeSearchIteration(int , tnode *);
tnode *successor(tnode *);
tnode *predecessor(tnode *leaf);
void leftRotate(tnode **root, tnode *leaf);

//other prototypes

#endif