#include "kernel.h"
#include "mem.h"

void kmain( void *mbd, unsigned int magic ){
	if ( magic != 0x2BADB002 ){
		/* Ack, not according to spec */
	}

	kclr();
	kprint( "Starting up.." );

	if( k_memory_a20_enable( ) == 0 ){
		kprint( "\n" );
		kprint( "Enabled a20line" );
		kprint( "\n" );
	}else{
		kprint( "\n" );
		kprint( "Failure to enable a20line" );
		kprint( "\n" );
	}
	
}
