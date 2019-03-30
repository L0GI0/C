#include <stdio.h>
#include <stdlib.h>

int main(void){

	int *(*x[10])(void); /*array of 10 pointer to function 
						 returning pointer to int and taking no arguments*/
	//creating the same array using typedef : 
	typedef int *Fnc(void); /*declaring type of function taking no arguments
							and returning pointer to int */
	typedef Fnc *Fnc_ptr // creating type of pointer to such function
	typedef Fnc_ptr Fnc_ptr_array[10]; //creating tpe of array of such pointers
	Fcn_ptr_array y; // declaring such array
	// at this point y is the same as x
}