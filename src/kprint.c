#include "kprint.h"
int k_video_char=0;
int k_video_line=0;

void kprint( const char *string ){
	while( *string != 0 ){

		// Not great, as \n has to be the whole line.. 
		// Find a better way to match
		if( (char *)string == (char*)"\n" ){
			k_video_char=0;
			k_video_line++;
			string++;
			continue;
		}

		char *video = (char*)0xB8000 + ( k_video_char * 2 ) + ( 80 * 2 * k_video_line );
		*video=*string;
		string++;
		video++;
		*video=0x07;
		video++;
		k_video_char++;
	}
}

void kclr( ){
	char *video = (char*)0xB8000;
	int i = 0;
	while( i < ( 80*25*2) ){
		video[i]=' ';
		i++;
		video[i]=0x07;
		i++;
	}
	k_video_char=0;
	k_video_line=0;
}
