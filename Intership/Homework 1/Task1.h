#ifndef _TASK1
#define _TASK1
#include "BST.h"

	/*Task 1 */

	/*Declarations of functions used in 1st  and 2nd approach, returning Max (most right) and Min (most left) value of BS Tree
	beggining from passed root */ 
	
	int Max(tnode *);
	int Min(tnode *);

	/*1. The simplest, thus the slowest version, visits some elements of BST many times, 
	this approach uses above functions, definition and declaration of this approach 
	in one place for readability */

	int isSorted_1(tnode * node ){

		if(node == NULL)
			return 1;

		if(node->left != NULL && Max(node->left) > node->value)
			return 0;

		if (node->right != NULL && Min(node->right) < node->value)
			return 0;

		if(!isSorted_1(node->left) || !isSorted_1(node->right))
			return 0;

		return 1;
	} 
	
	/*2. Second approach, founded on deduction concluded from essential BS Tree property
	on most left side of the tree each parent has greater value that it's child,
	on most right side vice versa   
	    */ 
	
  
	int Check(tnode * node, int min, int max){  
	 
	  if (node == NULL)  
	     return 1; 
	        
	  if (node->value < min || node->value > max)  
	     return 0;  

	  return 
	    Check(node->left, min, node->value) && Check(node->right, node->value , max); 
	}  
		
	int isSorted_2(tnode * node) {  
	  return ( Check(node, Min(node->left), Max(node->right)));  
	}  


	/*3. Third approach, based on inOrder ruotine which gives values 
	of BST in ascending order, thus previous value must be 
	less or equal to the following, if not, then given tree is not BST */

	int isSorted_3(tnode *node){
	
	static tnode * previous = NULL;

	if(node){
		if(!isSorted_3(node->left))
			return 0;

		if(previous != NULL && node->value < previous->value)
			return 0;

		previous = node; 

		return isSorted_3(node->right);
	}
	return 1;
}


#endif 