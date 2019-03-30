#include <stdio.h>
#include <stdlib.h>

int add2(int *, int *);
int comp2(int *, int *);
int add2_or_comp2(int, int, int(*fun)(int *, int*));

int main(void){
	printf("%d",add2_or_comp2(2, 3, comp2));

	return 0;
}

int add2(int *a, int *b){

	return *a + *b;
}

int comp2(int *a, int *b){

	return *a - *b;
}

int add2_or_comp2(int a, int b, int(*fun)(int *, int*)){

	return fun(&a, &b);	
}
