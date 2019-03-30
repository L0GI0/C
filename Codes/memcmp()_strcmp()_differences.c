#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
	char s1 []={ ’b’,’i’,’g’,’\0 ’,’c’,’a’,’r’};
	char s2 []={ ’b’,’i’,’g’,’\0 ’,’c’,’a’,’t’};
	//comparing by memcmp is done after comparing each specified character no metter of appearance of end of line sign
	if( memcmp ( s1 , s2 , 3) == 0 ) ;// TRUE
	if( memcmp ( s1 , s2 , 4) == 0 ) ;// TRUE
	if( memcmp ( s1 , s2 , 7) == 0 ) ;// FALSE
	// comparing by strcmp is done after comparing specified number of characters
	// or after reaching end of file sign
	if( strcmp ( s1 , s2 ) == 0 ) ;// TRUE
	if( strncmp ( s1 , s2 , 3) == 0 ) ;// TRUE
	if( strncmp ( s1 , s2 , 4) == 0 ) ;// TRUE
	if( strncmp ( s1 , s2 , 7) == 0 ) ;// TRUE

}