#include "bootpack.h"

#define COL8_000000 0
#define COL8_FF0000 1
#define COL8_00FF00 2
#define COL8_FFFF00 3
#define COL8_0000FF 4
#define COL8_FF00FF 5
#define COL8_00FFFF 6
#define COL8_FFFFFF 7
#define COL8_C6C6C6 8
#define COL8_840000 9
#define COL8_008400 10
#define COL8_848400 11
#define COL8_000084 12
#define COL8_840084 13
#define COL8_008484 14
#define COL8_848484 15

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

    putblock8_8(binfo->vram,binfo->scrnx,16,16,mx,my,mouse,16);
    sprintf(s,"scrnx=%d",binfo->scrnx);
    putfont8_asc(binfo->vram,binfo->scrnx,30,30,COL8_FFFFFF,s);

    for(;;){
        io_hlt();
    }
}



