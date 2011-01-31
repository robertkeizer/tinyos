#include "kernel.h"
#include "kprint.h"
#include "concat.h"
#include "strlen.h"

void kmain( void *mbd, unsigned int magic ){
	if ( magic != 0x2BADB002 ){
		/* Ack, not according to spec */
	}

	kclr();
	kprint( "Starting up.." );
	kprint( "Size of 'abc' is: " );
	kprint( (char *)strlen( "abc" ) );
}
