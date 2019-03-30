#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int compare(const void*, const void*);

#define N 100
#define M 20
char TEKST[N][M];

int main(int argc, char const *argv[])
{
	int i;
	while ( fgets(&TEKST[i++][0], sizeof(*TEKST), stdin) != NULL && TEKST[i][0] != '\n' && i < 5);	

	puts("------------------");

	for (i = 0; i < 5; i++){
		printf("%s \n", &TEKST[i][0]);
	} 


	for(i = 0; i < 5; i++)
		qsort(&TEKST[i][0],strlen(&TEKST[i][0]),sizeof(char),compare);

	puts("------------------");
	
		for (i = 0; i < 5; i++){
		printf("%s \n", &TEKST[i][0]);
	} 

	return 0;
}

int compare(const void *a, const void *b){

	char _a = *(char *)a;
	char _b = *(char *)b;
	printf("a: %d, b: %d \n", _a, _b);
	if((int)(_b - _a) > 0 && (int)(_b - _a) > 32)
		return -1;
	else if((int)(_b - _a) > 0)
		return 1;
	else if((int)(_b - _a) < 0 && (int)(_b - _a) > -32)
		return 1;
	else return -1;
	return 0;


}