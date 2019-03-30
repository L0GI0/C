/*Reads a file containing some amount of structure "data", each containing array of ints floats and chars,
data is stored in 2D array  */

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdarg.h>
#include <time.h>

struct data {
	int arr_1[10];
	float arr_2[5];
	char arr_3[12];
};
void printArray(struct data **Array);
struct data **fillArray(const char *);
void freeMemory(struct data **);

int main(int argc, char const *argv[]){
	
	const char * fileName = "data.dat";
	struct data **Array;
	Array = fillArray(fileName);
	printArray(Array);
	freeMemory(Array);
	return 0;
}

struct data **fillArray(const char *fileName){

	int i,j = 0,k = 0;
	FILE *sourceFile;
	struct data **Array = malloc(2* sizeof(struct data *));
	for (i = 0; i < 2; i++)
		Array[i] = malloc(3 * sizeof(struct data));



	sourceFile = fopen(fileName,"r");
	if(sourceFile == NULL){
		fprintf(stderr,"Cant open file:%s", fileName);
		exit(EXIT_FAILURE);	
			}
	while(!feof(sourceFile) && j < 2){
		 for (i = 0; i < 10; i++){
			fscanf(sourceFile,"%d",&(Array[j][k].arr_1[i]));
		}
		 for (i = 0; i < 5; i++)
			fscanf(sourceFile,"%f",&(Array[j][k].arr_2[i]));
			

			fscanf(sourceFile,"%11s",Array[j][k].arr_3);			
			k++;
			if(k == 3){
				k = 0;
				j++;
			}
	}
	return Array;
}


void printArray(struct data **Array){

    int i,j = 0,k= 0, structureNumber = 1;
    while(j < 2){
    printf("Int value from %d structure: ", structureNumber);	
    for(i = 0; i < 10; i++)
    	printf("%d ",Array[j][k].arr_1[i]);
    putchar('\n');
    printf("Float values from %d structure: ", structureNumber);
	for(i = 0; i < 5; i++)
    	printf("%.2f ",Array[j][k].arr_2[i]);	
    putchar('\n');
    printf("String from %d structure: ", structureNumber);
    puts(Array[j][k].arr_3);
    putchar('\n');
    k++;
    structureNumber++;
    if(k == 3){
    	k = 0;
    	j++;
    }
    }
}

void freeMemory(struct data **Array){
	int i;
		for (i = 0; i < 2; i++)
		free(Array[i]);
	free(Array);
}
