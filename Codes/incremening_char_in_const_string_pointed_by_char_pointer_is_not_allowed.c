#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){

	char wski1[] = "Analfabeta";
	printf("%c \n", ++*wski1);//Here we are changing 1st character to B;
	printf("%s", wski1); 
	char *wski2 = "Analfabeta"; //U changeable string
	printf("%c \n", ++*wski2); //here we got segmenation faul becuse we tring to change constant
	// value



	return 0;	
}