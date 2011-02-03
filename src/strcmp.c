#include "strcmp.h"
#include "strlen.h"
int strcmp( const char *str1, const char *str2 ){
	if( strlen( str1 ) != strlen( str2 ) ){
		return 1;
	}

	for( int x=0; x<strlen(str1); x++ ){
		if( str1[x] != str2[x] ){
			return 1;
		}
	}

	return 0;
}
