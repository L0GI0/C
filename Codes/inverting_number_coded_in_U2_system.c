#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int multiplicativeInverse(int value);

int main(int argc, char *argv[]){
	
	int inverted;
	inverted = multiplicativeInverse(10);
	printf("%d\n", inverted);
}

 int multiplicativeInverse(int value){
 		value = ~value;
 		value += 1;
 		return value;
 } 