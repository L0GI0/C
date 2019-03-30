#include <stdio.h>
// This contains the values for the integer type like int and char
#include <limits.h>
// This contains the value for floats and doubles
#include <float.h>

int main(){
	
	printf("The value of INT_MAX is %i\n", INT_MAX);
	printf("The value of INT_MIN is %i\n", INT_MIN);
	printf("An int takes %i bytes\n", sizeof(int));

	printf("The value of FLT_MAX is %f", FLT_MAX);
	printf("The value of FLT_MIN is %.50f\n", FLT_MIN);
	printf("A float takes %i bytes \n", sizeof(float));

	return 0;
}