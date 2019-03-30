#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
	int i;
	char string1[] = "String to ,,, compare";
	char string2[] = "String to ... compare";
	printf("%d \n",strcmp(string1, string2));
	printf("%d \n",memcmp(string1, string2, sizeof(string1)));
	memset(string1 + 10, '.', 3);
	printf("%s\n", string1);
	printf("%d \n",strcmp(string1, string2));
	printf("%d \n",memcmp(string1, string2, sizeof(string1)));
	//example which shows that memset is useable only for character arrays
	// because memset copies specified value (converted to type unsigned char)
	// which takes only 1 byte in memory, t o the first specified amount of bytes
	// pointer to character array, int ussualy takes 4 bytes so following code 
	// wont work properly
	int Array1[] = {1, 2, 2};
	int Array2[] = {1, 2, 3};
	printf("%d \n", memcmp(Array1,Array2, sizeof(int) * 3));
	memset(Array1 + 2, 3, sizeof(int));
	for(i = 0; i < 3; i++)
		printf("%d ", Array1[i]);
	printf("%d \n", memcmp(Array1,Array2, sizeof(int) * 3));
	Array1[2] = 3;
	for(i = 0; i < 3; i++)
		printf("%d ", Array1[i]);
	printf("%d \n", memcmp(Array1,Array2, sizeof(int) * 3));
}