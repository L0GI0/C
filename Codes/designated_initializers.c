#include <stdio.h>
#include <stdlib.h>
#define MONTHS 12
int main(void){
	int i;
	int Array[] = {1, 2, 20, [1] = 19, [0] = 18, [6] = 24, 25, 26};
	for (i = 0; i < sizeof(Array)/sizeof(int); i++)
		printf("%d ", Array[i]);
	putchar('\n');
	putchar('\n');
	int days[MONTHS] = {31,28, [4] = 31,30,31, [1] = 29};

	for(i = 0; i < MONTHS; i++)
		printf("%2d %d\n", i + 1, days[i]);

	return 0;
}