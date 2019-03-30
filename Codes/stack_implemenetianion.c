#include <stdio.h>
#include <stdlib.h>

typedef struct stack{
	struct stack *next; 
	int value;
}stackT;

void push(stackT **, int);
void printStack(stackT *elment);
stackT *pop(stackT **element);

int main(void){

	stackT *firstElement = NULL;
	push(&firstElement, 5);
	push(&firstElement, 4);
	push(&firstElement, 7);
	push(&firstElement, 3);
	printStack(firstElement);
	puts("pop");
	stackT *poped1 = pop(&firstElement);
	printStack(firstElement);
	puts("pop");
	stackT *poped2 = pop(&firstElement);
	printStack(firstElement);
	puts("pop");
	stackT *poped3 = pop(&firstElement);
	printStack(firstElement);
	puts("pop");
	stackT *poped4 = pop(&firstElement);
	printStack(firstElement);
	puts("pop");
	stackT *poped5 = pop(&firstElement);
	printStack(firstElement);
	putchar('\n');

	free(poped1);
	free(poped2);
	free(poped3);
	free(poped4);
	free(poped5);

}

void push(stackT **element, int value){

	stackT *new = (stackT *) malloc(sizeof(stackT));
	if(*element == NULL){
		*element = new;
		(*element)->value = value;
		(*element)->next = NULL;
		return;
	}
	new->value = value;
	new->next = *element;
	*element = new;
}

void printStack(stackT *element){

	while(element){
		printf("%d ", element->value);
		element = element->next;
	}
}

stackT *pop(stackT **element){

	if(*element){
		stackT *tmp = *element;
		*element = (*element)->next;
		return tmp;
	}
	else{
		puts("Stack is empty, function will return a NULL value");
		return NULL;
	}
}
