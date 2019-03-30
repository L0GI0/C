#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

char * proc1(char s[], char c);
char * proc2(char *s, char c);

int main(int argc, char *argv[]){
	char string[] = "Random string for test purpose";
	char c, *pointerToMatchingChar;


	printf("Enter wanted character in string: \"%s\", its adres will be returned\n", string);
	c = getchar();
	pointerToMatchingChar = proc1(string, c);
	putchar(*pointerToMatchingChar);
	pointerToMatchingChar = proc2(string, c);
	puts(" ");
	putchar(*pointerToMatchingChar);
	puts(" ");


	return 0;	
}

char * proc1(char s[], char c){
	int i;
	for( i = 0; s[i] != '\0'; i++)
		if( s[ i ] == c)
			return &s[ i ];
	return NULL;
}

char * proc2(char *s, char c){
	while(*s++){
		printf("*s = %c ", *(s -1));
		if(*(s - 1) == c){
			return s - 1;
		}
			
	}
	return NULL;
}