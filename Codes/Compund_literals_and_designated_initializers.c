#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stru{
	int a;
	double b;
}example;

int main(void){

	//Compund literal structure
	example = (struct stru){1, 2.0};
	printf("%d %lf\n", example.a, example.b);
	//Compound literal array
	int *arr;
	arr = (int []){1, 2 ,3 ,4};
	printf("%d %d %d %d \n", arr[0], arr[1], arr[2], arr[3]);
	//Designated initializers structure
	struct stru example2 = {.a = 2, .b = 1.0};
	//Designated initializers array 
	int arr2[] = {1, 2, 3, [0] = 3, [1] = 2, [2] = 1, [6] = 7};
	for(int i = 0; i < sizeof(arr2)/sizeof(int); i++)
		printf("%d ", arr2[i]);
	return 0;
}