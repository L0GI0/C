#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdarg.h>

void print_types(const char type[], ...);

int main(int argc, char const *argv[]){
	
	printf("Sekwencja typow: char(c)-int(i)-double(d)-double(f)-int(i)-char(c)\n");
	print_types("cidfic", 'j', '4', 4.7773, 4.12, 77, 'x');// przykladowe wywolanie
	return 0;}
	


	void print_types(const char type[],...){
		int i = 0, integ, strin;
		char c;
		double doubl;
		float flo;

		va_list ap;

		va_start(ap, type);

		while( (c = type[i++])!='\0'){
			switch(c){
				case 'i':
					integ = va_arg(ap,int);
					printf("Liczba int: %d\n", integ);
					break;
				case 'f':
					flo = va_arg(ap, double);
					printf("Liczba float: %0.2f\n",flo);
					break;
				case 'd':
					doubl = va_arg(ap, double);
					printf("Liczba double: %f \n", doubl);
					break;
				case 'c':
					c = va_arg(ap, int);
					printf("Char: %c \n", c);
					break;
				default:
					strin = va_arg(ap, int);
					break;
			}
		}
		va_end(ap);
	}