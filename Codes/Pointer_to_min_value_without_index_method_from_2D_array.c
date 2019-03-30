#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10000

int *tab_min(int(*)[3], int, int);
int A[][3] = {2,2,3,4,5,3,9,10,11,[1][2] = 8};

int main(void){

		int *pointer_to_min;
		pointer_to_min = tab_min(A,3,3);
		if(pointer_to_min)
			printf("Min value : %d", *pointer_to_min);
		 

}

int *tab_min(int(*tab)[3], int n, int m){
	int i,j, *min_pointer = *tab;
	for(i = 0; i < n; i++){
		for(j = 0; j < m; j++){
			if(  *(*(tab + i)+j) < (*min_pointer) )
				min_pointer = *(tab + i) +j;
		}
	}
	return min_pointer;
}
