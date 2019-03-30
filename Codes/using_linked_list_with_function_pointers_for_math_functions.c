#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct lista_trig{
	double (*function)(double);
	char function_name[31];
	struct lista_trig *next;
};

void dodaj (struct lista_trig **, char *function_name, double (*function)(double));
void wypisz(struct lista_trig *, double wartosc_kata);
void zwolnij (struct lista_trig **);

int main(void){

	struct lista_trig *head = NULL;
	char fun_name[][4] = {"sin", "cos", "tan"};
	double(*fun_wsk[])(double) =   { sin, cos, tan};
	int i;
	for( i = 0; i<3; i++)
		dodaj(&head, fun_name[i], fun_wsk[i]);

	double deg_val = 0.;

	while(deg_val < 3)
		wypisz(head, 30 * deg_val++);
	zwolnij(&head);

	return 0;
}

void dodaj (struct lista_trig **head, char *function_name, double (*function)(double)){

	struct lista_trig *new = (struct lista_trig *) malloc (sizeof(struct lista_trig));
	strcpy(new->function_name, function_name);
	new->function = function;
	if(!(*head) || (strcmp((*head)->function_name, function_name)) > 0){
		new->next = (*head);
		(*head) = new;
		return;
	}
	struct lista_trig *tmp = *head;
	while( tmp->next && strcmp(tmp->function_name, function_name) < 0)
		tmp = tmp->next;
	if(!(tmp->next))
		tmp->next = new;
	else{
		new->next = tmp->next->next;
		tmp->next = new;
	}
}

void wypisz(struct lista_trig *list, double wartosc_kata){

	while(list){
		printf("%s(%.2lf) = %.2lf \n", list->function_name, wartosc_kata, list->function(wartosc_kata));
		list = list->next;
	}
}

void zwolnij (struct lista_trig **head){

	struct lista_trig *temp = *head;
	while(*head){
		temp = *head;
		*head = (*head)->next;
		free(temp);
	}
	*head = NULL;
}
