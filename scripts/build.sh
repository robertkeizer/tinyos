#!/usr/bin/env bash
if [ ! -d "src/" ]; then
	echo "Use scripts/build.sh";
	exit 1;
fi;

nasm -f elf -o build/loader.o src/loader.s
gcc -o build/kernel.o -c src/kernel.c -Wall -Wextra -nostdlib -nostartfiles -nodefaultlibs
ld -T src/linker.ld -o build/kernel.bin build/loader.o build/kernel.o

cat grub/stage1 grub/stage2 grub/pad build/kernel.bin > build/floppy.img
