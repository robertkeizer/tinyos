void kprint( const char *str ){
	char *video = (char *)0xb8000;
	while( *str != 0 ){
		*video = *str;
		video++;
		str++;
		*video=0x07;
		video++;
	}
}
