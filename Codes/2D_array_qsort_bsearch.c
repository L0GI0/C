#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>

int compare1(const void *, const void *);
int compare2(const void *_a, const void *_b);
int bsearchcompare(const void *_a, const void *_b);


int TAB[100][20];

int suma(int *, int *);
void fill_array(int (*)[20]);

int main(void){

	srand((unsigned )time(NULL));
	fill_array(TAB);
	for(int i = 0; i < 100; i++)
	qsort(TAB[i], 20, sizeof(int), compare1);
	
	for(int i = 0; i < 100; i++){
		for(int j = 0; j < 20; j++)
			printf("%d ", TAB[i][j]);
		putchar('\n');
	}
	int sum;
	printf("\n\n\n");


	qsort(TAB, 100, sizeof(TAB[0]), compare2);

	printf("\n\n\n");
	for(int i = 0; i < 100; i++){
		sum = 0;
		for(int j = 0; j < 20; j++){
			printf("%d ", TAB[i][j]);
		}
		for(int j = 0; j < 10; j++)
			sum += suma(&TAB[i][j], &TAB[i][19-j]);
		printf(": %d", sum);
		putchar('\n');
	}

	int wanted_sum;
	printf("\nEnter wanted total value of a rows:\n");
	scanf("%d", &wanted_sum);
	int *find = bsearch(&wanted_sum, TAB, 100, sizeof(int) * 20, bsearchcompare);
	if(find){
		printf("%p %p %p\n", (find - *TAB), find, *TAB);
		printf("%d row has such total value \n", (int) (find - *TAB)/20 + 1);
		for(int i = 0; i < 20; i++)
			printf("%d ", find[i]);
	}
	else( fprintf(stderr,"There is no row witch such total value"));
	return 0;
}

void fill_array(int (*Array)[20]){

	int i,j;
	for(i = 0; i < 100; i++)
		for(j = 0; j < 20; j++)
			Array[i][j] = 1 + rand()%100;
}

int suma(int *a, int *b){
	
	return *a + *b;
}

int compare1(const void *_a, const void *_b){
	int *a = (int *)_a;
	int *b = (int *)_b;
	return *a - *b;
}

int compare2(const void *_a, const void *_b){

	int sum1 = 0, sum2 = 0;
	int *a = (int *)_a;
	int *b = (int *)_b;
	for(int i = 0; i < 10; i++){
		printf("%d ", a[i]);
		sum1 += suma(&a[i], &a[19 - i]);
	}
	putchar('\n');
	for(int i = 0; i < 10; i++){
		printf("%d ", b[i]);
		sum2 += suma(&b[i], &b[19 - i]);
	}
	putchar('\n');
	return sum1 - sum2;

}

int bsearchcompare(const void *_a, const void *_b){
	
	int total = 0;
	int *a = (int *)_a;
	int *b = (int *)_b;
	for(int i = 0; i < 10; i++)
		total += suma(&b[i], &b[19-i]);

	return (*(a) - total);

}