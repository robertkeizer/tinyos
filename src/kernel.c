#include "multiboot.h"
#include "kprint.h"
#include "concat.h"
#include "substr.h"
#include "strpos.h"

void kmain( void* mbd, unsigned long magic ){

	if ( magic != 0x2BADB002 ){
		kprint( "Ack. No multiboot." );
		for( ;; );
	};

	int *tmpPos;
	tmpPos	= strpos( "testing one two three", "o" );

	while( *tmpPos ){
		kprint( "Got 'o' at position " );
		kprint( (char *)*tmpPos );
		tmpPos++;
	}

	kprint( "Testing" );
	kprint( "!!" );

	for( ;; );
}
