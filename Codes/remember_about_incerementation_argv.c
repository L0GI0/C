#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]){
	printf("%c", **++argv); //r
	printf("%c", *++argv[1]);//r // cos argv[0] is "raz" now
	return 0;
}