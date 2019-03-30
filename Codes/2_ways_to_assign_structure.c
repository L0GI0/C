#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct location{
	char ulica[31];
	int nrdomu;
}loc;

typedef struct employee{
	char nazwisko[31];
	int wiek;
	loc adresy[3];
}emp;

int main(void){

	emp pracownik;
	strncpy(pracownik.nazwisko, "Pabjan", 31);
	pracownik.wiek = 21;
	strncpy(pracownik.adresy[2].ulica,  "Reymonta 17", 31);
	pracownik.adresy[1].nrdomu = 121;
	printf("%s %d %s %d\n", pracownik.nazwisko, pracownik.wiek, pracownik.adresy[2].ulica, pracownik.adresy[1].nrdomu);

	pracownik = (emp ){ "Smykowski", 22, {{"Empty", 0}, {"Empty", 0}, {"Reymonta", 121}}};

	printf("%s %d %s %d\n", pracownik.nazwisko, pracownik.wiek, pracownik.adresy[2].ulica, pracownik.adresy[1].nrdomu);

	return 0;
}