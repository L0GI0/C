#include <stdio.h>
#include <stdlib.h>

struct foo{
	int m;
	struct {
		float x;
		int n;
	};
};



int main(void){

	struct foo t;
	// direct acces to anonymus strucutre
	t.x = 2.0;
	t.n = 2;
	printf("t.x = %.1f t.n = %d", t.x, t.n );

}