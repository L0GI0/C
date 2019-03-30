// variadic.c -- varaidic marcors 
#include <stdio.h>
#include <math.h>
#define PR(X, ...) printf("Message" #X ": " __VA_ARGS__)

int main(void){
	double x = 48;
	double y;
	y = sqrt(x);
	PR(1, "x = %g\n", x);
	PR(2, "x = %2.f, y = %.4f\n", x, y);
}

/* In the first macro call, X has the value 1, so #X becomes "1". That makes the expansion look like this:
printf("Message 1: x = %g\n", x);

Here's the output: 
Message 1: x = 48
Message 2: x = 48.00, y = 6.9282

Don't forget, the ellipses have to be the last macro agrument

#define WRONK(X, ..., Y) #X #X__VA_ARGX__ #Y // won't work
*/