default:
	nasm -f elf -o build/loader.o src/loader.s
	gcc -o build/kernel.o -c src/kernel.c -Wall -Wextra -nostdlib -nostartfiles -nodefaultlibs -std=c99 -Lsrc/
	gcc -o build/kprint.o -c src/kprint.c -Wall -Wextra -nostdlib -nostartfiles -nodefaultlibs -std=c99 -Lsrc/
	gcc -o build/strlen.o -c src/strlen.c -Wall -Wextra -nostdlib -nostartfiles -nodefaultlibs -std=c99 -Lsrc/
	gcc -o build/concat.o -c src/concat.c -Wall -Wextra -nostdlib -nostartfiles -nodefaultlibs -std=c99 -Lsrc/
	gcc -o build/substr.o -c src/substr.c -Wall -Wextra -nostdlib -nostartfiles -nodefaultlibs -std=c99 -Lsrc/
	gcc -o build/strcmp.o -c src/strcmp.c -Wall -Wextra -nostdlib -nostartfiles -nodefaultlibs -std=c99 -Lsrc/
	gcc -o build/strpos.o -c src/strpos.c -Wall -Wextra -nostdlib -nostartfiles -nodefaultlibs -std=c99 -Lsrc/
	ld -T src/linker.ld -o build/kernel.bin build/loader.o build/kernel.o build/kprint.o build/strlen.o build/concat.o build/substr.o build/strcmp.o build/strpos.o
	cat grub/stage1 grub/stage2 grub/pad build/kernel.bin > build/floppy.img
clean:
	rm build/loader.o
	rm build/kernel.o
	rm build/kprint.o
	rm build/strlen.o
	rm build/concat.o
	rm build/substr.o
	rm build/strcmp.o
	rm build/strpos.o
	rm build/kernel.bin
	rm build/floppy.img
