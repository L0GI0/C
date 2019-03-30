#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int TAB[7][6];
int (*FF(int k))[2];
char * NAP[] = {"nap1", "nap2", "nap3"};
double T[3][2] = { {1.0,1.0}, {1.0,1.2}, {2.0,3.0} };

int main(void){
	

	double *((* a)[2]);                                                                                                                                                                                                                                       vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvfrhb];
	a = &T;
	
	int *b;
	b = FF + 1;
	
	int *c ;
	c = FF(9);

	int *d;//ok
	d = TAB[2];

	char *f;
	f = *NAP + 1;

	int g;//ok
	g = *NAP[1]++;

	//ok
	double (*h)[2];
	h = (double [][2]){1.0, 3.0, 4.0};
	//ok
	char **k;
	k = NAP;

	return 0;
}
/* Some explanations:
For arrays, a compound literal looks like an array initialization list preceed by a type name
that is enclosed in parantheses. For example, here's an ordinary array declaration:

int diva[2] = {10, 20};

And here's a compound literal that creates a nameless array containing the same two int
values: 

(int [2]){10,20};

Note that the type name is what you would get if you remove diva from the earlier declaration, 
leaving int [2] behind

Just as you can leave out the array size if you initialize a named array, you can omit if from a 
compund literal, and the compiler will count how many elements are present:

(int[]{50, 20, 90}) // a compound literal with 3 elements

Because these compound literals are nameless, you can't just create them in one statement and
then use them later, Instead, you have to use them somehow when you make them. One way
is to use a pointer to keep track of the location. That is, you can do something like this: 

int * pt1;
pt1 = (int [2]){10,20};
 */



