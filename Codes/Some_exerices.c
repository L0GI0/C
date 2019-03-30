#include <stdio.h>
#include <stdlib.h>
#include <string.h>
double X[5], Y[40][8][2];

int main(void){

	double *px, (*py)[8][2], (*pz)[2];
//1
	px=X;
	py=Y;
	pz=Y[2];
//2
	printf("%d\n", strcmp("TAK","NIE"));
	printf("%d\n", strcmp("TAK","tak"));
	printf("%d\n", strcmp("TAK","TAK"));
//3 
/*
	int i=4, j=8, k=2;
	printf("%d\n", j >>i || ++j < k);
	printf("i=%d, j=%d, k=%d\n",i,j,k);

	i=4,j=6;
	printf("%d\n", i << 1 * j >> 2);
	printf("i=%d, j=%d\n", i, j);

	int x=-1, y=-1, z=-1;
	printf("%d \n", ++x || ++y && z--);
	printf(" x=%d, y=%d, z=%d \n", x,y,z);
	*/
//4
int i = 0;
const int *a = &i;
int * const b = &i;
int const * const c = &i;

*a = 1;
*b = 2;
*c = 3;

a=b;
b=a;
c=a; 
}
