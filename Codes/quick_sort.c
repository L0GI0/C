#include <stdio.h>
#include <string.h>
#include <stdlib.h>

	int compare_score_desc(const void* score_a, const void* score_b){
		int a = *(int*)score_a;
		int b = *(int*)score_b;
		return b - a;
	}

	int compare_names(const void* a, const void* b){
		char** sa = (char**)a;
		char** sb = (char**)b;
		return strcmp(*sa,*sb);
	}


int main(){
	int scores[] = {543, 323, 32, 544, 11, 3, 123};
	int i;
	qsort (scores, 7, sizeof(int), compare_score_desc);
	puts("These are the scores in order:");
	for (i = 0; i < 7; i++){s
		printf("Score = %i\n", scores[i]);
	}
	char *names[] = {"Karen", "Mark", "Brett", "Molly"};
	qsort (names, 4, sizeof(char*), compare_names);
	puts("these are are the names in order:");
	for(i = 0; i < 4; i++){
		printf("%s\n", names[i]);
	}
	return 0;
}