#include "strlen.h"
char * substr( const char *string, int start, int end ){
	if( strlen( string ) > end || start < 0 || end < 0 || end < start ){
		// ERROR
	}
	
	int lengthOfNewString	= end - start;
	int newStringTmpCounter		= 0;

	char tmpReturn[lengthOfNewString+1];

	for( int tmpCounter=start; tmpCounter<end; tmpCounter++ ){
		tmpReturn[newStringTmpCounter] = string[tmpCounter];
		newStringTmpCounter++;
	}

	tmpReturn[lengthOfNewString+1] = '\0';
	return tmpReturn;
}
