#include "strlen.h"
#include "substr.h"
#include "strcmp.h"

int *strpos( const char *string, const char *substring ){
	int returnIntArray[strlen(substring)];
	int arrayCounter=0;
	for( int tmpCounter=0; tmpCounter<strlen(string)-strlen(substring); tmpCounter++ ){

		char tmpString[strlen(substring)];
		*tmpString = (char *)substr(string,tmpCounter,strlen(substring));

		if( strcmp(tmpString,string) == 0 ){
			returnIntArray[arrayCounter] = tmpCounter;
		}
		arrayCounter++;
	}

	return returnIntArray;
}
