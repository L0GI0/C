#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct person{
	char *name;
	char *lastName;
}person;

typedef struct STUDENT student;

struct STUDENT{
	person data;
	student *next;
	student *prev;
};

student *createElement();
void addAtTheBegginning(student **head);
void printList(student *head);
void addAtTheEnd(student **head);
void backAndForth(student *head);
student *findStudent(student *, const char *);
void deleteElement(student **head, const char *findName);



int main(void){

	student *head = NULL;
	addAtTheBegginning(&head);
	addAtTheBegginning(&head);
	addAtTheBegginning(&head);
	printList(head);
	addAtTheEnd(&head);
	addAtTheEnd(&head);
	addAtTheEnd(&head);
	printList(head);
	puts("Back and forth");
	backAndForth(head);
	student *found = findStudent(head, "to");
	if(found)
	printf("Found student : %s", found->data.name);
	deleteElement(&head,"ten");
	deleteElement(&head,"ten2");
	deleteElement(&head,"ten3");
	printList(head);

}

student *createElement(){
	student *element;
	char bufor[30 + 1];
	char *imie, *nazwisko;
	printf("Podaj imie: ");
	scanf("%s", bufor);
	imie = malloc(sizeof(bufor));
	strcpy(imie, bufor);
	printf("Podaj nazwisko: ");
	scanf("%s", bufor);
	nazwisko = malloc(sizeof(bufor));
	strcpy(nazwisko, bufor);
	element = malloc(sizeof(student));
	element->next = NULL;
	element->prev = NULL;
	element->data.name = imie;
	element->data.lastName = nazwisko; 
	return element;
}

void addAtTheBegginning(student **head){
	
	student *new = createElement();
	if(!*head){
		*head = new;
		return;
	}
	(*head)->prev = new;
	new->next = *head;
	*head = new;
}

void printList(student *head){
	puts("Printing list: ");
	int i=1;
	while(head){
		printf("%d.%s ",i,head->data.name);
		printf("%s \n", head->data.lastName);
		head = head->next;
	}
}

void addAtTheEnd(student **head){

	student *new = createElement();
	if(!*head){
		*head = new;
		return;
	}
	student *temp = *head;
	while(temp->next){
		temp = temp->next;
	}
	temp->next = new;
	new->prev = temp;
}

void backAndForth(student *head){

	student *temp = head;
	student *previous = NULL;
	while(temp){
		printf("%s \n", temp->data.name);
		previous = temp;
		temp = temp->next;
	}
	temp = previous;
	while(temp){
		printf("%s \n", temp->data.name);
		temp = temp->prev;
	}
}

student *findStudent(student *head, const char *findName){

	while(head && strcmp(head->data.name, findName) != 0){
		head = head->next;
	}
	if(!head){
		printf("There is no student with name %s, function will return NULL", findName);
		return NULL;
	}
	else return head;
}

void deleteElement(student **head, const char *findName){


	student *current = findStudent(*head, findName);
	if(!current){
		printf("Cant deleted %s", findName);
		return;
	}

	if(!current->next){
		free(current);
	}
	else if(!current->prev){
		(*head) = (*head)->next;
		free(current);
	}
	else {
		current->prev->next = current->next;
		current->next->prev = current->prev;
		free(current);
	}
}