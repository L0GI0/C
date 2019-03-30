// designate.c -- use designated initializers, and some gap advices
#include <stdio.h>
#define MONTHS 12 //always use gap between end of header code and start of main function

int main(void){     
int days[MONTHS] = {31, 28, [4] = 31, 30, 31, [1] = 29};
int i; // use gap between initialization and  and other part of the code

	for (i = 0 ; i < MONTHS; i++)
		printf("%2d  %d\n", i, days[i]); // use gap between end of whole code in main function and return command
	
	return 0;
}