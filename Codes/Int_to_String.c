#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdarg.h>
#include <time.h>


char * int_to_str(int );


int main(int argc, char const *argv[])
{
	char *string;
	string = int_to_str(431);	
	puts(string);
	free(string);
	return 0;
}


char * int_to_str(int value){
	int i;
	int numberOfDigits = log10(value) + 1;
	char testarray[10];
	
	char *string = malloc(sizeof(char) * (numberOfDigits + 1));
	for(i = numberOfDigits - 1; i >= 0; i--){
		string[i] = '0' + value%10;
		value /= 10;	
	}
		string[numberOfDigits + 1] = '\0';
	    return string;
}
