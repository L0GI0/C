#include <stdio.h>
#include <stdlib.h>
#define BUFF 256
int  has_ch(char ch, const char * line);
int main(int argc, char const *argv[])
{
	FILE *fp;
	char ch;
	char *line[BUFF];
	if ( argc != 3 && sizeof(argv[1]) != 1){
		puts("Invalid arguments");
	}
 	ch = argv[1][0];
	if ( (fp = fopen(argv[2], "r")) == NULL) {
			fprintf(stderr, "Can't open specified file %s\n", argv[2]);
			exit(EXIT_FAILURE);
	}

	while( (getc(line,BUF,fp)) =! NULL){
		if(has_ch(ch,line))
			puts(line);
	}
	return 0;
}

has_ch(char ch, const char * line){
	while (*line){
		if ( ch == *line++)
			return 1;
		return 0;
	}
}