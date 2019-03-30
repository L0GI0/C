#include <stdio.h>
#include <stdlib.h>

char *c[] = {"HOOD", "LATE", "RING", "BABY"};
char **cp[] = {c + 3, c + 2, c + 1, c};
char ***cpp = cp + 2;

int main(void){

	printf("%c     %c    %c\n", *(*c + 3), *(*(c) + 4), *(*(c + 1)));
	printf("%p, %p %p", (*(c) + 3), (*(c) + 4)  , *(c + 1));

	return 0;
}
