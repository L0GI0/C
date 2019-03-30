#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void){

	char string[] = "Random string for education purpose";
	puts(string);
	char *word = strstr(string,"purpose");
	strcpy(word,"purposes");
	puts(string);
	}
