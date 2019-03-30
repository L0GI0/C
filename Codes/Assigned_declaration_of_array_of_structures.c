#include <stdio.h>
#include <stdlib.h>
#define SIZE 31

struct iteminstore{
	int id_nmbr;
	char name[SIZE];
	int on_shelf;
};

int main(void){


	struct iteminstore nvntr[] = {{914, "Printer cable", 57}, {528, "Hard drive", 100},
	 {12, "Mouse", 23}};
	 printf("%s", nvntr[0].name);
	 printf("%s", nvntr[0].name);
	 printf("%s", nvntr[0].name);
}