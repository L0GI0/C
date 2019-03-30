#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *proc_1(char s[], char c){
		int i;
		for ( i = 0; s[i] != '\0'; i++)
			if( s[i] == c)
				return &s[i];
			return NULL;
}

char *proc_2(char s[], char c){
	while(*s != '\0')
		if(s && *s++ == c)
			return s--;
	return NULL;
}

int main(void){
	char *ptr1, *ptr2;
	ptr1 = proc_1("abcdefg", 'a');
	ptr2 = proc_2("abcdefg", 'a');
	if(ptr1)
	printf("ptr1: %s\n", ptr1);
	if(ptr2)
	printf("ptr2: %s\n", ptr2);
}

