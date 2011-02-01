default:
	nasm -f elf -o build/loader.o src/loader.s
	gcc -o build/kernel.o -c src/kernel.c -Wall -Wextra -nostdlib -nostartfiles -nodefaultlibs -std=c99 -Lsrc/
	gcc -o build/kprint.o -c src/kprint.c -Wall -Wextra -nostdlib -nostartfiles -nodefaultlibs -std=c99 -Lsrc/
	ld -T src/linker.ld -o build/kernel.bin build/loader.o build/kernel.o build/kprint.o
	cat grub/stage1 grub/stage2 grub/pad build/kernel.bin > build/floppy.img
clean:
	rm build/loader.o
	rm build/kernel.o
	rm build/kprint.o
	rm build/kernel.bin
	rm build/floppy.img
