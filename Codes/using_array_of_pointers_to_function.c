#include <stdio.h>
#include <stdlib.h>

float sum(float*, int);
float multi(float*, int);
float min(float*, int);
float max(float*, int);

float pierwsza[][3] = {1.2, 1.4, 1.6, 1.7, 1.5, 1.4, 1.0, 1.9, 1.1, 1.6, 1.5, 1.4};
char * nazwy[]={"sum", "multi", "min", "max" };
typedef float (*typ_funkcje)(float*, int);
float *fun_fun(float (*fun)(float*, int), float pierwsza[][3]);

int main(void){
	
	int i, j; 
	float *wyniki;
	typ_funkcje funkcje[] = {sum, multi, min, max};
	for (i = 0; i < 4; i++){
		wyniki = fun_fun(funkcje[i], pierwsza);
		for(j = 0; j < 4; j++)
			printf("%s (%d) = %0.2f \n", nazwy[i], j, wyniki[j]);
	}

	return 0;
}

float *fun_fun(float (*fun)(float*, int), float pierwsza[][3]){
	float *wyniki = malloc(sizeof(float) * 4);
	int j;
	for (j = 0; j < 4; j++)
		wyniki[j] = (float) fun(pierwsza[j], 3);
	return wyniki;
}

float sum(float *a, int b){
	int i;
	float result = 0;
	for (i = 0; i < b; i++)
		result += (float)a[i];
	return result;
}
float multi(float *a, int b){
	int i;
	float result = 1;
	for (i = 0; i < b; i++)
		result *= (float) a[i];
	return result;
}
float min(float *a, int b){
	int i; 
	float min = 10000;
	for (i = 0; i < b; i++)
		if(a[i] < min)
			min = a[i];

return min;
}
float max(float *a, int b){
	int i;
	float max = 0;
	for (i = 0; i < b; i++)
		if(a[i] > max)
			max = a[i];
	return max;
}


