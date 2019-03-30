#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *proc_1(char s[], char c);
char *proc_2(char * s, char c);


int main(int argc, char *argv[]){

	char string[] = {'a','b','c'};//this is not a string, no end on line sign
	char *str_pointer = string;
	printf("%lu", sizeof(string));
}

