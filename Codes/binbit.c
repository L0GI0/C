/* binbit.c -- using bit operations to display binary */

#include <stdio.h>
#include <limits.h> // for CHAR_BIT

char *itobs(int, char *);
void show_bstr(const char *);
int invert_end(int, int);
int main(void){

	char bin_str[CHAR_BIT * sizeof(int) + 1];
	int number;

	puts("Enter integers and see them in binary.");
	puts("Non-numeric input terminates program.");
	while(scanf("%d",&number) == 1){
		itobs(number,bin_str);
		printf("%d is ", number);
		show_bstr(bin_str);
		putchar('\n');
		number = invert_end(number, 4);
		printf("Invering the last 4 bits given\n");
		show_bstr(itobs(number,bin_str));
		putchar('\n');
	}
}

char *itobs(int number, char *str){

	const int size = CHAR_BIT * sizeof(int);

	for ( int  i = size -1; i >= 0; i--, number  >>= 1){
		str[i] =  (01 & number) + '0';
	}
	str[size] = '\0';
	return str;
}

// show binary string in block of 4 

void show_bstr( const char * str){

	int i =0;

	while(str[i]){ // not the null character
		putchar(str[i]);

		if( ++i % 4 == 0 && str[i])
			putchar(' ');
	}
}

int invert_end(int number, int bits){

	int mask = 0;
	int bitval = 1;

	while( bits-- > 0){
		mask |= bitval;
		bitval <<= 1;
	}

	return number ^ mask;
}