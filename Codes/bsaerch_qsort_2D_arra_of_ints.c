#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int TAB[100][20];

void fillArray(int TAB[][20]);
int compare(const void *, const void *);
void printArray(int TAB[][20]);
int compareBsearch(const void *, const void *);
int getRowNumber(int TAB[][20], int *);

int main(int argc, char *argv[]){
	srand((unsigned)time(NULL));	
	fillArray(TAB);
	qsort(TAB, 100, sizeof(int) * 20, compare);
	printArray(TAB);
	int *find, searchFor;
	puts("Enter wanted total walue of a row:");
	scanf("%d", &searchFor);
	
	find = bsearch(&searchFor, TAB, 100, sizeof(TAB[0]), compareBsearch);
	if(find != NULL)
		printf("Found such sum in %d row ", getRowNumber(TAB, find));


}

void fillArray(int TAB[][20]){

	int i,j;
	for (i = 0; i < 100; i++){
		for (j = 0; j < 20; j++)
			TAB[i][j] = 1+ rand()%100;
	}
}

int sum(int *Array1, int *Array2){
	int i;
	int sum1=0, sum2 = 0;
	for (i = 0; i < 20; i++){
		sum1 += Array1[i];
		sum2 += Array2[i];
	}
	return sum1 - sum2;
}

int compare(const void *_a, const void *_b){

	int *a = (int *)_a;
	int *b = (int *)_b;
	if(sum(a,b) > 0)
		return 1;
	else if (sum(a,b) < 0)
		return -1;
	else return 0;

}

void printArray(int Array[][20]){
	int i,j, sum = 0;
	for (i = 0; i < 100; i++){
		for (j = 0; j < 20; j++){
			printf("%d ", Array[i][j]);
			sum += Array[i][j];
		}
		printf(" Sum of a row : %d", sum);
		sum = 0;
		putchar('\n');
	}
}


int compareBsearch(const void *_a, const void *_b){

	int *a = (int *)_a;
	int *b = (int *)_b;
	int i, sum = 0;
	for (i = 0; i < 20; i++)
		sum += b[i];
	if (sum == *a)
		return 0;
	else if (*a > sum)
		return 1;
	else return -1;
}

int getRowNumber(int TAB[][20], int *found){
	int i= 0;
	while(sum(&TAB[i], found)){
		i++;
	}
	return ++i;
}

