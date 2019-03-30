#include <stdio.h>
#include <stdlib.h>

void suma(int *, int *, int);

int main(void){
	int i;
	int A[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int B[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

	int T_1[3][3] = {	{1, 2, 3},
						{4, 5, 6},
						{7, 8, 9},		
								};

	int T_2[3][3] = {	{1, 2, 3},
						{4, 5, 6},
						{7, 8, 9},		
								};
								

	suma(*T_1, *T_2, 3*3);
	suma(A, B, 10);
	for(i = 0; i < 10; i++)
	printf("%d %d\n", A[i], B[i]);
	putchar('\n');
	for(i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
			printf("%d %d \n", T_1[i][j], T_2[i][j]);

	return 0;}

void suma(int *A, int *B, int size){

	int i;
	for(i = 0; i < size; i++){
		A[i] += B[i];
		B[i] = A[i];
	}
}
