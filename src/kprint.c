#include "kprint.h"
void kprint( const char *str ){
	kprint_position current_pos;

	char *video = (char *)0xb8000 + ( (current_pos.row*80)+(current_pos.col*2) );

	/*
	** TODO: split by strpos( str, "\n" ) and recurse krpint..
	*/

	while( *str != 0 ){
		*video = *str;
		video++;
		str++;

		*video=0x07;
		video++;
		current_pos.col++;
	}
}
