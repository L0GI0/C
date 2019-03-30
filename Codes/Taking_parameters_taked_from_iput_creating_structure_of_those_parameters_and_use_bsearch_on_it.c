/*  Take parameters typed when calling a function using argv (argument vector) and argc (argument count), creating a dynnamic array of structures from those
parameters sorting with respect to workedYears by emplyeers, and searching using bsearch for a person which work specified amount of years*/
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdarg.h>
#include <time.h>

struct identities{
	char name[21];
	int  firstYearOfLabour;
	int  lastYearOfLabour;
};

void printArray(struct identities *Array, int sizeOfArray);
int compare(const void *, const void *);
int copareFindEmployee(const void *a, const void *b);

int main(int argc, char const *argv[]){
	int i,j,yearsWorked;
	int sizeOfArray = (int) argc/3;
	struct identities *Array = (struct identities *) malloc(sizeof(struct identities) * sizeOfArray);
	//there is always one more argv that we want to read which is arg[1] containing
	// file name, thus we start from i = 1, which prevent from reading invalid data
	/*
	strncpy(Array[0].name,argv[1],20);
	Array[0].firstYearOfLabour = atoi(argv[2]);
	Array[0].lastYearOfLabour = atoi(argv[3]);
	printf("%s %d %d", Array[0].name, Array[0].firstYearOfLabour, Array[0].lastYearOfLabour);
*/

	for(i = 1, j = 0; i + 3 <= argc && j < sizeOfArray; i++, j++){
		strncpy(Array[j].name,argv[i++],20);
		Array[j].firstYearOfLabour = atoi(argv[i++]);
		Array[j].lastYearOfLabour = atoi(argv[i]);
	}
	
	printArray(Array, sizeOfArray);
	qsort(Array,sizeOfArray,sizeof(struct identities), compare);
	puts("Sorted array by years of work");
	printArray(Array, sizeOfArray);
	yearsWorked = 4;
	printf("Searching for emplyeer who have worked for %d years \n", yearsWorked);
	struct identities *Employee = (struct identities *) bsearch(&yearsWorked,Array,sizeOfArray,sizeof(struct identities), copareFindEmployee);
	if (!Employee)
		puts("There is no such employee");
	else
	printf("%s worked for %d years",Employee->name, yearsWorked);
	return 0;
}

void printArray(struct identities *Array, int sizeOfArray){

	int i;
	for ( i = 0; i < sizeOfArray; i++)
		printf("%d. Name: %s  Years of labour: %d \n", i, Array[i].name, Array[i].lastYearOfLabour - Array[i].firstYearOfLabour);
}

int compare(const void *a, const void *b){

	struct identities *_a = (struct identities *)a;
	struct identities *_b = (struct identities *)b;
	return ((_a->lastYearOfLabour - _a->firstYearOfLabour) - (_b->lastYearOfLabour - _b->firstYearOfLabour)); 
}

int copareFindEmployee(const void *a, const void *b){
	struct identities *_b = (struct identities *)b;
	int *_a = (int *)a;
    printf("*_a:%d\n",(_b->lastYearOfLabour) - (_b->firstYearOfLabour));
    printf("*_b:%d\n",*(_a));
	return (*_a - (_b->lastYearOfLabour - _b->firstYearOfLabour));
}