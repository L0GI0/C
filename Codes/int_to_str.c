#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char *int_to_str(int );

int main(void){
	char *returned_string;
	int value_to_convert = -123;
	returned_string = int_to_str(value_to_convert);
	printf("*returned_string = int_to_string(%d)\nprintf(\"%%s\", returned_string);\n%s \n", value_to_convert, returned_string);
	return 0;
}

char *int_to_str(int value_to_convert){
	int i;
	int digits = log10(abs(value_to_convert)) + 1;
	char *string;
	if(value_to_convert >= 0)
	 string = (char *) malloc(sizeof(char) *digits);
	else string = (char *) malloc(sizeof(char) * digits + 1);
	for(i = value_to_convert > 0 ? digits - 1: digits; i >= 0; i--){
		string[i] = '0' + abs(value_to_convert%10);
		value_to_convert = abs(value_to_convert/10) ; 
	}
	if(string[0] == '0')
		string[0] = '-';
	return string;
}

// simpler method would be using sprintf() functio but u need to take of of string length, it may vary depending on value type
// and u need to make it big enough to contain whole number
/*   char converted_value[12];
	 int value_to_convert = 123;
	 sprintf(converted_value, "%d", value_to_conver);	  */
