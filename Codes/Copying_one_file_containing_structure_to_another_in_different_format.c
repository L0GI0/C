/* Copies bin source file to target one, source file is containing data about rectangle,
data is saved to another file in different format, file names are passed as arguments while executing a program*/
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdarg.h>

struct pros {double wymiary[2];
			 double p_pr;};

int main(int argc, char const *argv[]){
	
	struct pros buffer;
	int number=0;
	FILE *source, *target;

	if(argc < 3){
		puts("Invalid input");
		exit(EXIT_FAILURE);
	}

	source = fopen(argv[1],"rb");
	if(source == NULL){
		fprintf(stderr,"Cant open a %s file",argv[1]);
		exit(EXIT_FAILURE);
	}
	target = fopen(argv[2],"wb");
	if(target == NULL){
		fprintf(stderr,"Cant open a %s file",argv[2]);
		exit(EXIT_FAILURE);
	}	

		
	while(fscanf(source,"%lf %lf %lf", &buffer.wymiary[0], &buffer.wymiary[1], &buffer.p_pr) == 3){
		fprintf(target,"numer = %d a = %0.1lf b = %0.1lf pole = %0.1lf\n",number++, buffer.wymiary[0], buffer.wymiary[1], buffer.p_pr);
	}

	fclose(source);
	fclose(target);
	return 0;
}