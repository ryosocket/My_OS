# ファイル生成規則

ipl10.bin : ipl10.asm Makefile
	nasm ipl10.asm -o ipl10.bin -l ipl10.lst

asmhead.bin : asmhead.asm Makefile
	nasm asmhead.asm -o asmhead.bin -l asmhead.lst

nasmfunc.o : nasmfunc.asm Makefile
	nasm -f elf nasmfunc.asm -o nasmfunc.o 

bootpack.hrb : bootpack.c har.ld Makefile
	gcc -fno-pie -no-pie -march=i486 -m32 -nostdlib -T har.ld bootpack.c nasmfunc.o -o bootpack.hrb

haribote.sys : asmhead.bin bootpack.hrb Makefile
	cat asmhead.bin bootpack.hrb > haribote.sys

#helloos.img : ipl.bin tail.bin Makefile
haribote.img : ipl10.bin haribote.sys Makefile
	#cat ipl.bin tail.bin > helloos.img
	mformat -f 1440 -C -B ipl10.bin -i haribote.img ::
	mcopy -i haribote.img asmhead.bin  ::

asm :
	make -r ipl10.bin

img :
	make -r haribote.img

run :
	make img
	qemu-system-i386 -fda haribote.img
