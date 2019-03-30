#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct string{
	char *str;
	int len;
};

int compare(const void *, const void *);
char *randomString(int length);

int main(){
 	int i;
 	srand((unsigned)time(NULL));
 	struct string ARR[10];
 	for (i = 0; i < 10; i++){
 		ARR[i].len = 3 + rand()%8;
 		ARR[i].str = randomString(ARR[i].len);
 	}
 	for(i = 0; i < 10; i++)
 		printf("%s\n",ARR[i].str);
 	qsort(ARR,10,sizeof(struct string), compare);
 		printf("After sorting array of structure with respect to it's lenght and alphabetically order");
 	for(i = 0; i < 10; i++)
 		printf("%s\n",ARR[i].str);

}

char *randomString(int length){
	int i;
	/*it's enought to make a char pointer, malloc dont delete previous
	//string which char *str pointer from struct string points to,
	//it allocates new one losing acces to previous string, only way to
	 get to previous string is by struct pointer*/
	char *string = malloc(sizeof(char) * length);
	for (i = 0; i < length; i++){
		string[i] = 'A' + rand()%('Z' - 'A') + 1;
	}
	return string;
}

int compare(const void *_a, const void *_b){

	struct string *a = (struct string *)_a;
	struct string *b = (struct string *)_b;

	if((a->len - b->len) != 0)
			return (b->len - a->len);		
	return strcmp(a->str,b->str);	
}
