#include <stdio.h>
#include <stdlib.h>

int main(void){

	FILE *source, *text_destination, *binary_destination;
	if(!(source = fopen("double_file.txt","r+"))){
		fprintf(stderr,"Cant open source file");
		exit(EXIT_FAILURE);
	}
	char c;
	int lines = 1;
	while((c = getc(source))!= EOF){
		if(c == '\n')
			lines++;
	}
	printf("lines: %d\n", lines);
	int i = 0;
	rewind(source);
	double *Array1 = (double *)malloc(sizeof(double) * lines);
	double *Array2 = (double *)malloc(sizeof(double) * lines);
	while(fscanf(source, "%lf %lf", &Array1[i], &Array2[i]) == 2 && i < lines){
		++i;
	}
	if(!(text_destination = fopen("text_destination.txt","w+"))){
		fprintf(stderr,"Cant open destination text file");
		exit(EXIT_FAILURE);
	}
	if(!(binary_destination = fopen("binary_destination.bin","wb+"))){
		fprintf(stderr,"cant open destination binary file");
		exit(EXIT_FAILURE);
	}

	puts("Array 1:");
	for(i = 0; i < lines; i++)
		printf("%.2lf\n", Array1[i]);
	puts("Array 2:");
		for(i = 0; i < lines; i++)
		printf("%.2lf\n", Array2[i]);


	for(i = 0; i < lines; i++){
		fprintf(text_destination, "%.2lf", Array1[i]);
	}

	fwrite(Array2, sizeof(double), lines, binary_destination);
	rewind(binary_destination);	
	double *Array3 = malloc(sizeof(double) * lines);
	fread(Array3, sizeof(double), lines, binary_destination);
	for (i = 0; i < lines; i++)
		printf("%.2lf \n", Array3[i]);


	return 0;
}