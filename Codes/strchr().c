#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
	int counter = 1;
	char string[] = "Random string for exercise purpose";
	char *pch = strchr(string, 's');
	while(pch){
		printf("%d appearance of %c is as %ld character\n", counter, *pch, pch-string +1);
		printf("%s\n", pch);
		pch = strchr(pch + 1, 's');
		counter++;	
	}

}
