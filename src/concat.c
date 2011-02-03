#include "strlen.h"
char *concat( const char *str1, const char *str2 ){
	char tmpReturn[strlen(str1)+strlen(str2)+1];
	int counter=0;
	while( *str1 != 0 ){
		tmpReturn[counter] = *str1;
		str1++;
		counter++;
	}
	while( *str2 != 0 ){
		tmpReturn[counter] = *str2;
		str2++;
		counter++;
	}
	
	tmpReturn[counter] = (char)'\0';

	return tmpReturn;
}
