#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int suma(int *, int *);
void fillTab(int TAB[][20]);
int compare(const void *a,const void *b);
void printArray(int TAB[][20]);

int main(int argc, char const *argv[])
{

	int TAB[100][20], wantedSum;
	fillTab(TAB);
	
	qsort(*TAB,100,sizeof(int)*20,compare);
	puts("Enter wanted sum of a row");
	scnaf("%d", &wantedSum);
	bsearch(wantedSum,*TAB,100,sizeof(int)*20,compare)
	//printArray(TAB);

	return 0;
}

int sum(int *a, int *b){ // counts total value of 1D array

	for (i = 0; i < 20; i ++){
		total1 += a[i];
		total2 += b[i];
	}
	return total1 - total2;
}

void fillTab(int TAB[][20]){
	int i,j;

	for (i = 0; i < 100; i++)
		for(j = 0; j < 20; j++){
			TAB[i][j] = 1 + rand()%100;
		}
}

int compare(const void *a,const void *b){
	int *_a = (int *)a;
	int *_b = (int *)b;
 if ((sum(_a,_b)) > 0)
 	return 1;
 else if ((sum(_a, _b)) < 0)
 	return -1;
 else return 0;
}

void printArray(int TAB[][20]){
	int i,j, total=0;
	for(i = 0; i < 100; i++){
		for (j = 0; j < 20; j++){
			printf("%d ", TAB[i][j]);
			total += TAB[i][j];
		}
		printf(" total: %d", total);
		total = 0;
		putchar('\n');
	}
}
