#include <stdio.h>
#include <string.h>

void print_reverse(char *s){
	size_t len=strlen(s);
	printf("%zd",len);
	char *t=s+len-1;
	while(t>=s){
		printf("%c",*t);
		t=t-1;
	}
	puts("");
}

int main(){
	char string[80];
	printf("String to reverse: ");
	fgets(string,80,stdin);
	print_reverse(string);
}