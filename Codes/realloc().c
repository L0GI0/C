#include <stdio.h>
#include <stdlib.h>

int main(void){

	int *ptr = (int *)malloc(sizeof(int) * 2);
	int i;
	int *ptr_new;

	*ptr = 10;
	*(ptr + 1) = 20;

	ptr_new = (int *) realloc(ptr, sizeof(int ) * 3);
	*(ptr_new + 2) = 30;
	for ( i = 0; < 3; i ++)
		printf("%d ", *(ptr_new + i));

	return 0;
	
}