#ifndef _BST_
#define _BST_

typedef struct leaf{
	int value;
	struct leaf *left;
	struct leaf *right;
	struct leaf *parent;
}tleaf;


tleaf *create_leaf(tleaf *, int);
void add_leaf(tleaf **, tleaf *, int value);
void in_order(tleaf *leaf);
tleaf *tree_min(tleaf *leaf);
tleaf *tree_max(tleaf *leaf);
tleaf *tree_search_iteration(tleaf *, int);
tleaf *tree_search_recursion(tleaf *, int );
tleaf *predecessor(tleaf *leaf);
tleaf *successor(tleaf *leaf);

#endif
