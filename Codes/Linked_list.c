/* Linked list with basic operations, moreover there is tetPointer function with explains some confusing assigments of pointers by how to make a pointer to a pointer
which always point there where the target pointer is pointing to */
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct tnode {
	int value;
	struct tnode * next;
}node;

void addAtBegginning(node **, int);
void addAtEnd(node **element, int value);
void printList(node *element);
void printList(node *element);
void freeList(node **element);
void sortedAdd(node **element, int value );
node *findElement(node *element, int value);
void deleteElement(node **element, int value);
void testPointer(node **element);
void delete_node(node **head, int val);//exercise function
node *reverse_list(node *head);
void make_periodic_and_reverse(struct tnode **head);


int main(void){

	int i;
	node *root = NULL;
	int listValues[] = {20,21,32,21,12,3,5,2,5,6,2,10,54};
	for (i = 0; i < sizeof(listValues)/sizeof(listValues[0]); i++)
		addAtEnd(&root,listValues[i]);
	printList(root);
	freeList(&root);
	putchar('\n');
	puts("After deleting list: ");	
	printList(root);
	puts("Sorted add: ");
	for (i = 0; i < sizeof(listValues)/sizeof(listValues[0]); i++)
		sortedAdd(&root,listValues[i]);
	printList(root);
	node *located = findElement(root, 50);
	putchar('\n');
	if(located)
		printf("There is element with value %d \n", located->value);
	printf("List after deleting element with value 12\n");
	deleteElement(&root, 12);
	printList(root);

	printf("List after deleting element with value 20\n");
	deleteElement(&root, 20);
	printList(root);
	root = reverse_list(root);
	printf("List after using reverse_list function\n");
	printList(root);
	//make_periodic_and_reverse(&root); 
	//printList(root); // now list is periodic, printing will run infinite loop

}

void addAtBegginning(node **element, int value){

if (*element == NULL){
	*element = malloc(sizeof(node));
	(*element)->value = value;
	(*element)->next = NULL;
	return;
}
 	node *new = malloc(sizeof(node));
 	new->next = *element;
 	*element = new;
 	new->value = value;
}
	
void addAtEnd(node **element, int value){
	if (*element == NULL){
	*element = (node *) malloc(sizeof(node));
	(*element)->value = value;
	(*element)->next = NULL;
	return;
}
	node *tmp = *element;
	while(tmp->next != NULL)
		tmp = tmp->next;
	node *new = (node *) malloc(sizeof(node));
	tmp->next = new;
	new->value = value;
	new->next = NULL;
}

void printList(node *element){

	while(element){
		printf("%d ", element->value);
		element = element->next;
	}
	putchar('\n');
}

void freeList(node **element){
	node *tmp = NULL;
	while(*element){
		tmp = *element;
		*element = (*element)->next;
		free(tmp);
	}
	*element = NULL;
}
	
void sortedAdd(node **element, int value ){

	node *new = (node *) malloc(sizeof(node));
	new->value = value;
	if(*element == NULL || (*element)->value > value){
		new->next = *element;
		*element = new;
		return;
	}
	node *tmp = *element;
	while(tmp->next && tmp->next->value < value){
		tmp = tmp->next;
	}
	new->next = tmp->next;
	tmp->next = new;
}	

node *findElement(node *element, int value){

		while(element && element->value != value)
			element = element->next;
		if(!element){
			printf("Cant find element with value %d, function will return NULL\n", value);
			return NULL;
		}
		return element;
}

void deleteElement(node **element, int value){

	node *tmp = *element, *previous = NULL; 

	if(*element && (*element)->value == value){
			tmp = *element;
			*element = (*element)->next;
			free(tmp);
			return;
	}

	while(tmp && tmp->value != value){
		previous = tmp;
		tmp = tmp->next;
	}
	if(!tmp){
		puts("There is no such element");
		return;
	}
	previous->next = tmp->next;
	free(tmp);
}

void testPointer(node **element){

	node *ptr1, **ptr2;
	ptr1 = *element;
	ptr2 = &ptr1;
	printf("\n(*element)->value = %d | ptr1->value = %d | (*ptr2)->value = %d \n", (*element)->value, ptr1->value, (*ptr2)->value);
	ptr1 = (*element)->next;
	printf("(*element)->value = %d | ptr1->value = %d | (*ptr2)->value = %d \n", (*element)->value, ptr1->value, (*ptr2)->value);
}

void delete_node(node **head, int val){//exercise function
	node *cur, *prev;
	for (cur=*head,prev = NULL; cur && cur->value != val; 
		prev = cur, cur = cur->next);
		if(!cur)
			return;
		if(!prev)
			*head = (*head)->next;
		else
			prev->next = cur->next;
		free(cur);
}


node *reverse_list(node *head){
	node *temp1;
	node *temp2 = NULL;
	while(head!=NULL){
		temp1 = head->next;
		head->next = temp2;
		temp2 = head;
		head = temp1;
	}
	return temp2;
}

void make_periodic_and_reverse(struct tnode **head){

	//reverse
	struct tnode * prev = NULL, *temp2 = NULL, *temp1 = *head;
	while(temp1){
		temp2 = temp1->next;
		temp1->next = prev;
		prev = temp1;
		temp1 = temp2;
	}
	(*head)->next = prev;
	(*head) = prev;
}
