#include <stdio.h>
#include <stdlib.h>

struct adres{
	char ulica[31];
	int nrdomu;
};



struct pracownicy{
	char nazwisko[31];
	int wiek;
	struct adres adresy[3];
};


int main(void){

//1st approach
	/*
	puts("Podaj nazwisko");
	scanf("%s", pracownik.nazwisko);
	puts("Podaj wiek");
	scanf("%d", &pracownik.wiek);
	puts("Podaj ulice");
	scanf("%s", pracownik.adresy[2].ulica);
	puts("Podaj nr. domu");
	scanf("%d", &pracownik.adresy[1].nrdomu);


	printf("%s\n", pracownik.nazwisko);
	printf("%d\n", pracownik.wiek);
	printf("%s\n", pracownik.adresy[2].ulica);
	printf("%d\n", pracownik.adresy[1].nrdomu);
	*/

//2nd approach

	struct pracownicy pracownik = {"Pabjan", 21, {{"Biesiadki", 1},{"Krakow", 2},{"Pandora", 3}}};
	printf("%s\n", pracownik.nazwisko);
	printf("%d\n", pracownik.wiek);
	printf("%s\n", pracownik.adresy[2].ulica);
	printf("%d\n", pracownik.adresy[1].nrdomu);

}