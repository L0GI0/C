#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){

	int i=-5,j=0;
	printf("%d\n", !!i + !j);//1 + 1 = 2
	int k;
	i=j=6,k=7;
	printf("%d \n", i-7 && j++ < --k);// 0
	printf("i=%d, j=%d, k=%d\n",i,j,k);// 6,7,6
	int x = 03, y = 02, z =01;
	printf("%d, %d, %d \n", x | y & z, x | y & -z, x ^ y && z);//3, 3, 1
	x = 1;
	printf("G. %d\n", x<<=3);//8
	int l,m;
	i=2, j=3, k=4, l=6, m=1;
	printf("%d %d %d %d\n", i%=j,l=j>k ?++k:k<l? ++m<2:m>2,k,m);// 2, 0, 4, 2
	int n=5, p=9, q;
	float v;
	printf("q = %d x=%f\n", q = p % n + p > n, v = p/n);// 1, 1.000000
	n=10,p=5,q=10;
	int r;
	printf("r = %d p=%d q=%d n=%d\n", r=n==(p=q),p,q,n);
	n=5, p=2, q;
	q=++n==3 && ++p==3;
	printf("n = %d p=%d q=%d ", n,p,q);//6, 2, 0	
	return 0;	
}