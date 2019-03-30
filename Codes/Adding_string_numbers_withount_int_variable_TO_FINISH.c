#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *addNumbers(char number1[201], char number2[201]);

int main(){

	char number1[201];
	char number2[201];
	puts("Enter 1st number: ");
	fgets(number1,201,stdin);
	puts("Enter 1st number: ");
    fgets(number2,201,stdin);
    char *result = addNumbers(number1,number2);
    printf("Result:%s \n",result);
}

char *addNumbers(char number1[201], char number2[201]){

	int length1, length2,resultLength, i;
	length1 = strlen(number1);
	length2 = strlen(number2);
    char wynik[201];
    if(length1 > length2){

    	for ( i = 0; i < length1; i++){
    		wynik[length1 - 1] = number1[lenth1 - 1] +  
    	}

    }




	return result;
}
