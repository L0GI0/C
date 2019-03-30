#include <stdio.h>
#include <stdlib.h>
#include <stdnoreturn.h>

_Noreturn void stop_now(int i){
	printf("End of a program");
	exit(i); //u need to use exit() with _Noreturn prefix you only inform
	// compilator that this function will end whole program 
}

int main(void){
	printf("Before calling stop_now function\n");
	stop_now(2);
	printf("After calling stop_now function\n");//this won't be executed
}