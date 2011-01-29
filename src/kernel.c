#include "kernel.h"
void kmain( void *mbd, unsigned int magic ){
	if ( magic != 0x2BADB002 ){
		/* Ack, not according to spec */
	}

	kprint( "Test" );
}
