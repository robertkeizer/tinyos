#include "strlen.h"
int strlen( const char *str ){
	char *c;
	for( c = str; *c; ++c );
	return (int)( c - str );
}
