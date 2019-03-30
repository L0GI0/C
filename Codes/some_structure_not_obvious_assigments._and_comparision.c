#include <stdio.h>
#include <stdlib.h>

struct {
	char tytul[15];
	char autor[15];
	float cena;
	int ilosc;
}pierwsza, druga;
struct ksiazka {
	char tytul[15];
	char autor[15];
	float cena;
	int ilosc;
}trzecia, czwarta;

int main(void){
	int i = 2;
	float f = i;
	printf("%f", f);
	//druga = trzecia;// invalid, one structure can be assigned to another only if they are the same type
	//pierwsza.tytul = druga.tytul; //we should use strcpy
	//trzecia == czwarta; // we cant compare strucutres like this, we need to compare each element separately
	druga.cena = trzecia.ilosc; //ok, int can be assigned to float
	czwarta.cena = pierwsza.cena / trzecia.ilosc;// ok

	return 0;}