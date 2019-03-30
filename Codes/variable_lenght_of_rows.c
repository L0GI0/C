#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#define ROWS 5

void prin2D(int **);
const int rows_length[]={3,4,1,6,2};

int main(int argc, char const *argv[])
{
	;
	int i,j;
	int **arr = (int **)malloc(ROWS * sizeof(int *));

	for (i = 0; i < ROWS; i++){
		arr[i] = (int *) malloc(rows_length[i] * sizeof(int));
		for(j = 0; j < rows_length[i]; j++)
			arr[i][j] = rows_length[i];
	}
		printf("%d \n", *(*(arr + 1)));


		puts("--------------------");
		prin2D(arr);
	
	return 0;	}

	void prin2D(int **arr){
		int i,j;

		for (i = 0; i < ROWS; i++){
			for(j = 0; j < rows_length[i]; j++)
				printf("%d ", arr[i][j]);
			putchar('\n');
		}
	}