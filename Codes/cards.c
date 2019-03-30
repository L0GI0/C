#include <stdio.h>
#include <stdlib.h>
int main()
{
	int count=0;
	char card_name[3];
	while(card_name[0]!='X')
	{
	int val=0;
	puts("Enter the card_name: ");
	scanf("%2s",card_name);
	switch(card_name[0]){
		case 'K':
		case 'Q':	
		case 'J':
		 	val=10;
			
			 break;
		 case 'A':
			 val=11;
		 	break;
		 case 'X':
		 continue;	
		 default:
		 	val=atoi(card_name);
	}
	if(val>10 || val<1){
		puts("Value is out of range");
		continue;
		}
	if (val>2 && val <7){
		 puts("Count has gone up");
		 count++;
		}
	else if(val==10){	
		 puts("Count has gone down");
		 count--;	
		}
		printf("Current count: %i\n",count);
	}
	return 0;
}