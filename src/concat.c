#include "concat.h"
#include "strlen.h"
const char* concat( const char *str1, const char *str2 ){
	int totalSize = (sizeof(str1)-1) + (sizeof(str2)-1);

	int runningCounter=0;
	char tmpReturn[totalSize+1];

	for( unsigned int x=0; x< sizeof(str1)-1; x++ ){
		tmpReturn[x] = str1[x];
		runningCounter++;
	}
	
	for( unsigned int y=0; y<sizeof(str2)-1; y++ ){
		tmpReturn[y+runningCounter] = str2[y];
		runningCounter++;
	}

	return (char*)tmpReturn;
}
