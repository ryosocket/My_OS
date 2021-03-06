;hello-os
;TAB = 4

    ORG 0x7c00 ;このプログラムがどこに読み込まれるか記述する

;FAT12フロッピーのための記述
    
    JMP     entry
    DB      0x90

    DB      0xeb,0x4e,0x90
    DB      "HELLOIPL"  ;ブートセクタの名前
    DW      512         ;1セクタの大きさ（セクタ：データを読み書きする単位）
    DB      1           ;クラスタの大きさ(クラスタ：セクタの集まり、ファイルに割り当てる最小の単位)
    DW      1           ;FATがどこからはじまるか（FAT：File Allocation Tables）
    DB      2           ;FATの個数
    DW      224         ;ルートディレクトリの大きさ
    DW      2880        ;このドライブの大きさ
    DB      0xf0        ;メディアタイプ
    DW      9           ;FAT領域の長さ
    DW      18          ;１トラックにいくつセクタがあるか
    DW      2           ;ヘッドの数
    DD      0           ;パーティションを使っていないので必ず0にする
    DD      2880        ;ドライブの大きさ
    DB      0,0,0x29    ;
    DD      0xffffffff  ;
    DB      "HELLO-OS   "  ;ディスクの名前(11バイト)
    DB      "FAT12   "     ;フォーマットの名前（8バイト）
    RESB    18      

;main
    entry:
        MOV AX,0    ;レジスタの初期化
        MOV SS,AX   
        MOV SP,0x7c00
        MOV DS,AX
        MOV ES,AX

        MOV SI,msg
    
    putloop:
        MOV AL,[SI]
        ADD SI,1
        CMP AL,0
        JE  fin
        MOV AH,0x0e ;1文字表示ファンクション
        MOV BX,15   ;カラーコード
        INT 0x10    ;ビデオBIOS呼び出し
        JMP putloop
    
    fin:   
        HLT ;CPU停止(待機状態)
        JMP fin ;無限ループ
        
    msg:
        DB  0x0a,0x0a
        DB  "hello,world2"
        DB  0x0a
        DB  0

        RESB    0x1fe-($-$$)
        DB 0x55,0xaa

;ブートセクタ以外の記述
    DB  0xf0,0xff,0xff,0x00,0x00,0x00,0x00,0x00
    RESB    4600
    DB  0xf0,0xff,0xff,0x00,0x00,0x00,0x00,0x00
    RESB    1469432
