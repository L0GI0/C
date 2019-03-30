#include <stdio.h>
#include <stdlib.h>

int toInt(char * binString);

int main(){
	int val;
	char * pbin = "10000001";
	val = toInt(pbin);
	printf("%s is %d",pbin, val);
}

int toInt(char * binString){
	int i = 0;
	int val = 0;
	int binVal = 128;
	while(binString[i]){
			if(binString[i] == '1'){
				val |= binVal;
			}
			binVal >>= 1;
			i++;
	}
	return val;
}