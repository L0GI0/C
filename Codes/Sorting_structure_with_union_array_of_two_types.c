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


void fillArray(numberT *Array);
void printArray(numberT *Array);
void sortArray(numberT *Array);
void swap(numberT *, numberT *);

int main(){

	srand((unsigned)time(NULL));
	numberT *Array = (numberT *) malloc(sizeof(numberT) * 20);
	fillArray(Array);
	printArray(Array);
	sortArray(Array);
	puts("After sort:");
	printArray(Array);
	return 0;
}

void fillArray(numberT *Array){
	int i;
	float random;

	for(i = 0; i < 20; i++ ){
		random = ((float) rand()/(float)(RAND_MAX));
		if(random >= 0.5){
			Array[i].typeValue = 'i';
			Array[i].numberValue.intValue = (int) 10 * random;
			continue;
		} 
		Array[i].typeValue = 'd';
		Array[i].numberValue.doubleValue = 10 * random;
	}
}

void printArray(numberT *Array){

	int i;
	for ( i = 0; i < 20; i++){
		if(Array[i].typeValue == 'i')
			printf("%d\n", Array[i].numberValue.intValue);
		else
			printf("%0.2lf\n", Array[i].numberValue.doubleValue);
	}
}

void sortArray(numberT *Array){

	int i,j;
	for (i = 0; i < 19; i++){
		for (j = 0; j < 19; j++){
			
			if((Array[j].typeValue == 'i') && (Array[j+1].typeValue == 'i') && (Array[j].numberValue.intValue < Array[j+1].numberValue.intValue))
				swap(&Array[j],&Array[j+1]);
			if ( ((Array[j].typeValue)  == 'i') && ((Array[j+1].typeValue) == 'd'))
				swap(&Array[j],&Array[j+1]);				
			if(((Array[j].typeValue) == 'd') && ((Array[j+1].typeValue) == 'd') && ((Array[j].numberValue.doubleValue) < (Array[j+1].numberValue.doubleValue)));
			    swap(&Array[j],&Array[j+1]);	
		}
	}
}

void swap(numberT *a, numberT *b){
	//printf("In swap: a.typeValue=%c b.typeValue=%c\n", a->typeValue, b->typeValue);
	numberT key = *a;
	*a = *b;
	*b = key;
}