#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
	int lines = 0, char_count = 0;
	int characters[26] = {0};
	char c;
	while(scanf("%c", &c) == 1){
		if(c != '\n')
		char_count++;
		if( c >= 65 && c <= 90)
			++characters[((int) c) - 65];
		if( c >= 97 && c <= 122)
			++characters[((int) c) - 97];

		if(c == '\n')
			lines++;
	}
	int i;
	char max_char, second_max_char;
	int max = 0, second_max = 0;
	for(i = 0; i < 26; i++)
	{
		if(characters[i] > max){
			max = characters[i];
			max_char = 'a' + i;
		}
		if(characters[i] < max && characters[i] > second_max){
			second_max = characters[i];
			second_max_char = 'a' + i;

		}
		printf("%c occurred %d times \n", 'a' + i, characters[i]);
	}
	printf("There is %d characters in %d lines \n", char_count, lines);
	printf("Most frequent character is %c \n", max_char);
	printf("Second most frequent character is %c \n" , second_max_char);

	return 0;
	}