#include "multiboot.h"
#include "kprint.h"

void kmain( void* mbd, unsigned int magic ){

	if ( magic != 0x2BADB002 ){
		kprint( "Ack. No multiboot." );
		for( ;; );
	};

	char * boot_loader_name =(char*) ((long*)mbd)[16];

	kprint( boot_loader_name );

	for( ;; );
}
