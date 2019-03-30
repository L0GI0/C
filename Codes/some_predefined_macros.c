#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void myfunk(char *str);

#define CHECK_ZERO(div) \
if(div == 0)\
	printf("***Dzielenie przez ZERO w linii \
		%d w pliku %s ***\n", __LINE__, __FILE__)



#line 100 
int main(void){
	printf("%d\n", __LINE__);
	return 0;

	int j=0, i=1;
	//CHECK_ZERO(j);
	int k=i/j;
	myfunk("string");
	printf("%s", __func__);	
}

void myfunk(char *str){
	printf("inside functn %s", __func__);
}