#include <stdio.h>
#include <stdlib.h>

struct rect{double wymiary[2];
			double r_ar;}rectangle;




int main(int argc, char *argv[]){

	

	if(argc < 3){
		fprintf(stderr, "Invalid input");
		exit(EXIT_FAILURE);
	}

	FILE *source, *destination;

	if(!(source = fopen(argv[1], "rb+"))){
		fprintf(stderr,"Cant open %s", argv[1]);
		exit(EXIT_FAILURE);
	}

	struct rect	Array[] = {{{1, 2}, 2}, {{2, 3}, 6}, {{1, 5}, 5}, {{2, 1}, 2}, {{4, 4}, 16}};
	fwrite(Array, 5, sizeof(struct rect), source);
	fseek(source,0L, SEEK_END);
	int size = ftell(source)/sizeof(struct rect);
	printf("%d\n", size);
	struct rect *Array2 = malloc(sizeof(struct rect) * size);
	rewind(source);
	fread(Array2, 5, sizeof(struct rect), source);
	if(!(destination = fopen(argv[2], "w"))){
	fprintf(stderr,"Cant open %s", argv[2]);
	exit(EXIT_FAILURE);
	}
	int i = 0;
	for(i = 0; i < size; i++)
	fprintf(destination,"%lf %lf %lf \n", Array2[i].wymiary[0], Array2[i].wymiary[1], Array2[i].r_ar);

	
	return 0;
}