/* stringizing.c -- substitute in string 
Suppose you do want to include the macro agument in a string. C engalbes you to do that. 
Within the replecement part of a function-like marko, the # sympol becomes a preprocessing
operator that converts tokens into string . For exmaple, say that x is a macro parameter, and
then #x is that parameter name converted to the string "x". This process is calles stringizing*/
#include <stdio.h>
#define PSQR(x) printf("The square of " #x " is %d.\n", ((x) * (x)))

int main(void){
	int y = 5;

	PSQR(y);
	PSQR(2 + 4);

	return 0;
}