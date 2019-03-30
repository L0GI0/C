#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	int Arr1[3] = {1, 2, 3};
	double Arr2[][3] = { {3, 2, 1}, {1,2,3} };
	printf("Arr1: %p, &Arr1: %p \n",Arr1, &Arr1);
	printf("Arr2: %p, &Arr2: %p \n",Arr2, &Arr2);

	double (*pointer)[][3];
	pointer = &Arr2;

	printf("Pointer:  %p", Arr2);
	printf("Pointer:  %f", *(**pointer + 1));
	return 0;
}

