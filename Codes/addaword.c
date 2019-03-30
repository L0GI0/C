/* addaword.c -- uses fprintf(), fscanf(), and rewind () */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 41

int main(void){
	FILE *fp;
	char words[MAX];

	if((fp = fopen("wordy", "a+")) == NULL){
		fprintf(stdout,"Can't open \"wordy\" file.\n");
		exit(EXIT_FAILURE);
	}

	puts("Enter word to add to the file; press the # key at the begginning of a line to terminante.");
	while((fscanf(stdin,"%40s",words) == 1 ) && (word[0] != '#'))
		fprintf(fp, "%s\n", words);

	puts("File contents: ");
	rewind(fp); /* go back to the beginning of file */
	while (fscanf(fp,"%s",words) == 1)
		puts(words);
	puts("Done!");
	if(fclose(fp) != 0)
		fprintf(stderr,"Error closing file\n");

	return 0;
}