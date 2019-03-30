#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]){
		
	int a[5] = {1,2,3,4,5};
	printf("a %p \n", a);
	printf("&a %p \n", &a);
	printf("a + 1 %p \n", a + 1);
	printf("&a + 1 %p \n", &a + 1);
	printf("As we can see, the address of the array is... address of the array \n\
but there is difference in arithmetic on this, a + 1, jumps to following array element\n\
&a + 1 jumps whole array, to print the last element of the array we could use now *((pointer_to_&a + 1)- 1)\n");
		
	int * pointer = (int *) (&a + 1) ;
	printf("*(a+1): %d  *(pointer-1): %d \n", *(a+1), *(pointer - 1));
	
	return 0;
}