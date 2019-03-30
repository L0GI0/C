#include <stdio.h>
#include <stdlib.h>

struct dane{
	int tab_1[10];
	float tab_2[5];
	char tab_3[12];
}data;

struct dane **read_data(char *);

int main(void){
	int i,j, k;
	struct dane **file_content = read_data("data.dat"); 
	//print array of structure
	for (i = 0; i < 2; i++){
			for(j = 0; j < 3; j++){
			for (k = 0; k < 10; k++)
				printf("%d ",file_content[i][j].tab_1[k]);
			for(k = 0; k < 5; k++)
				printf("%.2f ",file_content[i][j].tab_2[k]);
			
			printf("%s \n", file_content[i][j].tab_3);
			}
		}
}

struct dane **read_data(char *file){

	FILE *data;
	int i,j,k;
	if(!(data = fopen(file, "r"))){
		fprintf(stderr,"Cant ofen %s file", file);
		exit(EXIT_FAILURE);
	}

	struct dane **Array = (struct dane **) malloc(sizeof(struct dane *) * 2);
	for(i = 0; i < 3; i++)
		Array[i] = (struct dane *) malloc(sizeof(struct dane) * 3);

	for (i = 0; i < 2; i++){
		for(j = 0; j < 3; j++){
		for (k = 0; k < 10; k++)
			fscanf(data, "%d", &Array[i][j].tab_1[k]);
		for(k = 0; k < 5; k++)
			fscanf(data, "%f", &Array[i][j].tab_2[k]);
			
		fscanf(data, "%s", Array[i][j].tab_3);
		}
	}
	return Array;
}