#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define N 100
#define M 20
char TEKST[N][M];

void fillArray();
void printArray();
int compare2(const void *a, const void *b);
int compare(const void *_a, const void *_b);

int main(void){
	srand((unsigned)time(NULL));
	int i,j;
	fillArray();
	printArray();
	for(i = 0; i < N; i++)
	qsort(TEKST[i],20,sizeof(char), compare);
	printf("\n After sorting \n");
	printArray();
	
	qsort(TEKST, 100, sizeof(char *), compare);
	//qsort(TEKST + 49, 50, sizeof(TEKST[0]), compare2);
}

void fillArray(){

	int i,j, random;
	for(i = 0; i < N; i++){
		for(j = 0; j < M; j++){
				random = rand()%2;
				if(random == 1)
			TEKST[i][j] = 'a' + rand()%('z' - 'a');
				else
			TEKST[i][j] = 'A' + rand()%('Z' - 'A');
		}
	}
}


int compare(const void *_a, const void *_b){
 
 char *a = (char *)_a;
 char *b = (char *)_b;

 return strcmp(a,b);
}

void printArray(){
	int i,j;
	for (i = 0; i < N; i++){
			for(j = 0; j < M; j++)
				printf("%c", TEKST[i][j]);
			putchar('\n');
		}
}

int compare2(const void *a, const void *b){
	char **_a = (char **)a;
	char **_b = (char **)b;

	return strcmp(*_a,*_b);
}