#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char *c[] = {"HOOD", "LATE", "RING", "BABY"};
	char **cp[] = {c+3, c+2, c+1, c};
	char ***cpp=cp+2;

int main(int argc, char *argv[]){;
	//printf("0: %s \n", *(c + 1)); // 
	printf("1: %s \n", **++cpp + 1); // ODD
	printf("2: %s \n", *++*--cpp - 2);  // 
	printf("3: %s \n" , *cpp[-1] + 2);  // 
	printf("4: %s \n", cpp[-2][-1] + 2); // 

	int i;
	// sizeof(c) = 20
	// siezeof(*c) = 5;
	for (i=sizeof(c)/sizeof(*c); i>0; i--)
		printf("\n%d %s\n", sizeof(c)/sizeof(*c)-i, *cp[i-1]);}	

	//3 HOOD
	//2 LATE
	//1 RING
	//0 BABY