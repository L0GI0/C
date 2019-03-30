#include <stdio.h>
#include <stdlib.h>


int main(){


	FILE *source1, *source2, *target;

	source1 = fopen("dane1.dat","r");
	source2 = fopen("dane2.dat","r");
	target = fopen("dane_all.dat","w");
	if(!sorce1 || !source2 || !target){
		puts("Cant open all files");
		exit(EXIT_FAILURE);
	}

	


}
