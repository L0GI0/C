#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int evenNumberOfZeros(int value);
void printBin(int value);
int main(void){
	
	int value;
	value = evenNumberOfZeros(11);
	printBin(value);

}

int evenNumberOfZeros(int value){

	unsigned int mask = 1;
	unsigned int zeroCounter = 0;
	while (mask != 256){
		if((value | mask) != value )
			zeroCounter++;
		mask <<= 1;
	}
	printf("Zeros : %d\n", zeroCounter);
	if (zeroCounter%2 == 0)
		return value;
	return value ^ 1;
 }   

void printBin(int value){
	int i;
	char binary[8];
	int mask = 128;
	for ( i = 0; i < 8; i++){
		if((value | mask) == value)
			binary[i] = '1';
		else binary[i] = '0';
		mask >>=1;
	}
	printf("%s", binary);
}
                                                                                                                               