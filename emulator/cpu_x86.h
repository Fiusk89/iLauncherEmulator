#pragma once
#ifndef CPU_X86_H
#define CPU_X86_H
#include "cpu.h"

typedef enum x86_regs
{
    x86_reg_gs = 0,
    x86_reg_fs = x86_reg_gs + 2,
    x86_reg_es = x86_reg_fs + 2,
    x86_reg_ds = x86_reg_es + 2,
    x86_reg_cs = x86_reg_ds + 2,
    x86_reg_ss = x86_reg_cs + 2,

    x86_reg_al = x86_reg_ss + 2,
    x86_reg_ah = x86_reg_al + 1,
    x86_reg_cl = x86_reg_ah + 1,
    x86_reg_ch = x86_reg_cl + 1,
    x86_reg_dl = x86_reg_ch + 1,
    x86_reg_dh = x86_reg_dl + 1,
    x86_reg_bl = x86_reg_dh + 1,
    x86_reg_bh = x86_reg_bl + 1,

    x86_reg_ax = x86_reg_bh + 1,
    x86_reg_cx = x86_reg_ax + 2,
    x86_reg_dx = x86_reg_cx + 2,
    x86_reg_bx = x86_reg_dx + 2,
    x86_reg_sp = x86_reg_bx + 2,
    x86_reg_bp = x86_reg_sp + 2,
    x86_reg_si = x86_reg_bp + 2,
    x86_reg_di = x86_reg_si + 2,
    x86_reg_ip = x86_reg_di + 2,
    x86_reg_flags = x86_reg_ip + 2,

    x86_reg_eax = x86_reg_flags + 2,
    x86_reg_ecx = x86_reg_eax + 4,
    x86_reg_edx = x86_reg_ecx + 4,
    x86_reg_ebx = x86_reg_edx + 4,
    x86_reg_esp = x86_reg_ebx + 4,
    x86_reg_ebp = x86_reg_esp + 4,
    x86_reg_esi = x86_reg_ebp + 4,
    x86_reg_edi = x86_reg_esi + 4,
    x86_reg_eip = x86_reg_edi + 4,
    x86_reg_eflags = x86_reg_eip + 4,

    x86_reg_cr0 = x86_reg_eflags + 4,
    x86_reg_cr1 = x86_reg_cr0 + 4,
    x86_reg_cr2 = x86_reg_cr1 + 4,
    x86_reg_cr3 = x86_reg_cr2 + 4,
    x86_reg_cr4 = x86_reg_cr3 + 4,
    x86_reg_cr5 = x86_reg_cr4 + 4,
    x86_reg_cr6 = x86_reg_cr5 + 4,
    x86_reg_cr7 = x86_reg_cr6 + 4,
    x86_reg_cr8 = x86_reg_cr7 + 4,

    x86_reg_gdtr = x86_reg_cr8 + 4,

    x86_reg_end = x86_reg_gdtr + 4,

    x86_flags_CF = 1 << 0,
    x86_flags_PF = 1 << 2,
    x86_flags_AF = 1 << 4,
    x86_flags_ZF = 1 << 6,
    x86_flags_SF = 1 << 7,
    x86_flags_TF = 1 << 8,
    x86_flags_IF = 1 << 9,
    x86_flags_DF = 1 << 10,
    x86_flags_OF = 1 << 11,

    x86_cr0_PE = 1 << 0,
    x86_cr0_MP = 1 << 1,
    x86_cr0_EM = 1 << 2,
    x86_cr0_TS = 1 << 3,
    x86_cr0_ET = 1 << 4,
    x86_cr0_NE = 1 << 5,
    x86_cr0_WP = 1 << 16,
    x86_cr0_AM = 1 << 18,
    x86_cr0_NW = 1 << 29,
    x86_cr0_CD = 1 << 30,
    x86_cr0_PG = 1 << 31,

    x86_cache_size = 0,
    x86_cache_rm = x86_cache_size + 1,
    x86_cache_reg = x86_cache_rm + 1,
    x86_cache_mod = x86_cache_reg + 1,
    x86_cache_address0 = x86_cache_mod + 1,
    x86_cache_address1 = x86_cache_address0 + 8,
    x86_cache_opcode = x86_cache_address1 + 8,
    x86_cache_seg_gs = x86_cache_opcode + 1,
    x86_cache_seg_fs = x86_cache_seg_gs + 8,
    x86_cache_seg_es = x86_cache_seg_fs + 8,
    x86_cache_seg_ds = x86_cache_seg_es + 8,
    x86_cache_seg_cs = x86_cache_seg_ds + 8,
    x86_cache_seg_ss = x86_cache_seg_cs + 8,
    x86_cache_is_word = x86_cache_seg_ss + 8,
    x86_cache_buffer256 = x86_cache_is_word + 1,
    x86_cache_end = x86_cache_buffer256 + 256,

    x86_override_dword_operand = 1 << 0,
    x86_override_dword_address = 1 << 1,
    x86_override_gs = 1 << 2,
    x86_override_fs = 1 << 3,
    x86_override_es = 1 << 4,
    x86_override_ds = 1 << 5,
    x86_override_cs = 1 << 6,
    x86_override_ss = 1 << 7,
} x86_regs_t;

static const uint8_t x86_regscontrol[] = {
    x86_reg_cr0,
    x86_reg_cr1,
    x86_reg_cr2,
    x86_reg_cr3,
    x86_reg_cr4,
    x86_reg_cr5,
    x86_reg_cr6,
    x86_reg_cr7,
    x86_reg_cr8,
};

static const uint8_t x86_regs32[] = {
    x86_reg_eax,
    x86_reg_ecx,
    x86_reg_edx,
    x86_reg_ebx,
    x86_reg_esp,
    x86_reg_ebp,
    x86_reg_esi,
    x86_reg_edi,
};

static const uint8_t x86_regs16[] = {
    x86_reg_ax,
    x86_reg_cx,
    x86_reg_dx,
    x86_reg_bx,
    x86_reg_sp,
    x86_reg_bp,
    x86_reg_si,
    x86_reg_di,
};

static const uint8_t x86_regs8[] = {
    x86_reg_al,
    x86_reg_cl,
    x86_reg_dl,
    x86_reg_bl,
    x86_reg_ah,
    x86_reg_ch,
    x86_reg_dh,
    x86_reg_bh,
};

static const uint8_t x86_sregs[] = {
    x86_reg_es,
    x86_reg_cs,
    x86_reg_ss,
    x86_reg_ds,
    x86_reg_fs,
    x86_reg_gs,
};

typedef struct x86_rm
{
    uint8_t rm : 3;
    uint8_t reg : 3;
    uint8_t mod : 2;
} x86_rm_t;

static const char *x86_regs_strings[x86_reg_end] = {
    "gs",
    (char *)NULL,
    "fs",
    (char *)NULL,
    "es",
    (char *)NULL,
    "ds",
    (char *)NULL,
    "cs",
    (char *)NULL,
    "ss",
    (char *)NULL,

    "al",
    "ah",
    "cl",
    "ch",
    "dl",
    "dh",
    "bl",
    "bh",

    "ax",
    (char *)NULL,
    "cx",
    (char *)NULL,
    "dx",
    (char *)NULL,
    "bx",
    (char *)NULL,
    "sp",
    (char *)NULL,
    "bp",
    (char *)NULL,
    "si",
    (char *)NULL,
    "di",
    (char *)NULL,
    "ip",
    (char *)NULL,
    "flags",
    (char *)NULL,

    "eax",
    (char *)NULL,
    (char *)NULL,
    (char *)NULL,
    "ecx",
    (char *)NULL,
    (char *)NULL,
    (char *)NULL,
    "edx",
    (char *)NULL,
    (char *)NULL,
    (char *)NULL,
    "ebx",
    (char *)NULL,
    (char *)NULL,
    (char *)NULL,
    "esp",
    (char *)NULL,
    (char *)NULL,
    (char *)NULL,
    "ebp",
    (char *)NULL,
    (char *)NULL,
    (char *)NULL,
    "esi",
    (char *)NULL,
    (char *)NULL,
    (char *)NULL,
    "edi",
    (char *)NULL,
    (char *)NULL,
    (char *)NULL,
    "eip",
    (char *)NULL,
    (char *)NULL,
    (char *)NULL,
    "eflags",
    (char *)NULL,
    (char *)NULL,
    (char *)NULL,

    "cr0",
    (char *)NULL,
    (char *)NULL,
    (char *)NULL,
    "cr1",
    (char *)NULL,
    (char *)NULL,
    (char *)NULL,
    "cr2",
    (char *)NULL,
    (char *)NULL,
    (char *)NULL,
    "cr3",
    (char *)NULL,
    (char *)NULL,
    (char *)NULL,
    "cr4",
    (char *)NULL,
    (char *)NULL,
    (char *)NULL,
    "cr5",
    (char *)NULL,
    (char *)NULL,
    (char *)NULL,
    "cr6",
    (char *)NULL,
    (char *)NULL,
    (char *)NULL,
    "cr7",
    (char *)NULL,
    (char *)NULL,
    (char *)NULL,
    "cr8",
    (char *)NULL,
    (char *)NULL,
    (char *)NULL,

    "gdtr",
    (char *)NULL,
    (char *)NULL,
    (char *)NULL,
};

struct cpu *x86_setup();
#endif