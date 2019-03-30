#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
	int i;
	int Source[] = {1,2,3,4,5,6,7,8};
	int Destination[] = {1,2,3,4,5,5,3,2};
	memcpy(Destination + 5, Source + 5 ,3 * sizeof(int));
	for (i = 0; i < sizeof(Destination)/sizeof(int); i++)
		printf("%d ", Destination[i]);
	// set source array to destination array in reversed order
	for (i = 0; i < sizeof(Destination)/sizeof(int); i++){
		memmove(Destination + i, Source + 7 - i, sizeof(int));
	}
	putchar('\n');	
	for (i = 0; i < sizeof(Destination)/sizeof(int); i++){
		printf("%d ",Destination[i]);
	}


}