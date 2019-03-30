#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct student{
	char name[31];
	char lastname[31];
	int age;
}stud;

void getPassword(void);
int main(void){

	getPassword();
	FILE* dataBase;
	dataBase = fopen("dataBase.dat","a");
	stud CreateStudent;
	puts("Enter name");
	scanf("%s",CreateStudent.name);	
	puts("Enter lastname");
	scanf("%s",CreateStudent.lastname);
	puts("Enter age");
	scanf("%d",&CreateStudent.age);
	fprintf(dataBase,"%s ",CreateStudent.name);
	fprintf(dataBase,"%s ",CreateStudent.lastname);
	fprintf(dataBase,"%d\n",CreateStudent.age);
	fclose(dataBase);
}

void getPassword(void){
	int i = 1;
	char *password = "gainAccess";
	char bufor[31];
	puts("Enter a password to a data base");
	while(i < 4){
		printf("%d/3 Attempt:", i);
		fscanf(stdin,"%s",bufor);
		if(strcmp(password,bufor) == 0)
			return;
		i++;
	}
	fprintf(stderr,"Wrong password, all avalible attempts used");
	exit(EXIT_FAILURE);
	}

	