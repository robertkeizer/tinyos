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

char *strcat( char *str, const char *str2 ){
	// Set the return pointer.
	char *r = str;
	// Get str up to the top end of its array.
	while( *str != 0 ){
		str++;
	}
	// Loop through each value of str2, append it to str
	while( (*str++ = *str2++ ) != 0 ){
		continue;
	}
	return r;
}

int strcmp( const char *str1, const char *str2 ){
	if( (int)strlen( str1 ) == (int)strlen( str2 ) ){
		return 0;
	}else{
		return 1;
	}
}

void kclr( ){
	char *video = (char *)0xb8000;
	for( int x=0; x<4000; x++ ){
		*video = 0;
		video++;
	}
}

char *intToChar( int input, &char *running ){
	if( input > 9 ){
		return intToChar( input%10, &running );
	}else{
		*running++ = (char)input+48;
		return running;
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

	if( strlen( "Testing" ) == 7 ){
		kprint( "[ good ] strlen works.\n" );
	}else{
		kprint( "[ fail ] strlen fails.\n" );
	}
	
	if( strcmp( "test", "test" ) ){
		kprint( "[ good ] strcmp works.\n" );
	}else{
		kprint( "[ fail ] strcmp fails.\n" );
	}

	char test[2];
	test[0] = intToChar( 5 );
	test[1] = '\0';
	kprint( test );
}
