#include <stdio.h>

int main(){
	FILE *fp;
	char ch;
	int i = 1;
	fp = fopen("myfile.c", "r");
	while((ch=getc(fp))!= EOF){
		if(ch = '\n'){
			i++;
		}
	}
	fclose(fp);
	return 0;
}