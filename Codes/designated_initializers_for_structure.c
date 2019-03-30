#include <stdio.h>
#include <stdlib.h>

struct strm{
	int a;
	int b;
	int c;
}ob = {.c=30,  .a=10};


int main(void){
	
	printf("ob.c = %d\nob.a = %d\n", ob.c, ob.a);


	return 0;
}