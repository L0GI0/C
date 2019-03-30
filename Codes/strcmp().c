#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char const *argv[]){
	
	printf("%d \n",strcmp("TAK","NIE"));// T has grater value in ASCII table than N, function will return 1
	printf("%d \n ",strcmp("TAK","tak"));// T has lower value that t in ASCII table, function will return -1
	printf("%d \n",strcmp("TAK","TAK"));//T has the same value as T, function will return 0

	return 0;
	}