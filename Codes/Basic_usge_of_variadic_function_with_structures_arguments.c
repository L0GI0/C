#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

struct pair {float x; char z;};

char max_chr_flt(int n, ... );

int main(void){

	char sign;
	struct pair Array[4] = {{11.34, 'a'}, {122.0, 'f'}, {10.12, 'x'},{1.67, 'd'}};
	sign = max_chr_flt( 4 , Array[0], Array[1], Array[2], Array[3]);
	printf("sign: %c\n", sign);

}

char max_chr_flt(int n, ...){

	int i;
	char sign;
	float max = 0;
	va_list ap;
	struct pair structure, **pointerToStructure;
	va_start(ap, n);

	for ( i = 0; i < n; i++){
		structure = va_arg(ap, struct pair);
		if ( structure.x > max){
			sign = structure.z;
			max = structure.x;
		}
	}
	return sign;
}
