#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float *createArray();
void printArray(float *);
int main(void){
int i = 0;
float bufor;
srand((unsigned)time(NULL));
float *Array = createArray();
//yyprintArray(Array);
FILE *binaryFile, *textFile;
if(!(binaryFile = fopen("binaryFile.bin","wb"))){
	puts("Cant open binaryFile.bin file");
	exit(EXIT_FAILURE);
}
if(!(textFile = fopen("textFile.txt","w"))){
	puts("Cant open textFile.txt file");
	exit(EXIT_FAILURE);
}
	//entering data to binary file
/*
	while( i < 100 && fprintf(binaryFile,"%f ", Array[i])){
		if(!i%10)
			fprintf(binaryFile,"\n");
		i++;
	}
	*/
	fwrite(Array,sizeof(float), 100, binaryFile);
	i = 0;
 	//entering data to txt file
 	while( i < 100 && fprintf(textFile,"%f ",Array[i]) ){
 		if(!i%10)
 			fprintf(textFile,"\n");
 		i++;
 	}
 	printf("Length of binary file is %ld\n", ftell(binaryFile));
 	printf("Length of text file is %ld\n", ftell(textFile));
 	fclose(binaryFile);
 	fclose(textFile);
 	
/*
 	fscanf(binaryFile,"%f", &bufor);
 	printf("%0.2f", bufor);
 	*/
 	/*
 	puts("Binary file: ");
 	while(fscanf(binaryFile,"%f", &bufor) != EOF){
 		printf("%0.2f ", bufor);
 	}
 	*/

 	if(!(binaryFile = fopen("binaryFile.bin","rb"))){
	puts("Cant open binaryFile.bin file");
	exit(EXIT_FAILURE);
}
if(!(textFile = fopen("textFile.txt","r"))){
	puts("Cant open textFile.txt file");
	exit(EXIT_FAILURE);
}
 	putchar('\n');
 	puts("Binary file: ");
 	float binaryFileContent[100];
 	fread(binaryFileContent, sizeof(float), 100, binaryFile);
 	for (i = 0; i < 100; i++)
 		printf("%0.2f ", binaryFileContent[i]);

 	putchar('\n');
 	putchar('\n');
 	puts("Text file: ");
 	while(fscanf(textFile,"%f", &bufor) != EOF){
 		printf("%0.2f ", bufor);
 	}
 	close(binaryFile);
 	close(textFile);
 	//setting every element with index devided by 5 to 0.0
 	if(!(binaryFile = fopen("binaryFile.bin","rb+"))){
 		puts("Cant open binary file");
 		exit(EXIT_FAILURE);
 	}
	 	
 	float zero[] = {0};
 	for(i = 0; i < 100; i += 5){
 		fseek(binaryFile, 4 * sizeof(float),SEEK_CUR);
		fwrite(zero,sizeof(float), 1, binaryFile);	
	}
    putchar('\n');
    rewind(binaryFile);
    fread(binaryFileContent,sizeof(float), 100, binaryFile);
    puts("After changing every element value with index devided by 5 to 0");
    for(i = 0; i < 100; i++)
    	printf("%0.2f ", binaryFileContent[i]);
}

float *createArray(){

	int i;
	float *Array = (float *) malloc(sizeof(float) * 100);
	for (i = 0; i < 100; i++){
		Array[i] = (((float)rand())/((float) RAND_MAX)) * 100;
	}

	return Array;
}

void printArray(float *Array){

	int i;
	for(i = 0; i < 100; i ++){
		printf("%0.2f ", Array[i]);
		if(!i%10)
			putchar('\n');
	}
	putchar('\n');
}