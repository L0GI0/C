#include <stdio.h>
#include <stdlib.h>
void	print2D(int **,int ,int);
int main(void){
	int **dynamic_two_D;
	int columns,rows;
	puts("Enter number of rows");
	scanf("%d", &rows);
	puts("Enter number of columns");
	scanf("%d", &columns);
	dynamic_two_D = malloc(rows * sizeof(int*));
	for (int i = 0; i < rows; i++)
		dynamic_two_D[i] = malloc(columns * sizeof(int));
	print2D(dynamic_two_D,columns,rows);

	return 0;
}

void print2D(int **array, int columns, int rows){
	int i,j=0

	for (i = 0; i < rows; i++){
		for(j = 0; j < columns; j++){
			printf("%d ",array[i][j]);
		}
		putchar('\n');
	}
}