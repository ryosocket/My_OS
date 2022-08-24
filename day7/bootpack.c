#include "bootpack.h"

void HariMain(void)
{
    char* vram; /*pは、BYTE[...]用の番地*/
    struct BOOTINFO *binfo;
    binfo = (struct BOOTINFO *)0x0ff0;
    extern char hankaku[4096];
    char s[40];
    char *mouse;
    int mx,my;
    mx=150;
    my=40;

    init_gdidt();
    init_palette();
    init_screen(binfo->vram,binfo->scrnx,binfo->scrny);
    init_mouse_coursor8(mouse,COL8_008484);
    init_pic();
    io_sti();

    putblock8_8(binfo->vram,binfo->scrnx,16,16,mx,my,mouse,16);
    sprintf(s,"scrnx=%d",binfo->scrnx);
    putfont8_asc(binfo->vram,binfo->scrnx,30,30,COL8_FFFFFF,s);

    io_out8(PIC0_IMR,0xf9);
    io_out8(PIC1_IMR,0xef);

    for(;;){
        io_hlt();
    }
}



