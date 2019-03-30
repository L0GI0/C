#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

void print_types(const char type[], ...);

int main(void){
	printf("Sekwencja typow: char(c)-int(i)-double(d)-double(f)-int(i)-char(c)\n");
	print_types("cidfic", 'j', 2, 3.0, 5.0, 10, 'd');
	return 0;
}

void print_types(const char type[], ...){

	char c;
	va_list ap;
	va_start(ap, type);
	while( c = *type++){
		switch(c){
			case 'c':
				printf("Char: %c\n", va_arg(ap, int));
				break;
			case 'i':
				printf("Int: %d\n", va_arg(ap, int));	
				break;
			case 'f':
				printf("Float: %f\n", va_arg(ap, double));
				break;
			case 'd':
				printf("Double: %lf\n", va_arg(ap, double));
				break;
			default:
				va_arg(ap, int);
				break;
		}
	}
	va_end(ap);
}