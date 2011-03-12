#include "multiboot.h"

int current_row=0;
int current_col=0;

int strlen( const char *str ){
	int running_total=0;
	for( int x=0; (char)str[x] != '\n'; x++ ){
		running_total++;
	}
	return running_total;
}

void kprint( const char *str ){
        char *video = (char *)0xb8000 + ( current_col*2 ) + ( current_row*80*2 );
        while( *str != 0 ){
                *video = *str;
                video++;
                str++;

                *video=0x07;
                video++;
		current_col++;
        }
}

void kmain( void* mbd, unsigned long magic ){

	if ( magic != 0x2BADB002 ){
		kprint( "Ack. No multiboot." );
		for( ;; );
	};

	kprint( "Testing" );

	kprint( "!!" );

	current_row=1;
	current_col=0;

	if( strlen( "Test" ) != 4 ){
		kprint( "Crap, strlen fails." );
	}else{
		kprint( "Yay, strlen works." );
	}

	for( ;; );
}
