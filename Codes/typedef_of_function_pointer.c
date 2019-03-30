#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void fun_fun(float (*fun)(float *, int), float tab[][3]);
float sum(float *, int );
float multi(float *, int );
float min(float *, int );
float max(float *, int );

int main(int argc, char const *argv[])
{	
	int i,j;
	float pierwsza[][3] = {1.2, 1.4, 1.6, 1.7, 1.5, 1.4, 1.0, 1.9, 1.1, 1.6, 1.5, 1.4}; 
	char * nazwy[]={"sum", "multi", "min", "max"};
	typedef float (*typ_funkcje)(float *, int);
	//enum attempt {sum, multi, min, max};
	
	typ_funkcje functions[] = {sum, multi, min, max};
	

	for(i = 0; i < 4; i++ )
		fun_fun(functions[i], pierwsza);

	return 0;

}


void fun_fun(float (*fun)(float *, int), float tab[][3]){
	int i,j;
	
	}



float sum(float a*, int b){

}


float multi(float a*, int b){

}

float min(float a*, int b){

}

float max(float a*, int b){

}