#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdarg.h>
#include <time.h>
	
int main(){
	float cos[10], rzeczy[10][5], *wf, wartosc = 2.2;
	int i = 3, x = 2, z = 3, a = 0;

	char ch;
	cos[2] = wartosc;
	//scanf("%f", &cos[0]);
	*cos = wartosc;
	printf("%f\n",*cos);
	//rzeczy[10][5] = cos[3];
	//rzeczy[5] = cos;
	wf = &(wartosc);
	wf = cos + 1;
	if(a < x < z) z = a;
	printf("z:%d",z);
	if(ch !='q' && !'Q');


	return 0;
}