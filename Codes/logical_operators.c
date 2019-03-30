#include <stdio.h>
#define ROZMIAR 10

int main(void){
	
	int x,y,z;
	x=y=z= -1;
	++x || ++y && z--;
	printf("x=%d, y=%d, z=%d \n", x, y, z);// 0,0, -1
	x=y=z=0;
	--x || --y || ++z;
	printf("x = %d, y=%d, z=%d \n", x,y,z);//-1, 0, 0;
	x=y=z= -1;
	++x && --y || ++z;
	printf("x=%d, y=%d, z=%d \n", x,y,z);//0,-1,0
	return 0;}