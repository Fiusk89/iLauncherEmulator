bits 16
org 0xf0000

pmode:use16
    mov word sp, 0x3000
    ;lgdt [gdtr]
    mov ax, 0x10
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax
	jmp 0x08:start

start:use16
    mov word ax, 0xffff
    mov word bx, 0xffff
    push word ax
    mov word dx, [0xf4f5]
    mov word ax, sp
    mov word sp, 0x0000
    mov word sp, ax
    pop word ax
    int 0x21
    cmp word ax, bx
    je call_loop
    jmp word start

call_loop:use16
    mov word bp, colors
.l1:
    cmp word bp, colors + (256 * 4)
    je .end
.l2:
    mov ax, [bp]
    add bp, 2
    mov bx, [bp]
    add bp, 2
    call loop
    jmp .l1
.end:
    jmp call_loop

loop:use16
    mov word cx, 0x0000
.l1:
    cmp word cx, [0xfff4]
    je .end
    mov dx, 0x0000
.l2:
    int byte 0x20
    add word dx, 1
    cmp word dx, [0xfff2]
    je .l3
    jmp word .l2
.l3:
    add word cx, 1
    jmp word .l1
.end:
    ret

gdt:
    .start:
        dq 0x0000000000000000
        dq 0x000f9a000000ffff
        dq 0x000f92000000ffff
    .end:
    
gdtr:
    dw gdt.end - gdt.start
    dd gdt.start

colors:
    dd 0x000000
    dd 0x800000
    dd 0x008000
    dd 0x808000
    dd 0x000080
    dd 0x800080
    dd 0x008080
    dd 0xc0c0c0
    dd 0x808080
    dd 0xff0000
    dd 0xffff00
    dd 0x00ff00
    dd 0x0000ff
    dd 0xff00ff
    dd 0x00ffff
    dd 0xffffff
    dd 0x000000
    dd 0x00005f
    dd 0x000087
    dd 0x0000af
    dd 0x0000d7
    dd 0x0000ff
    dd 0x005f00
    dd 0x005f5f
    dd 0x005f87
    dd 0x005faf
    dd 0x005fd7
    dd 0x005fff
    dd 0x008700
    dd 0x00875f
    dd 0x008787
    dd 0x0087af
    dd 0x0087d7
    dd 0x0087ff
    dd 0x00af00
    dd 0x00af5f
    dd 0x00af87
    dd 0x00afaf
    dd 0x00afd7
    dd 0x00afff
    dd 0x00d700
    dd 0x00d75f
    dd 0x00d787
    dd 0x00d7af
    dd 0x00d7d7
    dd 0x00d7ff
    dd 0x00ff00
    dd 0x00ff5f
    dd 0x00ff87
    dd 0x00ffaf
    dd 0x00ffd7
    dd 0x00ffff
    dd 0x5f0000
    dd 0x5f005f
    dd 0x5f0087
    dd 0x5f00af
    dd 0x5f00d7
    dd 0x5f00ff
    dd 0x5f5f00
    dd 0x5f5f5f
    dd 0x5f5f87
    dd 0x5f5faf
    dd 0x5f5fd7
    dd 0x5f5fff
    dd 0x5f8700
    dd 0x5f875f
    dd 0x5f8787
    dd 0x5f87af
    dd 0x5f87d7
    dd 0x5f87ff
    dd 0x5faf00
    dd 0x5faf5f
    dd 0x5faf87
    dd 0x5fafaf
    dd 0x5fafd7
    dd 0x5fafff
    dd 0x5fd700
    dd 0x5fd75f
    dd 0x5fd787
    dd 0x5fd7af
    dd 0x5fd7d7
    dd 0x5fd7ff
    dd 0x5fff00
    dd 0x5fff5f
    dd 0x5fff87
    dd 0x5fffaf
    dd 0x5fffd7
    dd 0x5fffff
    dd 0x870000
    dd 0x87005f
    dd 0x870087
    dd 0x8700af
    dd 0x8700d7
    dd 0x8700ff
    dd 0x875f00
    dd 0x875f5f
    dd 0x875f87
    dd 0x875faf
    dd 0x875fd7
    dd 0x875fff
    dd 0x878700
    dd 0x87875f
    dd 0x878787
    dd 0x8787af
    dd 0x8787d7
    dd 0x8787ff
    dd 0x87af00
    dd 0x87af5f
    dd 0x87af87
    dd 0x87afaf
    dd 0x87afd7
    dd 0x87afff
    dd 0x87d700
    dd 0x87d75f
    dd 0x87d787
    dd 0x87d7af
    dd 0x87d7d7
    dd 0x87d7ff
    dd 0x87ff00
    dd 0x87ff5f
    dd 0x87ff87
    dd 0x87ffaf
    dd 0x87ffd7
    dd 0x87ffff
    dd 0xaf0000
    dd 0xaf005f
    dd 0xaf0087
    dd 0xaf00af
    dd 0xaf00d7
    dd 0xaf00ff
    dd 0xaf5f00
    dd 0xaf5f5f
    dd 0xaf5f87
    dd 0xaf5faf
    dd 0xaf5fd7
    dd 0xaf5fff
    dd 0xaf8700
    dd 0xaf875f
    dd 0xaf8787
    dd 0xaf87af
    dd 0xaf87d7
    dd 0xaf87ff
    dd 0xafaf00
    dd 0xafaf5f
    dd 0xafaf87
    dd 0xafafaf
    dd 0xafafd7
    dd 0xafafff
    dd 0xafd700
    dd 0xafd75f
    dd 0xafd787
    dd 0xafd7af
    dd 0xafd7d7
    dd 0xafd7ff
    dd 0xafff00
    dd 0xafff5f
    dd 0xafff87
    dd 0xafffaf
    dd 0xafffd7
    dd 0xafffff
    dd 0xd70000
    dd 0xd7005f
    dd 0xd70087
    dd 0xd700af
    dd 0xd700d7
    dd 0xd700ff
    dd 0xd75f00
    dd 0xd75f5f
    dd 0xd75f87
    dd 0xd75faf
    dd 0xd75fd7
    dd 0xd75fff
    dd 0xd78700
    dd 0xd7875f
    dd 0xd78787
    dd 0xd787af
    dd 0xd787d7
    dd 0xd787ff
    dd 0xd7af00
    dd 0xd7af5f
    dd 0xd7af87
    dd 0xd7afaf
    dd 0xd7afd7
    dd 0xd7afff
    dd 0xd7d700
    dd 0xd7d75f
    dd 0xd7d787
    dd 0xd7d7af
    dd 0xd7d7d7
    dd 0xd7d7ff
    dd 0xd7ff00
    dd 0xd7ff5f
    dd 0xd7ff87
    dd 0xd7ffaf
    dd 0xd7ffd7
    dd 0xd7ffff
    dd 0xff0000
    dd 0xff005f
    dd 0xff0087
    dd 0xff00af
    dd 0xff00d7
    dd 0xff00ff
    dd 0xff5f00
    dd 0xff5f5f
    dd 0xff5f87
    dd 0xff5faf
    dd 0xff5fd7
    dd 0xff5fff
    dd 0xff8700
    dd 0xff875f
    dd 0xff8787
    dd 0xff87af
    dd 0xff87d7
    dd 0xff87ff
    dd 0xffaf00
    dd 0xffaf5f
    dd 0xffaf87
    dd 0xffafaf
    dd 0xffafd7
    dd 0xffafff
    dd 0xffd700
    dd 0xffd75f
    dd 0xffd787
    dd 0xffd7af
    dd 0xffd7d7
    dd 0xffd7ff
    dd 0xffff00
    dd 0xffff5f
    dd 0xffff87
    dd 0xffffaf
    dd 0xffffd7
    dd 0xffffff
    dd 0x080808
    dd 0x121212
    dd 0x1c1c1c
    dd 0x262626
    dd 0x303030
    dd 0x3a3a3a
    dd 0x444444
    dd 0x4e4e4e
    dd 0x585858
    dd 0x626262
    dd 0x6c6c6c
    dd 0x767676
    dd 0x808080
    dd 0x8a8a8a
    dd 0x949494
    dd 0x9e9e9e
    dd 0xa8a8a8
    dd 0xb2b2b2
    dd 0xbcbcbc
    dd 0xc6c6c6
    dd 0xd0d0d0
    dd 0xdadada
    dd 0xe4e4e4
    dd 0xeeeeee