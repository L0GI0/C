#include <stdio.h>
#include <stdlib.h>


typedef struct list{
	int value;
	struct list *next;
}tlist;

void add_element_at_the_end(tlist **, int);
void print_list(tlist *);
void add_element_at_the_beggining(tlist **, int);
void sorted_add_element(tlist **, int);
tlist *find_element(tlist *, int);
void delete_element(tlist **head, int value);
void reverse_list(tlist **);
/* ************ */
int main(void){
	int i;
	tlist *head = NULL;
	int values[] = { 2, 6, 10, 23, 21, 50, 21, 44};
	for(i = 0; i < sizeof(values)/sizeof(*values); i++)
		sorted_add_element(&head, values[i]);
	print_list(head);
	tlist *found = find_element(head, 50);
	putchar('\n');
	if(found)
		printf("There is element with value %d\n", found->value);
	printf("Deleting element wiht value %d\n", 50);
	delete_element(&head, 50);
	print_list(head);
	printf("Reversing the list\n");
	reverse_list(&head);
	print_list(head);

	
return 0;
}
/* ************ */
void add_element_at_the_end(tlist **head, int value){

	tlist *new = (tlist *)malloc(sizeof(tlist));
	new->value = value;
	new->next = NULL;
	if(!(*head)){
		(*head) = new;
		return;
	}
	tlist *tmp = (*head);
	while(tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void print_list(tlist *tmp){

	while(tmp){
		printf("%d ", tmp->value);
		tmp = tmp->next;
	}
	putchar('\n');
}

void add_element_at_the_beggining(tlist **head, int value){

	tlist *new = (tlist *) malloc(sizeof(tlist));
	new->value = value;
	new->next = (*head);
	(*head) = new;

}

void sorted_add_element(tlist **head, int value){

	tlist *new = (tlist *) malloc(sizeof(tlist));
	new->value = value;
	if(!(*head) || (*head)->value > value){
		new->next = (*head);
		*head = new;
		return;
	}
	tlist *tmp = *head, *prev = NULL;
	while(tmp && tmp->value < value){
		prev = tmp;
		tmp = tmp->next;}
		if(!tmp){
			prev->next = new;
			new->next = NULL;
		}
		else{ 
			prev->next = new;
			new->next = tmp;
			}
}

tlist *find_element(tlist *head, int value){

	while(head && head->value != value){
		head = head->next;
	}
	if(!head){
		fprintf(stderr,"There is no element with value %d\n", value);
		return NULL;
	}
	return head;
}

void delete_element(tlist **head, int value){

	if(!(*head)){
		fprintf(stderr, "The list is empty\n");
		return;
	}
	tlist *temp = *head;
	if ((*head)->value == value){
		*head = (*head)->next;
		free(temp);
		return;}
	tlist *prev = NULL;
	while(temp && temp->value != value){
		prev = temp;
		temp = temp->next;
	}	
	if(!temp){
		fprintf(stderr,"There is no such element\n");
		return;
	}
	else{
		prev->next = temp->next;
		free(temp);
	}

}

void reverse_list(tlist **head){

	tlist *temp, *prev = NULL;
	while(*head){
		temp = (*head)->next;
		(*head)->next = prev;
		prev = *head;
		(*head) = temp;
	}
	*head = prev;
}