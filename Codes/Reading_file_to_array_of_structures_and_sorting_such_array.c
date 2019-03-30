#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dane { char marka[20]; int rocznik, przebieg;};
struct autko {struct dane mobile; int cena;};
int compare(const void *, const void *);

int main(void){
	int i = 0, lines = 0;
	char buf;
	FILE *source;
	source = fopen("auto.bin","rb");
	if(!source){
		printf("Cant open a file");
		exit(EXIT_FAILURE);
	}
	while( (buf = fgetc(source)) != EOF){
		if(buf == '\n')
		lines++;
	}
	fseek(source, 0L, SEEK_SET);
	struct autko *oferta = malloc(sizeof(struct autko) * lines);
	while (i <= lines && fscanf(source,"%s %d %d %d", oferta[i].mobile.marka, &oferta[i].mobile.rocznik,
	 &oferta[i].mobile.przebieg, &oferta[i].cena) == 4){
		i++;
	}
	printf("%-10s %-8s %-8s %-8s \n","Marka","Cena","Rocznik","Przebieg");
	for ( i = 0; i < lines; i++)
		printf("%-10s %-8d %-8d %-8d \n", oferta[i].mobile.marka, oferta[i].cena, oferta[i].mobile.rocznik, oferta[i].mobile.przebieg);
	qsort(oferta, lines, sizeof(struct autko), compare);
	puts("After sorting:");
	printf("%-10s %-8s %-8s %-8s \n","Marka","Cena","Rocznik","Przebieg");
	for ( i = 0; i < lines; i++)
		printf("%-10s %-8d %-8d %-8d \n", oferta[i].mobile.marka, oferta[i].cena, oferta[i].mobile.rocznik, oferta[i].mobile.przebieg);
}

int compare(const void *_a, const void *_b){

	struct autko *a = (struct autko *)_a;
	struct autko *b = (struct autko *)_b;

	if(strcmp(a->mobile.marka, b->mobile.marka))
		return strcmp(a->mobile.marka, b->mobile.marka);
	else if(a->mobile.przebieg - b->mobile.przebieg)
		return b->mobile.rocznik - a->mobile.rocznik;
	else if(a->cena - b->cena)
		return a->cena - b->cena;
	else return a->mobile.przebieg - b->mobile.przebieg;
}
