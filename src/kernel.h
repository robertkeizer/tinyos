#ifndef __KERNEL
#define __KERNEL
void kprint( const char *string ){
	char *video = (char*)0xB8000;
	while( *string != 0 ){
		*video=*string;
		string++;
		video++;
		*video=0x07;
		video++;
	}
}
#endif
