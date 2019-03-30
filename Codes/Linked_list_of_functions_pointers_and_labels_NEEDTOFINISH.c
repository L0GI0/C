#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdarg.h>
#include <time.h>

struct functionList{

	struct functionList *next;
	double (*pointer)(double);
	char functionLabel[31];
}list;

void printList(struct functionList *list);
struct functionList* add (struct functionList *list, const char *functionLabel, double(*pointerToFunction)(double));
double function1(double );
double function2(double );
double function3(double );
double function4(double );
double function5(double );
int main(){
	struct functionList *head = malloc(sizeof(struct functionList));
	head = add(head,"aa",function1);
	head = add(head,"zz",function2);
	head = add(head,"gg",function3);
	head = add(head,"uu",function4);
	head = add(head,"xx",function5);
	printList(head);
	
	return 0;
}

struct functionList* add(struct functionList *list, const char *functionLabel, double(*pointerToFunction)(double)){

	struct functionList *tmp = list;
	struct functionList *previous = NULL;
	while(tmp->next  && (strcmp(functionLabel,tmp->functionLabel)) > 0){
		tmp = tmp->next;
		previous = tmp;
	}
	struct functionList * new = malloc(sizeof(struct functionList));
	if (tmp->next && previous){
		previous->next = new;
		new->next = tmp;
	}
	else if(tmp->next){
		new->next = list;
		new->pointer = pointerToFunction;
	    strncpy(new->functionLabel, functionLabel,30);
	    return new;
	}
	else{
	tmp->next = new;
	new->pointer = pointerToFunction;
	strncpy(new->functionLabel, functionLabel,30);
	return tmp;
	}
	new->pointer = pointerToFunction;
	strncpy(new->functionLabel, functionLabel,30);
	return list; 
}

double function1(double value){
	return 0;
}

double function2(double value){
	return 0;
}

double function3(double value){
	return 0;
}

double function4(double value){
	return 0;
}

double function5(double value){
	return 0;
}

void printList(struct functionList *list){

	struct functionList *tmp  = list->next;
	while(tmp){
		printf("%s\n",tmp->functionLabel);
		tmp = tmp->next;
	}	
}