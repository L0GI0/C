#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char const *argv[]){
/*	
	int i=4,j=8,k=2;
	printf("%d\n", j>>k || ++j < k);
	printf("i=%d j=%d k=%d\n",i,j,k);

	unsigned int i=4, j=6;
	printf("%d\n",i << 1 * j >> 2); // multiplication is evaluated 1st cause it has higher precedense
	printf("i=%d, j=%d\n",i,j);
*/

	int x=-1,y=-1,z=-1;
	printf("%d \n", ++x || ++y && z--);
	printf("x=%d, y=%d, z=%d \n",x,y,z);

	return 0;
	}