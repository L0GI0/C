#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define N 10
#define M 20

char TEKST[N][M];

int compare(const void *, const void *);
int compareRows(const void *_a, const void *_b);


int main(void){
	int i;
	for(i = 0; i < N; i++)
		scanf("%s", TEKST[i]);
	puts("Print array");
	for(i = 0; i < N; i++)
		printf("%s\n", TEKST[i]);
	for(i = 0; i < N; i++)
	qsort(TEKST[i], strlen(TEKST[i]), sizeof(char), compare);
	puts("Print array after sorting each row alphabetically");
	for(i = 0; i < N; i++)
		printf("%s\n", TEKST[i]);
	qsort(TEKST, 10, sizeof(char ) * 20 , compare);
	//qsort(*TEKST + 4, 5, sizeof(char)* 20, compare);
	puts("Print array after sorting rows alphabetically");
	for(i = 0; i < N; i++)
		printf("%s\n", TEKST[i]);

}

int compare(const void *_a, const void *_b){

	char *a = (char *)_a;
	char *b = (char *)_b;
	char c1 = toupper(*a);
	char c2 = toupper(*b);

	if(strcmp(&c1, &c2) == 0){
		if(islower(*a) && isupper(*b))
			return -1;
		if(isupper(*a) && islower(*b))
		 return 1;
	}
	return strcmp(&c1, &c2);
}

int compareRows(const void *_a, const void *_b){

	int i = 0;
	char *a = (char *)_a;
	char *b = (char *)_b;

	return strcmp(a, b);
}