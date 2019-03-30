#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
	int lines = 0, lines_with_specified_word = 0;
	char buffor[101];
	while(fgets(buffor,101,stdin) && buffor[0] != 'q'){
		if(strstr(buffor,"wagon")){
			printf("%d. %s", lines, buffor);
			lines_with_specified_word++;
		}
		lines++;
	}
	printf("Found %d lines with word \"wagon\" \n", lines_with_specified_word);

	return 0;
}