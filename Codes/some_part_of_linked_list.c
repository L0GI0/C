#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct node{
	int data;
	struct node *next;
} nodeInst;

nodeInst * addNodeAtTheEnd(nodeInst *, int);
void printList(nodeInst *);
struct node * delete_node(struct node** head, int val);
struct node * corobi(struct node *ptr);

int main(int argc, char const *argv[]){
	nodeInst * head = malloc(sizeof(nodeInst));
	head = addNodeAtTheEnd(head, 2);
	head = addNodeAtTheEnd(head, 3);
	head = addNodeAtTheEnd(head, 4);
	head = addNodeAtTheEnd(head, 5);
	head = delete_node(&head, 2);
	puts("Print list: ");	
	printList(head);
	head = corobi(head);
	puts("Print list: ");	
	printList(head);
	return 0;
}


nodeInst *addNodeAtTheEnd(nodeInst *pointer, int value){

	nodeInst *tmp = pointer;
	while(tmp->next)
		tmp = tmp->next;
	tmp->next = malloc(sizeof(nodeInst));
	tmp->data = value; 
	return pointer;
}

void printList(nodeInst *pointer){
	while(pointer->next){
		printf("%d\n", pointer->data);
		pointer = pointer->next;}
	}


struct node * delete_node(struct node** head, int val){
	struct node * cur, *prev;
	for(cur = *head,  prev = NULL;cur!=NULL && cur->data !=val ;
		prev = cur, cur = cur->next );
		printf("Cur in delete_node: %d\n", cur->data);
		if(!cur){
			return *head;  //wartosc val nie ma na liscie
			puts("test1");
		}
		if(!prev){
			// here -> has higher precedence that * so parantheses are madtatory in this case
			*head = (*head)->next; // wartosc val znajduje sie na poczatku listy
			puts("test2");
		}
		else  {
			cur = cur->next->next; //wartosc val nie znajduje sie na poczatku listy
			puts("test3");
		}
		return *head; //?
	} 	

	struct node * corobi(struct node *ptr){
		struct node *temp1;
		struct node * temp2 = NULL;
		while(ptr->next != NULL){
			temp1 = ptr->next;
			ptr->next = temp2;
			temp2 = ptr;
			ptr = temp1;
		}
		return temp2;
	}