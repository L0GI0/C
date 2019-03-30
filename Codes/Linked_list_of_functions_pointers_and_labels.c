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

void printValuesOfDegree(struct functionList *list, double );
void add (struct functionList **list, const char *functionLabel, double(*pointerToFunction)(double));
void freeList(struct functionList **list);

int main(){
	struct functionList *head = NULL;
	char fun_name[][4] = { "sin", "cos", "tan"};
	double (*fun_ptr[3])(double) = {sin, cos, tan};

	int i;

	for(i = 0; i < 3; i++)
		add(&head,fun_name[i],fun_ptr[i]);

	double deg_val = 0;


	while(deg_val <= 2)
		printValuesOfDegree(head, deg_val++ * 30);

	freeList(&head);
	return 0;
}

void add (struct functionList **list, const char *functionLabel, double (*pointerToFunction)(double)){

	struct functionList *new = malloc(sizeof(struct functionList));
	new->pointer = pointerToFunction;
	strncpy(new->functionLabel,functionLabel,30);
	new->next = NULL;
	
	if(*list == NULL || (strcmp((*list)->functionLabel,functionLabel)) > 0 ){
		new->next = *list;
		*list = new;
		return;
	}
	struct functionList *tmp = *list;
	while(tmp->next && strcmp(tmp->next->functionLabel,functionLabel) < 0 )
		tmp = tmp->next;
	new->next = tmp->next;
	tmp->next = new;

}


void printValuesOfDegree(struct functionList *list, double degree){

	while(list){
		printf("%s(%lf) = %lf \n",list->functionLabel,degree,(list->pointer)(degree));
		list = list->next;
	}	
}

void freeList(struct functionList **list){

	struct functionList *current = NULL;
	while((*list)){
		current = *list;
		*list = (*list)->next;
		free(current);
	}
	*list = NULL;
}
