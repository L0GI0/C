#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct s{
	unsigned dlugosc;
	char *var;
};

char *random_string(int );

int main(void){

	int i, j, k = 0;
	int tab[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
	struct s ***Array = malloc (sizeof(struct s***) * 3);
	for(i = 0; i < 3; i++)
		Array[i] = malloc(sizeof(struct s**) * 4);
	for(i = 0; i < 3; i++)
		for(j = 0; j < 4; j++){
			Array[i][j] = malloc(sizeof(struct s*));
			Array[i][j]->dlugosc = tab[k++]; 				
			Array[i][j]->var = random_string(Array[i][j]->dlugosc);
		}
		for(i = 0; i < 3; i++){
			for(j = 0; j < 4; j++){
				printf("%s\n", Array[i][j]->var);
			}
		}



	for(i = 0; i < 3; i++)
		for(j = 0; j < 4; j++)
			free(Array[i][j]);
	for(i = 0; i < 3; i++)
		free(Array[i]);
	free(Array);



	return 0;
}

char *random_string(int length){

	int i;
	char *string = malloc(length);
	for(i = 0; i < length - 1; i++)
		string[i] = 'a' + rand()%26;
	string[length - 1] = '\0';

	return string;
}
