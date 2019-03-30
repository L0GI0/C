#include <stdio.h>
#include <stdlib.h>

const int dl_wierszy[]={3,4,1,6,2};
int main(void){
	
	int i,j;
	int **Tablica = (int **)malloc(sizeof(int*) * 5);
	for(i = 0; i < 5; i ++){
		Tablica[i] = (int *)malloc(sizeof(int) * dl_wierszy[i]);
			for(j = 0; j < dl_wierszy[i]; j++)
				Tablica[i][j] = dl_wierszy[i];
	}

	for(i = 0; i < 5; i++){
		for(j = 0; j < dl_wierszy[i]; j++)
			printf("%d ", Tablica[i][j]);
		putchar('\n');
	}

	}