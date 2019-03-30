#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdarg.h>


struct adres{
	char ulica[21];
	int nrdomu;
};

struct employee{
	char nazwisko[21];
	int wiek;
	struct adres adresy[3];
}pracownik2;

int main(int argc, char const *argv[])
{
	
	struct employee pracownik = {"Smith", 21, {{"Biesiadki", 74},{"Reymonta", 17},{"Sydney", 1}}};
	printf("%s, %d, %s, %d\n", pracownik.nazwisko, pracownik.wiek, pracownik.adresy[2].ulica, pracownik.adresy[1].nrdomu);
	
	strcpy(pracownik2.nazwisko,"Clarke");
	pracownik2.wiek = 17;
	strcpy(pracownik2.adresy[0].ulica,"Somewhere");
	strcpy(pracownik2.adresy[1].ulica,"With me");
	strcpy(pracownik2.adresy[2].ulica,"Forever Happy");
	pracownik2.adresy[0].nrdomu = 1;
	pracownik2.adresy[1].nrdomu =  2;
	pracownik2.adresy[2].nrdomu = 3;

	printf("%s, %d, %s, %d", pracownik2.nazwisko, pracownik2.wiek, pracownik2.adresy[2].ulica, pracownik2.adresy[1].nrdomu);
	strcmp(pracownik2.nazwisko,"Clarke");



	return 0;
}