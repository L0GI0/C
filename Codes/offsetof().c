#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
		//how many bytes
struct cic {
char a ; // 1
int b ; // 4
char c ; /* 1 */ };

struct icc {
int b ; // 4
char a ; // 1
char c ; // 1  
char d /* 1 */};

struct cci {
char a ; // 1
char c ; // 1
int b ; /* 4 */ }z;


int main(void){

	printf("%lu\n", sizeof(struct cic));
	printf("%lu\n", sizeof(struct icc));
	printf("%lu\n", sizeof(struct cci));

	printf("%p %p %p \n", &z.a, &z.c, &z.b);
	printf("cci\n");
	printf("a=%lu\n", offsetof(struct cci, a));
	printf("b=%lu\n", offsetof(struct cci, b));
	printf("c=%lu\n", offsetof(struct cci, c));
	printf("icc\n");
	printf("a=%ld\n", offsetof(struct icc,a));
	printf("b=%ld\n", offsetof(struct icc,b));
	printf("c=%ld\n", offsetof(struct icc,c));
	printf("d=%ld\n", offsetof(struct icc,d));
	printf("cic\n");
	printf("a=%lu\n", offsetof(struct cic,a));
	printf("b=%lu\n", offsetof(struct cic,b));
	printf("c=%lu\n", offsetof(struct cic,c));


}