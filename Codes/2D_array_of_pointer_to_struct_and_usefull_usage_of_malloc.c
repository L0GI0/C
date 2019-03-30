/*creating 2D array of pointers to structures, scanning  values "dlugosc" to each structure using 
asigned pointers from created array, then using function random_string to create string of lenght "dlugosc"
for each pointed structure
*/

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdarg.h>


char *stringToReturn;
char *random_string(int value);

struct s {
	unsigned dlugosc;
	char *var;
};

int main(int argc, char const *argv[]){


	int i,j;
	struct s ***a = malloc(3 * sizeof(struct s **));
	
	for(i = 0; i < 3; i++)
		a[i] = malloc(2 * sizeof(struct s*));

	for (i = 0; i < 3; i++)
		for (j = 0; j < 2; j++){
			a[i][j] = malloc(sizeof(struct s));
			puts("Podaj dlugosc: ");
			scanf("%d", &(a[i][j]->dlugosc));
			a[i][j]->var = random_string(a[i][j]->dlugosc);  
		}
		//printing strings
		for (i = 0; i < 3; i++)
			 for (j = 0; j < 2; j++)
				puts(a[i][j]->var);

	puts("Freeing memory");
		for(i = 0; i < 3; i++){
			for(j = 0; j < 2; j++)
				free(Array[i][j]);
			}
		for(i = 0; i < 3; i++)
			free(Array[i]);
		free(Array);;


}

char * random_string(int value){

	char *string = malloc(value *sizeof(char)); //these allowes you to create variable length
	//string, moreover this string is allocated at chap which allowes you to 
	// return it without error 'function returning local variable', it will treat
	// this value as . 
	int i;

	for (i = 0; i < value; i++){
		string[i] = 'a' + (rand()%('z' - 'a'));
	}
	return string;
}
