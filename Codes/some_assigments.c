#include <stdio.h>
#include <stdlib.h>

int TAB[7][6];
int (*FF(int k))[2];
char * NAP[] = {"nap1", "nap2", "nap3"};
double T[][2] = {{1.0,1.0},{0.},{2.0,3.0}};

int tab[2][2];


int main(void){
double (*a)[][2];
int (*(*b)(int))[2];
int (*c)[2];
int *d;
int *e;
char *f;
char g;
double (*h)[2];
char **k;


a = &T;
b = FF + 1;
c = FF(9);
d = TAB[2];
e = FF(9)[1];
f = *NAP + 1;
g = *++NAP[1];
h = (double [][2]){1.0, 3.0, 4.0};
k = NAP;
printf("%s \n", f);
printf("%c \n", g);
}       

int (*FF(int k))[2]{
	
	return tab;
}                                        