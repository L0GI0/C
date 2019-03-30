#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdarg.h>

int mniejszy (int *, int *);
int wiekszy (int *, int *);
int rowny (int *, int *);

int main(int argc, char const *argv[])
{

	 char *a[] = {"mniejszy", "wiekszy", "rowny"};
	 char b[] = {'m','n','i','e','j','s','z','y','\0'};
	 char *c = "wiekszy";
	 printf("%s", b);


	int *test1, *test2, test;
	int (*ptr[3])(int *, int *) = {mniejszy, wiekszy, rowny}; 

	printf("%d\n",ptr[0](test1, test2));
	return 0;
}

int mniejszy (int *a, int *b){
	return 2;
}
int wiekszy (int *a, int *b){

	return 0;
}
int rowny (int *a, int *b){

	return 0;
}