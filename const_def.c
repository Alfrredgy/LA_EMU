#include "qemu/osdep.h"
#include "cpu.h"
#include "internals.h"
#include "cpu-csr.h"

const char * const regnames[32] = {
    "r0", "r1", "r2", "r3", "r4", "r5", "r6", "r7",
    "r8", "r9", "r10", "r11", "r12", "r13", "r14", "r15",
    "r16", "r17", "r18", "r19", "r20", "r21", "r22", "r23",
    "r24", "r25", "r26", "r27", "r28", "r29", "r30", "r31",
};

const char * const fregnames[32] = {
    "f0", "f1", "f2", "f3", "f4", "f5", "f6", "f7",
    "f8", "f9", "f10", "f11", "f12", "f13", "f14", "f15",
    "f16", "f17", "f18", "f19", "f20", "f21", "f22", "f23",
    "f24", "f25", "f26", "f27", "f28", "f29", "f30", "f31",
};

const char *const loongarch_r_alias[32] =
{
    "zer", "ra", "tp", "sp", "a0", "a1", "a2", "a3",
    "a4",   "a5", "a6", "a7", "t0", "t1", "t2", "t3",
    "t4",   "t5", "t6", "t7", "t8", "r21","fp", "s0",
    "s1",   "s2", "s3", "s4", "s5", "s6", "s7", "s8",
};

const char *const loongarch_f_alias[32] =
{
    "fa0", "fa1", "fa2",  "fa3",  "fa4",  "fa5",  "fa6",  "fa7",
    "ft0", "ft1", "ft2",  "ft3",  "ft4",  "ft5",  "ft6",  "ft7",
    "ft8", "ft9", "ft10", "ft11", "ft12", "ft13", "ft14", "ft15",
    "fs0", "fs1", "fs2",  "fs3",  "fs4",  "fs5",  "fs6",  "fs7",
};


#define CSRNAME_DECL(name)                  \
        [LOONGARCH_CSR_ ## name] = #name


const char* const csrnames[LOONGARCH_CSR_MAXADDR + 1] = {
    [0 ... LOONGARCH_CSR_MAXADDR] = NULL,
    CSRNAME_DECL(CRMD),
    CSRNAME_DECL(PRMD),
    CSRNAME_DECL(EUEN),
    CSRNAME_DECL(MISC),
    CSRNAME_DECL(ECFG),
    CSRNAME_DECL(ESTAT),
    CSRNAME_DECL(ERA),
    CSRNAME_DECL(BADV),
    CSRNAME_DECL(BADI),
    CSRNAME_DECL(EENTRY),
    CSRNAME_DECL(TLBIDX),
    CSRNAME_DECL(TLBEHI),
    CSRNAME_DECL(TLBELO0),
    CSRNAME_DECL(TLBELO1),
    CSRNAME_DECL(ASID),
    CSRNAME_DECL(PGDL),
    CSRNAME_DECL(PGDH),
    CSRNAME_DECL(PGD),
    CSRNAME_DECL(PWCL),
    CSRNAME_DECL(PWCH),
    CSRNAME_DECL(STLBPS),
    CSRNAME_DECL(RVACFG),
    CSRNAME_DECL(CPUID),
    CSRNAME_DECL(PRCFG1),
    CSRNAME_DECL(PRCFG2),
    CSRNAME_DECL(PRCFG3),
    CSRNAME_DECL(SAVE(0)),
    CSRNAME_DECL(SAVE(1)),
    CSRNAME_DECL(SAVE(2)),
    CSRNAME_DECL(SAVE(3)),
    CSRNAME_DECL(SAVE(4)),
    CSRNAME_DECL(SAVE(5)),
    CSRNAME_DECL(SAVE(6)),
    CSRNAME_DECL(SAVE(7)),
    CSRNAME_DECL(SAVE(8)),
    CSRNAME_DECL(SAVE(9)),
    CSRNAME_DECL(SAVE(10)),
    CSRNAME_DECL(SAVE(11)),
    CSRNAME_DECL(SAVE(12)),
    CSRNAME_DECL(SAVE(13)),
    CSRNAME_DECL(SAVE(14)),
    CSRNAME_DECL(SAVE(15)),
    CSRNAME_DECL(TID),
    CSRNAME_DECL(TCFG),
    CSRNAME_DECL(TVAL),
    CSRNAME_DECL(CNTC),
    CSRNAME_DECL(TICLR),
    CSRNAME_DECL(LLBCTL),
    CSRNAME_DECL(IMPCTL1),
    CSRNAME_DECL(IMPCTL2),
    CSRNAME_DECL(TLBRENTRY),
    CSRNAME_DECL(TLBRBADV),
    CSRNAME_DECL(TLBRERA),
    CSRNAME_DECL(TLBRSAVE),
    CSRNAME_DECL(TLBRELO0),
    CSRNAME_DECL(TLBRELO1),
    CSRNAME_DECL(TLBREHI),
    CSRNAME_DECL(TLBRPRMD),
    CSRNAME_DECL(MERRCTL),
    CSRNAME_DECL(MERRINFO1),
    CSRNAME_DECL(MERRINFO2),
    CSRNAME_DECL(MERRENTRY),
    CSRNAME_DECL(MERRERA),
    CSRNAME_DECL(MERRSAVE),
    CSRNAME_DECL(CTAG),
    CSRNAME_DECL(DMW(0)),
    CSRNAME_DECL(DMW(1)),
    CSRNAME_DECL(DMW(2)),
    CSRNAME_DECL(DMW(3)),
    CSRNAME_DECL(DBG),
    CSRNAME_DECL(DERA),
    CSRNAME_DECL(DSAVE),

};