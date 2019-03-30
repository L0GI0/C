#include <stdio.h>
#include <stdlib.h>

struct mys{
	int a;
	float fa[]; // flexible array component
};

int main(void){

	//allocating memory for structure with examplary flexible component as 
	// array of 10 floats
	struct mys *p = malloc(sizeof(struct mys) + 10 * sizeof(float)); 
}