/*nasmhead.asm*/
struct BOOTINFO
{
    char cyls,leds,vmode,reserve;
    short scrnx,scrny;
    char *vram;
};

/*nasmfunc.asm*/
void io_hlt(void);
void write_mem8(int addr, int data);
void io_cli(void);
void io_out8(int port, int data);
int io_load_eflags(void);
void io_store_eflags(int flags);
void load_gdtr(int limit, int addr);
void load_idtr(int limit, int addr);

/*graphic.c*/
void init_palette(void);
void set_palette(int start, int end, unsigned char *rgb);
void sprintf(char *str, char *fmt, ...);
void boxfill8(unsigned char *vram,int xsize,unsigned char c,int x0,int y0,int x1,int y1);
void init_screen(unsigned char *vram,int xsize,int ysize);
void putfont8(char *vram,int xsize,int x,int y,char c,char *font);
void putfont8_asc(char *vram,int xsize,int x,int y, char color, unsigned char *s);
void init_mouse_coursor8(char *mouse, char bc);
void putblock8_8(char *vram,int vxsize,int pxsize,int pysize,int px0,int py0, char *buf,int bxsize);

/*dsctbl.c*/
struct SEGMENT_DESCRIPTOR
{
    short limit_low,base_low;
    char base_mid,access_right;
    char limit_high,base_high;
};

struct GATE_SESCRIPTOR
{
    short offset_low,selector;
    char dw_count,access_right;
    short offset_high;
};

void set_segmdesc(struct SEGMENT_DESCRIPTOR *sd,unsigned int limit,int base,int ar);
void set_gatedesc(struct GATE_SESCRIPTOR *gd,int offset,int selector, int ar);
void init_gdidt(void);

