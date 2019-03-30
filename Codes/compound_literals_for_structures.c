#include <stdlib.h>
#include <stdio.h>

struct foo{int a; char b[2];}structure;

int main(void){
	
	structure = ((struct foo) {2, 'a', 0});
	printf("%d\n",  structure.a);
	printf("%s\n",  structure.b);

	return 0;
}