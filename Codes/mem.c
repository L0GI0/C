/*mem.c -- using memcpy() and memmove() 
Both of these functions copy n bytes from the location pointed to by s2 to the location pointed
to by s1, and both return the value of s1. The difference between the two, as indicated by the keyword restricted,
is that memcpy() is free to assuma that there is no overlap between the two memory ranges . 
the memmove() function doesn't make that assumption, so copying takes place as if all the bytes are first copied to a temporary buffer
before being copied to the final destination . What if you use memcpy() when there are overlapping ranges ?
The behaviour is undefined maining it might work or it might not. The compiler won't stop you from using the memcpy()
function when you shouldn't, so it's your responsibility to ake sure that rankes aren't overlaping when you
use it / It's just aother part of the programmer's burden.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 10
void show_array(const int ar[], int n);
// remove following if C11_Static_assert not supported
_Static_assert(sizeof(double) == 2 * sizeof(int), "double not twice in size");

int main(){
	int values[SIZE] = {1,2,3,4,5,6,7,8,9,10};
	int target[SIZE];
	double curious[SIZE / 2] = {2.0, 2.0e5, 2.0e10, 2.0e20, 5.0e30};

	puts("memcpy() used: ");
	puts("values (original data): ");
	show_array(values, SIZE);
	memcpy(target, values, SIZE * sizeof(int));
	puts("target (copy of values): ");
	show_array(target, SIZE);

	puts("\nUsing memmove() with overlapping ranges: ");
	memmove(values + 2, values, 5 * sizeof(int));
	puts("values -- elements 0-5 copied to 2-7: ");
	show_array(values, SIZE);

	puts("\nUsing memcpy() to copy double to int: ");
	memcpy(target, curious, (SIZE / 2) * sizeof(double));
	puts("target -- 5 doubles into 10 int positions: ");
	show_array(target, SIZE / 2);
	show_array(target + 5, SIZE / 2);

	return 0;
}

void show_array(const int ar[], int n){
	int i;
	for ( i = 0; i < n; i++)
		printf("%d", ar[i]);
	putchar('\n');
}

/* The last call to memcpy() copies data from a type double array to a type int array.
This shows that memcpy() doesn't know or care about data types; it just copies bytes from one location
to another. (You could, for example, copy bytes from a structure to a character array.) Alseo.
there is no data conversion . If you had a loop doing element-by-element assignemnt, the type double values would
be converted to type int during assignemnt, In this case, the bytes are
copied over "as it," and the program then interprets the bit patterns as if they were type int.
*/