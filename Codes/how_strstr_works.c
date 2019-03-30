#include <stdio.h>
#include <string.h>

int main(){
	char s0[]="dysfunctional";
	char s1[]="fun";
	//strstr(string0,string1) returns true if string1 if found 
	// in string 0, or 0 otherwise
	if(strstr(s0,s1))
			puts("I found the fun in dysfunctional");
}
