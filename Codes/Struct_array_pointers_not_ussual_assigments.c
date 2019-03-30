#include <stdio.h>

struct S1 {
	char *s;
	int i;
	struct S1 *sp;};

int main(void){
	static struct S1 a[] = {
		{"abcd", 1, a+1},
		{"efgh", 2, a+2},
		{"ijkl", 3, a}
	};
	struct S1 *p = a;
	printf("%s, %s, %s \n", a[0].s, p->s, a[2].sp->s);                 
	printf("%s, %s, %s \n", ++(p->s), a[(++p)->i].s, a[--(p->sp->i)].s);
	return 0;
}