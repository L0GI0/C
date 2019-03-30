#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int mniejszy(int *, int*);
int wiekszy(int *, int*);
int rowny(int *, int*);

int main(void){

	char *pinters_to_strings[] = {"mniejszy", "wiekszy", "rowny"};
	int (*functions[])(int *, int *) = {mniejszy, wiekszy, rowny};
	char not_string[] = {'m','n','i','e','j','s','z','y'};
	char string[] = "mniejszy";
	char *pointer_to_string = "wiekszy";
	printf("size of not_string[]: %lu as we can see, \n\
there is no end of line character, which string should contain,\n\
sizeof string[]: %lu, it is because string has EOF character\n", sizeof(not_string), sizeof(string));
	return 0;
}

int mniejszy(int *a, int *b){

	return 0;
}
int wiekszy(int *a, int *b){

	return 0;
}
int rowny(int *a, int *b){

	return 0;
}