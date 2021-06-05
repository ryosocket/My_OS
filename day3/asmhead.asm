;asmhead
;TAB = 4

;BOOT_INFO関係
CYLS    EQU     0x0ff0  ;ブートセクタが設定する
LEDS    EQU     0x0ff1  
VMODE   EQU     0x0ff2  ;何ビットカラーか？色数に関する情報
SCRNX   EQU     0x0ff4  ;解像度のX
SCRNY   EQU     0x0ff6  ;解像度のY
VRAM    EQU     0x0ff8  ;グラフィックバッファの開始番地,VideoRAM

ORG 0xc200 ;このプログラムがどこに読み込まれるか

MOV AL,0x13 ;VGAグラフィックス、320x200x8bitカラー
MOV AH,0x00
INT 0x10

MOV     BYTE [VMODE], 8 
MOV     WORD [SCRNX], 320   
MOV     WORD [SCRNY], 200  
MOV     DWORD [VRAM], 0x000a0000

MOV     AH, 0x02
INT     0x16  ;キーボードBIOS
MOV     [LEDS], AL

fin:
    HLT
    JMP fin