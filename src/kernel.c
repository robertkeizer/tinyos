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

void kclr( ){
	char *video = (char *)0xb8000;
	for( int x=0; x<4000; x++ ){
		*video = 0;
		video++;
	}
}

void kprint( const char *str ){
        char *video = (char *)0xb8000 + ( current_col*2 ) + ( current_row*80*2 );

	for( int currentChar=0; (char)str[currentChar] != 0; currentChar++ ){
		if( (char)str[currentChar] == '\n' ){
			current_row++;
			current_col=0;
		}else{
			*video = (char)str[currentChar];
			video++;
			*video = 0x07;
			video++;
			current_col++;
		}
	}
}

void kmain( void* mbd, unsigned long magic ){

	if ( magic != 0x2BADB002 ){
		kprint( "Ack. No multiboot." );
		for( ;; );
	};

	kclr();

	kprint( "This is tinyos!\n" );

	if( strlen( "Test" ) != 4 ){
		kprint( "[ fail ] strlen fails.\n" );
	}else{
		kprint( "[ good ] strlen works.\n" );
	}

	for( ;; );
}
