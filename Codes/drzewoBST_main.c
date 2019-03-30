#include <stdio.h>
#include <stdlib.h>
#include "drzewoBST.h"

int main(){
	int tab[] = {15,5,16,20,3,12,18,23,10,13,6,7};
	int i;
	tnode *root = createLeaf(10,NULL);
	
	
	for (i = 0; i < sizeof(tab)/sizeof(tab[0]); i++)
		addLeafRecursion(tab[i], &root, root);
	inOrder(root);
}