#include <stdio.h>
#include <stdlib.h>

int main(void){

	enum moneta {penny, nickel = 7, dime, quarter, 
	half_dolar, dolar = 15} variable;

	int i = quarter;
	printf("%d \n", i);
	i = penny;
	printf("%d \n", i);
	i = dolar;
	printf("%d \n", i);
	i = half_dolar;
	printf("%d \n", i);
	variable = nickel;
	i = variable;
	printf("%d \n", i);

}