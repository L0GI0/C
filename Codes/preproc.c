/* preproc.c -- simple preprocessor examples */
#include <stdio.h>
#define TWO 2
#define OW "Consistency is the last refuge of the unimagina\
tive. - Oscar Wilde" // a backslash contunues a definituon */
					// to the next line
#define FOUR TWO*TWO
#define PX printf("X is %d.\
");
int main(void){
	int x = TWO;
	PX;
	x = FOUR;
	printf(FMT,x);
	printf("%s\n", OW);
	printf("TWO: OW\n");

	return 0;
}