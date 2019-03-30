#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef union {
	int intValue;
	double doubleValue;
}value;

typedef struct number{
	char typeValue;
	value numberValue;
}numberT;


int main(){
	numberT structure[2] = {{'i',{12}}, {'i',{34}}};
	numberT *pointer1 = &structure[0];
	numberT *pointer2 = &structure[1];
	
	puts("Struct:");
	printf("%c, %d\n", structure[0].typeValue, structure[0].numberValue.intValue); 
	printf("%c, %d\n", structure[1].typeValue, structure[1].numberValue.intValue);

	puts("Pointers:");
	printf("%c, %d\n", pointer1->typeValue, pointer1->numberValue.intValue); 
	printf("%c, %d\n", pointer2->typeValue, pointer2->numberValue.intValue);
	//swapping 
	numberT tmp = *pointer1;
	*pointer1 = *pointer2;
	printf("tmp: %d, pointer1: %d\n", tmp.numberValue.intValue, pointer1->numberValue.intValue);
	*pointer2 = tmp; 
	
	puts("Struct:");
	printf("%c, %d\n", structure[0].typeValue, structure[0].numberValue.intValue); 
	printf("%c, %d\n", structure[1].typeValue, structure[1].numberValue.intValue);

	puts("Pointers:");
	printf("%c, %d\n", pointer1->typeValue, pointer1->numberValue.intValue); 
	printf("%c, %d\n", pointer2->typeValue, pointer2->numberValue.intValue);

}