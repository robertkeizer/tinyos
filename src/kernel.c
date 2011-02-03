#include "multiboot.h"
#include "kprint.h"
#include "concat.h"
#include "substr.h"

void kmain( void* mbd, unsigned long magic ){

	if ( magic != 0x2BADB002 ){
		kprint( "Ack. No multiboot." );
		for( ;; );
	};

	kprint( substr( "TEST", 2, 4 ) );

	for( ;; );
}
