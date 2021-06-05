# ファイル生成規則

# Makefile
nasmhead.bin: nasmhead.asm
	nasm -o nasmhead.bin nasmhead.asm

nasmfunc.o: nasmfunc.asm
	nasm -f elf32 -o nasmfunc.o nasmfunc.asm

bootpack.o: bootpack.c
	gcc -c -m32 -fno-pic -o bootpack.o bootpack.c

bootpack.bin: bootpack.o nasmfunc.o
	ld -m elf_i386 -e HariMain -o bootpack.bin -Tos.ls bootpack.o nasmfunc.o

os.sys: nasmhead.bin bootpack.bin
	cat nasmhead.bin bootpack.bin > os.sys

ipl10.bin: ipl10.asm
	nasm -o ipl10.bin ipl10.asm

os.img: ipl10.bin os.sys
	mformat -f 1440 -C -B ipl10.bin -i os.img ::
	mcopy -i os.img os.sys ::

run: os.img
	qemu-system-i386 -fda os.img

clean:
	rm -f *.bin
	rm -f *.o
	rm -f *.sys
	rm -f *.img

debug: 
	qemu-system-i386 -m 32 -localtime -vga std -fda os.img -gdb tcp::10000 -S &