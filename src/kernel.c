void kmain( void *mbd, unsigned int magic ){
	if ( magic != 0x2BADB002 ){
		/* Ack, not according to spec */
	}
	unsigned char *videoram = (unsigned char *) 0xb8000;
	videoram[0] = 65;
	videoram[1] = 0x07;
}
