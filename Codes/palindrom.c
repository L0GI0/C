#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int is_palindrome(char *str)
{
    int i;
    for(i = 0; i < strlen(str)/2; i++){
    	printf("%c  %c \n", tolower(str[i]), tolower(str[strlen(str) - i - 1]));
        if( tolower(str[i]) != tolower(str[strlen(str) - i - 1]))
           return 0;
    }
           
    return 1;           
}

#ifndef RunTests
int main()
{
    char *str = "deleveled";
    printf("%d", is_palindrome(str));
}
#endif