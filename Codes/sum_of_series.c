#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

double sumOfSeries(int n,int x);

int main(int argc, char const *argv[]){

	int n,x;
	double result;
	printf("To count sum of x^1 + x^2 ... x^n series");
	printf("Enter n and x respectively: ");
	scanf("%d %d", &n, &x);
	result = sumOfSeries(n,x);
	printf("Result: %.2f",result);
	return 0;
	}

double sumOfSeries(int n,int x){
 	if (n==0)
 		return 1;
 	return (sumOfSeries(n-1,x) + pow(x,n));
}