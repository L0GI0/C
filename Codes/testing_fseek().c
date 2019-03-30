#include <stdio.h>
#include <stdlib.h>

int main(void){

	FILE *source;
	source = fopen("fseek()_test.bin", "wb+");
	if(!source){
		fprintf(stderr,"Cant open file");
		exit(EXIT_FAILURE);
	}
	char c;
	int i;
	int Array[] = { 1, 2, 3, 4, 5, 6, 7};
	fwrite(Array, sizeof(Array)/sizeof(int), sizeof(int), source);
	rewind(source);
	fseek(source, 0, SEEK_END);
	//printf("%ld",ftell(source));
	int zero[] = {0};
	rewind(source);
	for(i = 0; i < 4; i++){
		fwrite(zero, 1, sizeof(int), source);
		fseek(source, sizeof(int) , SEEK_CUR);
	}
	rewind(source);
	fread(Array, 7, sizeof(int), source);
	for(i = 0; i < 7; i++)
		printf("%d \n", Array[i]);
	return 0;
}