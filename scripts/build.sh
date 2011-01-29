#!/usr/bin/env bash
if [ ! -d "src/" ]; then
	echo "Use scripts/build.sh";
	exit 1;
fi;

# into src/
cd src
nasm -f elf -o ../build/loader.o loader.s
nasm -f elf -o ../build/k_memory_a20_enable.o asm/k_memory_a20_enable.s
gcc -o ../build/kernel.o -c kernel.c -Wall -Wextra -nostdlib -nostartfiles -nodefaultlibs -std=c99
ld -T linker.ld -o ../build/kernel.bin ../build/loader.o ../build/k_memory_a20_enable.o ../build/kernel.o
cd ../
# back out of src/
cat grub/stage1 grub/stage2 grub/pad build/kernel.bin > build/floppy.img
