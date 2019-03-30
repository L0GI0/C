#include <stdio.h>
#include <stdlib.h>

int f1(int (*f)(int)){
	int n=6;
	while((*f)(--n)) n;
	return n;
}

int f2(int n){
	return n*n-6*n+5;
}


int main(void){

	printf("f1(f2) = %db\n", f1(f2));
                                                                                     