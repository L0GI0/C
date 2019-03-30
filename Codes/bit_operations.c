#include <stdio.h>
#include <stdlib.h>

int main(void){

	unsigned short int i = 0x0000;
	
	// ustawianie 4-tego bitu
	i = 0x0010;
	printf("i = 0x0010 : %d \n ", i);
	i = 0x0000;
	printf("i = 0x0000 : %d \n ", i);
	i |= 1 << 4;
	printf("i |= 1 << 4 : %d \n ", i);
	// kasowanie 4 bitu przy pomocy maski bitowej
	i = 0x00ff;
	printf("i = 0x00ff: %d\n", i);
	i = i & ~(1 << 4);
	printf(" i &= ~(1 << 4): %d \n", i);
	// testowanie bitu 
	i = 0x0010;
	printf(" i = 0x0010 : %d\n", i);
	if( i & 0x0010)
		printf("i & 0x0010 is true cos gives value different that 0");
	return 0;
}