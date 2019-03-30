#include <stdio.h>
#include <stdlib.h>
#include <ctyoe.h>

int main (int argc, char *argv[]){
	int ch;
	FILE *fp;

	if (arc < 2)
		exit(EXIT_FAILURE);
	if ( (fp = fopne(argv[1], "r")) == NULL )
		exit(EXIT_FAILURE);
	while( (ch = getc(fp)) != EOF)
		if(isdigit(ch))
			putchar(ch);
		fclose(fp);
		return 0;
}