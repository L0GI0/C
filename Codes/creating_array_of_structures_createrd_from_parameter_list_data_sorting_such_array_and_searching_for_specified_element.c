#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct osoba {
	char name[31];
	int first_year_of_labour;
	int last_year_of_labour;
};

struct osoba *create_array_of_employees(int argc, char **argv);
void employee_list(struct osoba *, int );
int compare (void const *, void const *);
int compareB (void const *_a, void const *_b);


int main(int argc, char *argv[]){
	int years_of_labour;
	struct osoba *data = create_array_of_employees(argc, argv);
	employee_list(data, argc/3);
	qsort(data, argc/3, sizeof(struct osoba ), compare);
	employee_list(data, argc/3);
 	puts("Enter worked yeras by wanted employee: ");
 	scanf("%d", &years_of_labour);
 	struct osoba *found_employee = bsearch(&years_of_labour, data, argc/3, sizeof(struct osoba), compareB);	
 	if(found_employee)
 		printf("%s worked for %d", found_employee->name, years_of_labour);
 	
	return 0;
}

struct osoba *create_array_of_employees(int argc, char **argv){
	int i, j;
	int emplyees_number = argc/3;
	struct osoba *employee = (struct osoba *) malloc (sizeof(struct osoba ) * emplyees_number);
	for(i = 0, j = 1; i < emplyees_number; i++){
			strcpy(employee[i].name, argv[j++]);
			employee[i].first_year_of_labour = atoi(argv[j++]);
			employee[i].last_year_of_labour = atoi(argv[j++]);
	}
	return employee;
}

void employee_list(struct osoba * employee, int emplyees_number){
	int i;
	putchar('\n');
	for (i = 0; i < emplyees_number; i++){
		printf("%s ", employee[i].name);
		printf("%d ", employee[i].first_year_of_labour);
		printf("%d \n", employee[i].last_year_of_labour);
	}
}

int compare (void const *_a, void const *_b){

	struct osoba *a = (struct osoba *)_a;
	struct osoba *b = (struct osoba *)_b;

	return (a->last_year_of_labour - a->first_year_of_labour) - (b->last_year_of_labour - b->first_year_of_labour);
}

int compareB (void const *_a, void const *_b){

	int *a = (int *)_a;
	struct osoba *b = (struct osoba *)_b;
	printf("%d \n", b->last_year_of_labour - b->first_year_of_labour);
	return *a - (b->last_year_of_labour - b->first_year_of_labour);
}
