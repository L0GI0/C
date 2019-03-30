
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdarg.h>
#include <time.h>

char *ARR[100];

void fillArray(char *ARR[100]);
void printArray(char *ARR[100]);
int compareRowElements(const void *a, const void *b);
int compareRows(const void *a, const void *b);


int compareBsearch(const void *a, const void *b);
int main(int argc, char const *argv[]){
	
	int i;
	char *string;
	srand((unsigned)time(NULL));	
	fillArray(ARR);
	puts("Array before using qsort for sorting each row alphabetically: ");
	putchar('\n');
	printArray(ARR);
	for (i = 0; i < 100; i++)
	qsort(ARR[i],20,sizeof(char),compareRowElements);
	printArray(ARR);
	putchar('\n');
	puts("Array after using qsort for sorting each row alphabetically: ");
	putchar('\n');
	printArray(ARR);
	puts("Array after using qsort for sorting rows alphabetically: ");
	qsort(ARR,100,sizeof(char *),compareRows);
	printArray(ARR);
	puts("Enter a wanted string to search in array, max lenght is 20:");
	fgets(string,21,stdin);
	char (*wantedString)[20] = (char *)(bsearch(&string, ARR, 100, sizeof(ARR[0]), compareBsearch));
	//if(wantedString){	
	//printf("Wanted string is stored in %d row of an Array", i);
			//}
	return 0;
}

void fillArray(char *ARR[100]){

	int i,j;
	//random string :
	for(j = 0; j < 100; j++){
		 ARR[j] = malloc(sizeof(char) * 20);
	for (i = 0; i < 20; i++){
         ARR[j][i] = 'a' + rand()%('z' - 'a');
	}
	}
}

void printArray(char *ARR[100]){

	int i;
	for(i = 0; i < 100; i++)
			puts(ARR[i]);
	}

int compareRowElements(const void *a,const void *b){
	
	char *_a = (char *)a;
	char *_b = (char *)b;
	return strcmp(_a,_b);
}

int compareRows(const void *a, const void *b){

	char **_a = (char **)a;
	char **_b = (char **)b;

	return strcmp(*_a,*_b);
}


int compareBsearch(const void *a, const void *b){

	char **_a = (char **)a;
	char **_b = (char **)b;
	
	printf("%s\n",*_a);
	printf("%s\n",*_b);
	return strcmp(*_a,*_b);



}