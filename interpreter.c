#include "osdep.h"
#include "cpu.h"

#include "util.h"


#define __NOT_IMPLEMENTED__ do {fprintf(stderr, "NOT IMPLEMENTED %s, pc:%lx\n", __func__, env->pc); return false;} while(0);

#define DisasContext CPULoongArchState
#define ctx env
static inline int plus_1(DisasContext *ctx, int x)
{
    return x + 1;
}

static inline int shl_1(DisasContext *ctx, int x)
{
    return x << 1;
}

static inline int shl_2(DisasContext *ctx, int x)
{
    return x << 2;
}

static inline int shl_3(DisasContext *ctx, int x)
{
    return x << 3;
}
#include "trans_la.c.inc"



static bool trans_add_w(CPULoongArchState *env, arg_add_w *a) {
    env->gpr[a->rd] = (int64_t)(int32_t)(env->gpr[a->rj] + env->gpr[a->rk]);
    env->pc += 4;
    return true;
}
static bool trans_add_d(CPULoongArchState *env, arg_add_d *a) {
    env->gpr[a->rd] = env->gpr[a->rj] + env->gpr[a->rk];
    env->pc += 4;
    return true;
}
static bool trans_sub_w(CPULoongArchState *env, arg_sub_w *a) {
    env->gpr[a->rd] = (int64_t)(int32_t)(env->gpr[a->rj] - env->gpr[a->rk]);
    env->pc += 4;
    return true;
}
static bool trans_sub_d(CPULoongArchState *env, arg_sub_d *a) {
    env->gpr[a->rd] = env->gpr[a->rj] - env->gpr[a->rk];
    env->pc += 4;
    return true;
}
static bool trans_slt(CPULoongArchState *env, arg_slt *a) {
    env->gpr[a->rd] = (int64_t)env->gpr[a->rj] < (int64_t)env->gpr[a->rk];
    env->pc += 4;
    return true;
}
static bool trans_sltu(CPULoongArchState *env, arg_sltu *a) {
    env->gpr[a->rd] = (uint64_t)env->gpr[a->rj] < (uint64_t)env->gpr[a->rk];
    env->pc += 4;
    return true;
}
static bool trans_slti(CPULoongArchState *env, arg_slti *a) {
    env->gpr[a->rd] = (int64_t)env->gpr[a->rj] < (int64_t)a->imm;
    env->pc += 4;
    return true;
}
static bool trans_sltui(CPULoongArchState *env, arg_sltui *a) {
    env->gpr[a->rd] = (uint64_t)env->gpr[a->rj] < (uint64_t)(int64_t)a->imm;
    env->pc += 4;
    return true;
}
static bool trans_nor(CPULoongArchState *env, arg_nor *a) {
    env->gpr[a->rd] = ~(env->gpr[a->rj] | env->gpr[a->rk]);
    env->pc += 4;
    return true;
}
static bool trans_and(CPULoongArchState *env, arg_and *a) {
    env->gpr[a->rd] = env->gpr[a->rj] & env->gpr[a->rk];
    env->pc += 4;
    return true;
}
static bool trans_or(CPULoongArchState *env, arg_or *a) {
    env->gpr[a->rd] = env->gpr[a->rj] | env->gpr[a->rk];
    env->pc += 4;
    return true;
}
static bool trans_xor(CPULoongArchState *env, arg_xor *a) {
    env->gpr[a->rd] = env->gpr[a->rj] ^ env->gpr[a->rk];
    env->pc += 4;
    return true;
}

static bool trans_orn(CPULoongArchState *env, arg_orn *a) {
    env->gpr[a->rd] = env->gpr[a->rj] | ~ env->gpr[a->rk];
    env->pc += 4;
    return true;
}

static bool trans_andn(CPULoongArchState *env, arg_andn *a) {
    env->gpr[a->rd] = env->gpr[a->rj] & ~ env->gpr[a->rk];
    env->pc += 4;
    return true;
}

static bool trans_mul_w(CPULoongArchState *env, arg_mul_w *a) {
    env->gpr[a->rd] = (int64_t)((int32_t)env->gpr[a->rj] * (int32_t)env->gpr[a->rk]);
    env->pc += 4;
    return true;
}
static bool trans_mulh_w(CPULoongArchState *env, arg_mulh_w *a) {__NOT_IMPLEMENTED__}
static bool trans_mulh_wu(CPULoongArchState *env, arg_mulh_wu *a) {__NOT_IMPLEMENTED__}
static bool trans_mul_d(CPULoongArchState *env, arg_mul_d *a) {
    env->gpr[a->rd] = (int64_t)env->gpr[a->rj] * (int64_t)env->gpr[a->rk];
    env->pc += 4;
    return true;
}
static bool trans_mulh_d(CPULoongArchState *env, arg_mulh_d *a) {__NOT_IMPLEMENTED__}
static bool trans_mulh_du(CPULoongArchState *env, arg_mulh_du *a) {
    uint64_t high,low;
    mulu64(&low, &high, env->gpr[a->rj], env->gpr[a->rk]);
    env->gpr[a->rd] = high;
    env->pc += 4;
    return true;
}
static bool trans_mulw_d_w(CPULoongArchState *env, arg_mulw_d_w *a) {__NOT_IMPLEMENTED__}
static bool trans_mulw_d_wu(CPULoongArchState *env, arg_mulw_d_wu *a) {__NOT_IMPLEMENTED__}
static bool trans_div_w(CPULoongArchState *env, arg_div_w *a) {
    env->gpr[a->rd] = (int32_t)env->gpr[a->rj] / (int32_t)env->gpr[a->rk];
    env->pc += 4;
    return true;
}
static bool trans_mod_w(CPULoongArchState *env, arg_mod_w *a) {
    env->gpr[a->rd] = (int32_t)env->gpr[a->rj] % (int32_t)env->gpr[a->rk];
    env->pc += 4;
    return true;
}
static bool trans_div_wu(CPULoongArchState *env, arg_div_wu *a) {
    env->gpr[a->rd] = (uint32_t)env->gpr[a->rj] / (uint32_t)env->gpr[a->rk];
    env->pc += 4;
    return true;
}
static bool trans_mod_wu(CPULoongArchState *env, arg_mod_wu *a) {
    env->gpr[a->rd] = (uint32_t)env->gpr[a->rj] % (uint32_t)env->gpr[a->rk];
    env->pc += 4;
    return true;
}
static bool trans_div_d(CPULoongArchState *env, arg_div_d *a) {
    env->gpr[a->rd] = (int64_t)env->gpr[a->rj] / (int64_t)env->gpr[a->rk];
    env->pc += 4;
    return true;
}
static bool trans_mod_d(CPULoongArchState *env, arg_mod_d *a) {__NOT_IMPLEMENTED__}
static bool trans_div_du(CPULoongArchState *env, arg_div_du *a) {
    env->gpr[a->rd] = (uint64_t)env->gpr[a->rj] / (uint64_t)env->gpr[a->rk];
    env->pc += 4;
    return true;
}
static bool trans_mod_du(CPULoongArchState *env, arg_mod_du *a) {
    env->gpr[a->rd] = (uint64_t)env->gpr[a->rj] % (uint64_t)env->gpr[a->rk];
    env->pc += 4;
    return true;
}
static bool trans_alsl_w(CPULoongArchState *env, arg_alsl_w *a) {
    env->gpr[a->rd] = (int64_t)(int32_t)((env->gpr[a->rj] << a->sa) + env->gpr[a->rk]);
    env->pc += 4;
    return true;
}
static bool trans_alsl_wu(CPULoongArchState *env, arg_alsl_wu *a) {
    env->gpr[a->rd] = (uint32_t)((env->gpr[a->rj] << a->sa) + env->gpr[a->rk]);
    env->pc += 4;
    return true;
}
static bool trans_alsl_d(CPULoongArchState *env, arg_alsl_d *a) {
    env->gpr[a->rd] = (env->gpr[a->rj] << a->sa) + env->gpr[a->rk];
    env->pc += 4;
    return true;
}
static bool trans_lu12i_w(CPULoongArchState *env, arg_lu12i_w *a) {
    env->gpr[a->rd] = (int64_t)(a->imm << 12);
    env->pc += 4;
    return true;
}
static bool trans_lu32i_d(CPULoongArchState *env, arg_lu32i_d *a) {
    env->gpr[a->rd] = (uint64_t)(uint32_t)env->gpr[a->rd] | ((int64_t)a->imm << 32);
    env->pc += 4;
    return true;
}
static bool trans_lu52i_d(CPULoongArchState *env, arg_lu52i_d *a) {
    env->gpr[a->rd] = deposit64(env->gpr[a->rj], 52, 12, a->imm);
    env->pc += 4;
    return true;
}
static bool trans_pcaddi(CPULoongArchState *env, arg_pcaddi *a) {
    env->gpr[a->rd] = env->pc + (a->imm << 2);
    env->pc += 4;
    return true;
}
static bool trans_pcalau12i(CPULoongArchState *env, arg_pcalau12i *a) {
    env->gpr[a->rd] = env->pc + (a->imm << 12);
    env->gpr[a->rd] &= ~0xfffull;
    env->pc += 4;
    return true;
}
static bool trans_pcaddu12i(CPULoongArchState *env, arg_pcaddu12i *a) {
    env->gpr[a->rd] = env->pc + (a->imm << 12);
    env->pc += 4;
    return true;
}
static bool trans_pcaddu18i(CPULoongArchState *env, arg_pcaddu18i *a) {__NOT_IMPLEMENTED__}
static bool trans_addi_w(CPULoongArchState *env, arg_addi_w *a) {
    env->gpr[a->rd] = (int64_t)(int32_t)(env->gpr[a->rj] + a->imm);
    env->pc += 4;
    return true;
}
static bool trans_addi_d(CPULoongArchState *env, arg_addi_d *a) {
    env->gpr[a->rd] = env->gpr[a->rj] + a->imm;
    env->pc += 4;
    return true;
}
static bool trans_addu16i_d(CPULoongArchState *env, arg_addu16i_d *a) {
    env->gpr[a->rd] = env->gpr[a->rj] + (a->imm << 16);
    env->pc += 4;
    return true;
}
static bool trans_andi(CPULoongArchState *env, arg_andi *a) {
    env->gpr[a->rd] = env->gpr[a->rj] & a->imm;
    env->pc += 4;
    return true;
}
static bool trans_ori(CPULoongArchState *env, arg_ori *a) {
    env->gpr[a->rd] = env->gpr[a->rj] | a->imm;
    env->pc += 4;
    return true;
}
static bool trans_xori(CPULoongArchState *env, arg_xori *a) {
    env->gpr[a->rd] = env->gpr[a->rj] ^ a->imm;
    env->pc += 4;
    return true;
}
static bool trans_sll_w(CPULoongArchState *env, arg_sll_w *a) {
    env->gpr[a->rd] = (int64_t)((int32_t)env->gpr[a->rj] << (env->gpr[a->rk] & 0x1f));
    env->pc += 4;
    return true;
}
static bool trans_srl_w(CPULoongArchState *env, arg_srl_w *a) {
    env->gpr[a->rd] = (int64_t)(int32_t)((uint32_t)env->gpr[a->rj] >> (env->gpr[a->rk] & 0x1f));
    env->pc += 4;
    return true;
}
static bool trans_sra_w(CPULoongArchState *env, arg_sra_w *a) {
    env->gpr[a->rd] = (int64_t)((int32_t)env->gpr[a->rj] >> (env->gpr[a->rk] & 0x1f));
    env->pc += 4;
    return true;
}
static bool trans_sll_d(CPULoongArchState *env, arg_sll_d *a) {
    env->gpr[a->rd] = env->gpr[a->rj] << (env->gpr[a->rk] & 0x3f);
    env->pc += 4;
    return true;
}
static bool trans_srl_d(CPULoongArchState *env, arg_srl_d *a) {
    env->gpr[a->rd] = (uint64_t)env->gpr[a->rj] >> (env->gpr[a->rk] & 0x3f);
    env->pc += 4;
    return true;
}
static bool trans_sra_d(CPULoongArchState *env, arg_sra_d *a) {
    env->gpr[a->rd] = (int64_t)env->gpr[a->rj] >> (env->gpr[a->rk] & 0x3f);
    env->pc += 4;
    return true;
}
static bool trans_rotr_w(CPULoongArchState *env, arg_rotr_w *a) {
    uint32_t rj = env->gpr[a->rj];
    int imm = env->gpr[a->rk] & 0x1f;
    env->gpr[a->rd] = (int64_t)(int32_t)((rj >> imm) | (rj << (32 - imm)));
    env->pc += 4;
    return true;
}
static bool trans_rotr_d(CPULoongArchState *env, arg_rotr_d *a) {
    uint64_t rj = env->gpr[a->rj];
    int imm = env->gpr[a->rk] & 0x3f;
    env->gpr[a->rd] = (rj >> imm) | (rj << (64 - imm));
    env->pc += 4;
    return true;
}
static bool trans_slli_w(CPULoongArchState *env, arg_slli_w *a) {
    env->gpr[a->rd] = (int64_t)((int32_t)env->gpr[a->rj] << a->imm);
    env->pc += 4;
    return true;
}
static bool trans_slli_d(CPULoongArchState *env, arg_slli_d *a) {
    env->gpr[a->rd] = env->gpr[a->rj] << a->imm;
    env->pc += 4;
    return true;
}
static bool trans_srli_w(CPULoongArchState *env, arg_srli_w *a) {
    env->gpr[a->rd] = (int64_t)((uint32_t)env->gpr[a->rj] >> a->imm);
    env->pc += 4;
    return true;
}
static bool trans_srli_d(CPULoongArchState *env, arg_srli_d *a) {
    env->gpr[a->rd] = env->gpr[a->rj] >> a->imm;
    env->pc += 4;
    return true;
}
static bool trans_srai_w(CPULoongArchState *env, arg_srai_w *a) {
    env->gpr[a->rd] = (int64_t)((int32_t)env->gpr[a->rj] >> a->imm);
    env->pc += 4;
    return true;
}
static bool trans_srai_d(CPULoongArchState *env, arg_srai_d *a) {
    env->gpr[a->rd] = (int64_t)env->gpr[a->rj] >> a->imm;
    env->pc += 4;
    return true;
}
static bool trans_rotri_w(CPULoongArchState *env, arg_rotri_w *a) {
    uint32_t rj = env->gpr[a->rj];
    int imm = a->imm & 0x1f;
    env->gpr[a->rd] = (int64_t)(int32_t)((rj >> imm) | (rj << (32 - imm)));
    env->pc += 4;
    return true;
}
static bool trans_rotri_d(CPULoongArchState *env, arg_rotri_d *a) {
    uint64_t rj = env->gpr[a->rj];
    int imm = a->imm & 0x3f;
    env->gpr[a->rd] = (rj >> imm) | (rj << (64 - imm));
    env->pc += 4;
    return true;
}
static bool trans_ext_w_h(CPULoongArchState *env, arg_ext_w_h *a) {
    env->gpr[a->rd] = (int64_t)(int16_t)env->gpr[a->rj];
    env->pc += 4;
    return true;
}
static bool trans_ext_w_b(CPULoongArchState *env, arg_ext_w_b *a) {
    env->gpr[a->rd] = (int64_t)(int8_t)env->gpr[a->rj];
    env->pc += 4;
    return true;
}
static bool trans_clo_w(CPULoongArchState *env, arg_clo_w *a) {
    env->gpr[a->rd] = env->gpr[a->rj] ? clo32(env->gpr[a->rj]) : 32;
    env->pc += 4;
    return true;
}
static bool trans_clz_w(CPULoongArchState *env, arg_clz_w *a) {
    env->gpr[a->rd] = env->gpr[a->rj] ? clz32(env->gpr[a->rj]) : 32;
    env->pc += 4;
    return true;
}
static bool trans_cto_w(CPULoongArchState *env, arg_cto_w *a) {
    env->gpr[a->rd] = env->gpr[a->rj] ? cto32(env->gpr[a->rj]) : 32;
    env->pc += 4;
    return true;
}
static bool trans_ctz_w(CPULoongArchState *env, arg_ctz_w *a) {
    env->gpr[a->rd] = env->gpr[a->rj] ? ctz32(env->gpr[a->rj]) : 32;
    env->pc += 4;
    return true;
}
static bool trans_clo_d(CPULoongArchState *env, arg_clo_d *a) {
    env->gpr[a->rd] = env->gpr[a->rj] ? clo64(env->gpr[a->rj]) : 64;
    env->pc += 4;
    return true;
}
static bool trans_clz_d(CPULoongArchState *env, arg_clz_d *a) {
    env->gpr[a->rd] = env->gpr[a->rj] ? clz64(env->gpr[a->rj]) : 64;
    env->pc += 4;
    return true;
}
static bool trans_cto_d(CPULoongArchState *env, arg_cto_d *a) {
    env->gpr[a->rd] = env->gpr[a->rj] ? cto64(env->gpr[a->rj]) : 64;
    env->pc += 4;
    return true;
}
static bool trans_ctz_d(CPULoongArchState *env, arg_ctz_d *a) {
    env->gpr[a->rd] = env->gpr[a->rj] ? ctz64(env->gpr[a->rj]) : 64;
    env->pc += 4;
    return true;
}
static bool trans_revb_2h(CPULoongArchState *env, arg_revb_2h *a) {
    uint32_t mask = 0x00FF00FF;
    uint32_t rj = env->gpr[a->rj];
    env->gpr[a->rd] = (int64_t)(int32_t)(((rj >> 8) & mask) | ((rj & mask ) << 8));
    env->pc += 4;
    return true;
}
static bool trans_revb_4h(CPULoongArchState *env, arg_revb_4h *a) {
    uint64_t mask = 0x00FF00FF00FF00FFULL;
    uint64_t rj = env->gpr[a->rj];
    env->gpr[a->rd] = ((rj >> 8) & mask) | ((rj & mask ) << 8);
    env->pc += 4;
    return true;
}
static bool trans_revb_2w(CPULoongArchState *env, arg_revb_2w *a) {__NOT_IMPLEMENTED__}
static bool trans_revb_d(CPULoongArchState *env, arg_revb_d *a) {__NOT_IMPLEMENTED__}
static bool trans_revh_2w(CPULoongArchState *env, arg_revh_2w *a) {__NOT_IMPLEMENTED__}
static bool trans_revh_d(CPULoongArchState *env, arg_revh_d *a) {
    uint64_t mask = 0x0000FFFF0000FFFFULL;
    uint64_t rj = env->gpr[a->rj];
    uint64_t t = ((rj >> 16) & mask) | ((rj & mask ) << 16);
    env->gpr[a->rd] = (t >> 32) | (t << 32);
    env->pc += 4;
    return true;
}
static bool trans_bitrev_4b(CPULoongArchState *env, arg_bitrev_4b *a) {__NOT_IMPLEMENTED__}
static bool trans_bitrev_8b(CPULoongArchState *env, arg_bitrev_8b *a) {__NOT_IMPLEMENTED__}
static bool trans_bitrev_w(CPULoongArchState *env, arg_bitrev_w *a) {__NOT_IMPLEMENTED__}
static bool trans_bitrev_d(CPULoongArchState *env, arg_bitrev_d *a) {__NOT_IMPLEMENTED__}
static bool trans_bytepick_w(CPULoongArchState *env, arg_bytepick_w *a) {__NOT_IMPLEMENTED__}
static bool trans_bytepick_d(CPULoongArchState *env, arg_bytepick_d *a) {__NOT_IMPLEMENTED__}
static bool trans_maskeqz(CPULoongArchState *env, arg_maskeqz *a) {
    env->gpr[a->rd] = env->gpr[a->rk] == 0 ? 0 : env->gpr[a->rj];
    env->pc += 4;
    return true;
}
static bool trans_masknez(CPULoongArchState *env, arg_masknez *a) {
    env->gpr[a->rd] = env->gpr[a->rk] != 0 ? 0 : env->gpr[a->rj];
    env->pc += 4;
    return true;
}
static bool trans_bstrins_w(CPULoongArchState *env, arg_bstrins_w *a)  {
    env->gpr[a->rd] = (int64_t)(int32_t)deposit32(env->gpr[a->rd], a->ls, a->ms - a->ls + 1, env->gpr[a->rj]);
    env->pc += 4;
    return true;
}
static bool trans_bstrpick_w(CPULoongArchState *env, arg_bstrpick_w *a) {
    if (a->ls > a->ms) {
        return false;
    }
    env->gpr[a->rd] = (int64_t)extract32(env->gpr[a->rj], a->ls, a->ms - a->ls + 1);
    env->pc += 4;
    return true;
}
static bool trans_bstrins_d(CPULoongArchState *env, arg_bstrins_d *a) {
    env->gpr[a->rd] = deposit64(env->gpr[a->rd], a->ls, a->ms - a->ls + 1, env->gpr[a->rj]);
    env->pc += 4;
    return true;
}
static bool trans_bstrpick_d(CPULoongArchState *env, arg_bstrpick_d *a) {
    if (a->ls > a->ms) {
        return false;
    }
    env->gpr[a->rd] = extract64(env->gpr[a->rj], a->ls, a->ms - a->ls + 1);
    env->pc += 4;
    return true;
}



static hwaddr load_pa(CPULoongArchState *env, uint64_t addr) {
    hwaddr ha;
    int prot;
    int mmu_idx = FIELD_EX64(env->CSR_CRMD, CSR_CRMD, PLV) == 0 ? MMU_IDX_KERNEL : MMU_IDX_USER;
    int r = check_get_physical_address(env, &ha, &prot, addr, MMU_DATA_LOAD, mmu_idx);
    // printf("va:%lx,pa:%lx\n", addr, ha);
        if (addr == 0xfffffefffe0510b0) {
        printf("load:va:%lx,pa:%lx\n", addr, ha);
    }
    return ha;
}
static hwaddr store_pa(CPULoongArchState *env, uint64_t addr) {
    if (addr == 0xfffffefffe0510b0) {
        printf("store_pa1 %lx addr:%lx\n", env->pc, addr);
    }

    if ((addr & ~0xf) == 0xfffffefffe0510b0) {
        printf("store_pa2 %lx addr:%lx\n", env->pc, addr);
    }

    if ((addr & ~0xf) == 0xfffffefffe0510a0) {
        printf("store_pa3 %lx addr:%lx\n", env->pc, addr);
    }

    hwaddr ha;
    int prot;
    int mmu_idx = FIELD_EX64(env->CSR_CRMD, CSR_CRMD, PLV) == 0 ? MMU_IDX_KERNEL : MMU_IDX_USER;
    int r = check_get_physical_address(env, &ha, &prot, addr, MMU_DATA_STORE, mmu_idx);
    if (addr == 0xfffffefffe0510b0) {
        printf("store:va:%lx,pa:%lx\n", addr, ha);
    }
    if (ha == 0x15e0510b0) {
        printf("store:va:%lx,pa:%lx\n", addr, ha);
    }
    return ha;
}
static bool is_io(hwaddr ha) {
    return ha >= 0x10000000 && ha < 0x90000000;
}
static void do_io_st(hwaddr ha, uint64_t data, int size) {
    switch (ha)
    {
    case 0x1fe002e0:
            printf("%c", (char)(data));
        break;
    
    default:
        fprintf(stderr, "do_io_st, addr:%lx, data:%lx, size:%d", ha, data, size);
        // assert(0);
    }
}
static uint64_t do_io_ld(hwaddr ha, int size) {
    uint64_t data;
    switch (ha)
    {
    case 0x1fe00120:
            data = 'a';
        break;
    default:
        break;
    }
    return data;
}
static bool trans_ld_b(CPULoongArchState *env, arg_ld_b *a) {
    hwaddr ha = load_pa(env, env->gpr[a->rj] + a->imm);
    env->gpr[a->rd] = is_io(ha) ? do_io_ld(ha, 1) : ram_ldb(ram, ha);
    env->pc += 4;
    return true;
}
static bool trans_ld_h(CPULoongArchState *env, arg_ld_h *a) {
    hwaddr ha = load_pa(env, env->gpr[a->rj] + a->imm);
    env->gpr[a->rd] = is_io(ha) ? do_io_ld(ha, 2) : ram_ldh(ram, ha);
    env->pc += 4;
    return true;
}
static bool trans_ld_w(CPULoongArchState *env, arg_ld_w *a) {
    hwaddr ha = load_pa(env, env->gpr[a->rj] + a->imm);
    env->gpr[a->rd] = is_io(ha) ? do_io_ld(ha, 4) : ram_ldw(ram, ha);
    env->pc += 4;
    return true;
}
static bool trans_ld_d(CPULoongArchState *env, arg_ld_d *a) {
    hwaddr ha = load_pa(env, env->gpr[a->rj] + a->imm);
    env->gpr[a->rd] = is_io(ha) ? do_io_ld(ha, 8) : ram_ldd(ram, ha);
    env->pc += 4;
    return true;
}

static bool trans_st_b(CPULoongArchState *env, arg_st_b *a) {
    hwaddr ha = store_pa(env, env->gpr[a->rj] + a->imm);
    is_io(ha) ? do_io_st(ha, env->gpr[a->rd], 1) : ram_stb(ram, ha, env->gpr[a->rd]);
    env->pc += 4;
    return true;
}
static bool trans_st_h(CPULoongArchState *env, arg_st_h *a) {
    hwaddr ha = store_pa(env, env->gpr[a->rj] + a->imm);
    is_io(ha) ? do_io_st(ha, env->gpr[a->rd], 2) : ram_sth(ram, ha, env->gpr[a->rd]);
    env->pc += 4;
    return true;
}
static bool trans_st_w(CPULoongArchState *env, arg_st_w *a) {
    hwaddr ha = store_pa(env, env->gpr[a->rj] + a->imm);
    is_io(ha) ? do_io_st(ha, env->gpr[a->rd], 4) : ram_stw(ram, ha, env->gpr[a->rd]);
    env->pc += 4;
    return true;
}
static bool trans_st_d(CPULoongArchState *env, arg_st_d *a) {
    hwaddr ha = store_pa(env, env->gpr[a->rj] + a->imm);
    is_io(ha) ? do_io_st(ha, env->gpr[a->rd], 8) : ram_std(ram, ha, env->gpr[a->rd]);
    env->pc += 4;
    return true;
}
static bool trans_ld_bu(CPULoongArchState *env, arg_ld_bu *a) {
    hwaddr ha = load_pa(env, env->gpr[a->rj] + a->imm);
    env->gpr[a->rd] = is_io(ha) ? do_io_ld(ha, 1) : ram_ldub(ram, ha);
    env->pc += 4;
    return true;
}
static bool trans_ld_hu(CPULoongArchState *env, arg_ld_hu *a) {
    hwaddr ha = load_pa(env, env->gpr[a->rj] + a->imm);
    env->gpr[a->rd] = is_io(ha) ? do_io_ld(ha, 2) : ram_lduh(ram, ha);
    env->pc += 4;
    return true;
}
static bool trans_ld_wu(CPULoongArchState *env, arg_ld_wu *a) {
    hwaddr ha = load_pa(env, env->gpr[a->rj] + a->imm);
    env->gpr[a->rd] = is_io(ha) ? do_io_ld(ha, 4) : ram_lduw(ram, ha);
    env->pc += 4;
    return true;
}
static bool trans_ldx_b(CPULoongArchState *env, arg_ldx_b *a) {
    hwaddr ha = load_pa(env, env->gpr[a->rj] + env->gpr[a->rk]);
    env->gpr[a->rd] = is_io(ha) ? do_io_ld(ha, 1) : ram_ldb(ram, ha);
    env->pc += 4;
    return true;
}
static bool trans_ldx_h(CPULoongArchState *env, arg_ldx_h *a) {
    hwaddr ha = load_pa(env, env->gpr[a->rj] + env->gpr[a->rk]);
    env->gpr[a->rd] = is_io(ha) ? do_io_ld(ha, 2) : ram_ldh(ram, ha);
    env->pc += 4;
    return true;
}
static bool trans_ldx_w(CPULoongArchState *env, arg_ldx_w *a) {
    hwaddr ha = load_pa(env, env->gpr[a->rj] + env->gpr[a->rk]);
    env->gpr[a->rd] = is_io(ha) ? do_io_ld(ha, 4) : ram_ldw(ram, ha);
    env->pc += 4;
    return true;
}
static bool trans_ldx_d(CPULoongArchState *env, arg_ldx_d *a) {
    hwaddr ha = load_pa(env, env->gpr[a->rj] + env->gpr[a->rk]);
    env->gpr[a->rd] = is_io(ha) ? do_io_ld(ha, 8) : ram_ldd(ram, ha);
    env->pc += 4;
    return true;
}
static bool trans_stx_b(CPULoongArchState *env, arg_stx_b *a) {
    hwaddr ha = store_pa(env, env->gpr[a->rj] + env->gpr[a->rk]);
    is_io(ha) ? do_io_st(ha, env->gpr[a->rd], 1) : ram_stb(ram, ha, env->gpr[a->rd]);
    env->pc += 4;
    return true;
}
static bool trans_stx_h(CPULoongArchState *env, arg_stx_h *a) {
    hwaddr ha = store_pa(env, env->gpr[a->rj] + env->gpr[a->rk]);
    is_io(ha) ? do_io_st(ha, env->gpr[a->rd], 2) : ram_sth(ram, ha, env->gpr[a->rd]);
    env->pc += 4;
    return true;
}
static bool trans_stx_w(CPULoongArchState *env, arg_stx_w *a) {
    hwaddr ha = store_pa(env, env->gpr[a->rj] + env->gpr[a->rk]);
    is_io(ha) ? do_io_st(ha, env->gpr[a->rd], 4) : ram_stw(ram, ha, env->gpr[a->rd]);
    env->pc += 4;
    return true;
}
static bool trans_stx_d(CPULoongArchState *env, arg_stx_d *a) {
    hwaddr ha = store_pa(env, env->gpr[a->rj] + env->gpr[a->rk]);
    is_io(ha) ? do_io_st(ha, env->gpr[a->rd], 8) : ram_std(ram, ha, env->gpr[a->rd]);
    env->pc += 4;
    return true;
}
static bool trans_ldx_bu(CPULoongArchState *env, arg_ldx_bu *a) {
    hwaddr ha = load_pa(env, env->gpr[a->rj] + env->gpr[a->rk]);
    env->gpr[a->rd] = is_io(ha) ? do_io_ld(ha, 1) : ram_ldub(ram, ha);
    env->pc += 4;
    return true;
}
static bool trans_ldx_hu(CPULoongArchState *env, arg_ldx_hu *a) {
    hwaddr ha = load_pa(env, env->gpr[a->rj] + env->gpr[a->rk]);
    env->gpr[a->rd] = is_io(ha) ? do_io_ld(ha, 2) : ram_lduh(ram, ha);
    env->pc += 4;
    return true;
}
static bool trans_ldx_wu(CPULoongArchState *env, arg_ldx_wu *a) {
    hwaddr ha = load_pa(env, env->gpr[a->rj] + env->gpr[a->rk]);
    env->gpr[a->rd] = is_io(ha) ? do_io_ld(ha, 4) : ram_lduw(ram, ha);
    env->pc += 4;
    return true;
}
static bool trans_preld(CPULoongArchState *env, arg_preld *a) {__NOT_IMPLEMENTED__}
static bool trans_dbar(CPULoongArchState *env, arg_dbar *a) {
    env->pc += 4;
    return true;
}
static bool trans_ibar(CPULoongArchState *env, arg_ibar *a) {
    env->pc += 4;
    return true;
}
static bool trans_ldptr_w(CPULoongArchState *env, arg_ldptr_w *a) {
    hwaddr ha = load_pa(env, env->gpr[a->rj] + a->imm);
    env->gpr[a->rd] = is_io(ha) ? do_io_ld(ha, 4) : ram_ldw(ram, ha);
    env->pc += 4;
    return true;
}
static bool trans_stptr_w(CPULoongArchState *env, arg_stptr_w *a) {
    hwaddr ha = store_pa(env, env->gpr[a->rj] + a->imm);
    is_io(ha) ? do_io_st(ha, env->gpr[a->rd], 4) : ram_stw(ram, ha, env->gpr[a->rd]);
    env->pc += 4;
    return true;
}
static bool trans_ldptr_d(CPULoongArchState *env, arg_ldptr_d *a) {
    hwaddr ha = load_pa(env, env->gpr[a->rj] + a->imm);
    env->gpr[a->rd] = is_io(ha) ? do_io_ld(ha, 8) : ram_ldd(ram, ha);
    env->pc += 4;
    return true;
}
static bool trans_stptr_d(CPULoongArchState *env, arg_stptr_d *a) {
    hwaddr ha = store_pa(env, env->gpr[a->rj] + a->imm);
    is_io(ha) ? do_io_st(ha, env->gpr[a->rd], 8) : ram_std(ram, ha, env->gpr[a->rd]);
    env->pc += 4;
    return true;
}
static bool trans_ldgt_b(CPULoongArchState *env, arg_ldgt_b *a) {__NOT_IMPLEMENTED__}
static bool trans_ldgt_h(CPULoongArchState *env, arg_ldgt_h *a) {__NOT_IMPLEMENTED__}
static bool trans_ldgt_w(CPULoongArchState *env, arg_ldgt_w *a) {__NOT_IMPLEMENTED__}
static bool trans_ldgt_d(CPULoongArchState *env, arg_ldgt_d *a) {__NOT_IMPLEMENTED__}
static bool trans_ldle_b(CPULoongArchState *env, arg_ldle_b *a) {__NOT_IMPLEMENTED__}
static bool trans_ldle_h(CPULoongArchState *env, arg_ldle_h *a) {__NOT_IMPLEMENTED__}
static bool trans_ldle_w(CPULoongArchState *env, arg_ldle_w *a) {__NOT_IMPLEMENTED__}
static bool trans_ldle_d(CPULoongArchState *env, arg_ldle_d *a) {__NOT_IMPLEMENTED__}
static bool trans_stgt_b(CPULoongArchState *env, arg_stgt_b *a) {__NOT_IMPLEMENTED__}
static bool trans_stgt_h(CPULoongArchState *env, arg_stgt_h *a) {__NOT_IMPLEMENTED__}
static bool trans_stgt_w(CPULoongArchState *env, arg_stgt_w *a) {__NOT_IMPLEMENTED__}
static bool trans_stgt_d(CPULoongArchState *env, arg_stgt_d *a) {__NOT_IMPLEMENTED__}
static bool trans_stle_b(CPULoongArchState *env, arg_stle_b *a) {__NOT_IMPLEMENTED__}
static bool trans_stle_h(CPULoongArchState *env, arg_stle_h *a) {__NOT_IMPLEMENTED__}
static bool trans_stle_w(CPULoongArchState *env, arg_stle_w *a) {__NOT_IMPLEMENTED__}
static bool trans_stle_d(CPULoongArchState *env, arg_stle_d *a) {__NOT_IMPLEMENTED__}
static bool trans_ll_w(CPULoongArchState *env, arg_ll_w *a) {
    hwaddr ha = load_pa(env, env->gpr[a->rj] + a->imm);
    env->gpr[a->rd] = is_io(ha) ? do_io_ld(ha, 4) : ram_ldw(ram, ha);
    env->pc += 4;
    return true;
}
static bool trans_sc_w(CPULoongArchState *env, arg_sc_w *a) {
    hwaddr ha = store_pa(env, env->gpr[a->rj] + a->imm);
    ram_stw(ram, ha, env->gpr[a->rd]);
    env->gpr[a->rd] = 1;
    env->pc += 4;
    return true;
}
static bool trans_ll_d(CPULoongArchState *env, arg_ll_d *a) {
    hwaddr ha = load_pa(env, env->gpr[a->rj] + a->imm);
    env->gpr[a->rd] = ram_ldd(ram, ha);
    env->pc += 4;
    return true;
}
static bool trans_sc_d(CPULoongArchState *env, arg_sc_d *a) {
    hwaddr ha = store_pa(env, env->gpr[a->rj] + a->imm);
    ram_std(ram, ha, env->gpr[a->rd]);
    env->gpr[a->rd] = 1;
    env->pc += 4;
    return true;
}
static bool trans_amswap_w(CPULoongArchState *env, arg_amswap_w *a) {return trans_amswap_db_w(env, a);}
static bool trans_amswap_d(CPULoongArchState *env, arg_amswap_d *a) {return trans_amswap_db_d(env, a);}
static bool trans_amadd_w(CPULoongArchState *env, arg_amadd_w *a) {return trans_amadd_db_w(env, a);}
static bool trans_amadd_d(CPULoongArchState *env, arg_amadd_d *a) {return trans_amadd_db_d(env, a);}
static bool trans_amand_w(CPULoongArchState *env, arg_amand_w *a) {return trans_amand_db_w(env, a);}
static bool trans_amand_d(CPULoongArchState *env, arg_amand_d *a) {return trans_amand_db_d(env, a);}
static bool trans_amor_w(CPULoongArchState *env, arg_amor_w *a) {return trans_amor_db_w(env, a);}
static bool trans_amor_d(CPULoongArchState *env, arg_amor_d *a) {return trans_amor_db_d(env, a);}
static bool trans_amxor_w(CPULoongArchState *env, arg_amxor_w *a) {return trans_amxor_db_w(env, a);}
static bool trans_amxor_d(CPULoongArchState *env, arg_amxor_d *a) {return trans_amxor_db_d(env, a);}
static bool trans_ammax_w(CPULoongArchState *env, arg_ammax_w *a) {return trans_ammax_db_w(env, a);}
static bool trans_ammax_d(CPULoongArchState *env, arg_ammax_d *a) {return trans_ammax_db_d(env, a);}
static bool trans_ammin_w(CPULoongArchState *env, arg_ammin_w *a) {return trans_ammin_db_w(env, a);}
static bool trans_ammin_d(CPULoongArchState *env, arg_ammin_d *a) {return trans_ammin_db_d(env, a);}
static bool trans_ammax_wu(CPULoongArchState *env, arg_ammax_wu *a) {return trans_ammax_db_wu(env, a);}
static bool trans_ammax_du(CPULoongArchState *env, arg_ammax_du *a) {return trans_ammax_db_du(env, a);}
static bool trans_ammin_wu(CPULoongArchState *env, arg_ammin_wu *a) {return trans_ammin_db_wu(env, a);}
static bool trans_ammin_du(CPULoongArchState *env, arg_ammin_du *a) {return trans_ammin_db_du(env, a);}
static bool trans_amswap_db_w(CPULoongArchState *env, arg_amswap_db_w *a) {
    hwaddr ha = store_pa(env, env->gpr[a->rj]);
    int32_t old_v = ram_ldw(ram, ha);
    ram_stw(ram, ha, env->gpr[a->rk]);
    env->gpr[a->rd] = (int64_t)old_v;
    env->pc += 4;
    return true;
}
static bool trans_amswap_db_d(CPULoongArchState *env, arg_amswap_db_d *a) {
    hwaddr ha = store_pa(env, env->gpr[a->rj]);
    int64_t old_v = ram_ldd(ram, ha);
    ram_std(ram, ha, env->gpr[a->rk]);
    env->gpr[a->rd] = old_v;
    env->pc += 4;
    return true;
}
static bool trans_amadd_db_w(CPULoongArchState *env, arg_amadd_db_w *a) {
    hwaddr ha = store_pa(env, env->gpr[a->rj]);
    int32_t old_v = ram_ldw(ram, ha);
    int32_t new_v = env->gpr[a->rk] + old_v;
    ram_stw(ram, ha, new_v);
    env->gpr[a->rd] = (int64_t)old_v;
    env->pc += 4;
    return true;
}
static bool trans_amadd_db_d(CPULoongArchState *env, arg_amadd_db_d *a) {
    hwaddr ha = store_pa(env, env->gpr[a->rj]);
    int64_t old_v = ram_ldd(ram, ha);
    int64_t new_v = env->gpr[a->rk] + old_v;
    ram_std(ram, ha, new_v);
    env->gpr[a->rd] = (int64_t)old_v;
    env->pc += 4;
    return true;
}
static bool trans_amand_db_w(CPULoongArchState *env, arg_amand_db_w *a) {
    hwaddr ha = store_pa(env, env->gpr[a->rj]);
    int32_t old_v = ram_ldw(ram, ha);
    int32_t new_v = env->gpr[a->rk] & old_v;
    ram_stw(ram, ha, new_v);
    env->gpr[a->rd] = (int64_t)old_v;
    env->pc += 4;
    return true;
}
static bool trans_amand_db_d(CPULoongArchState *env, arg_amand_db_d *a) {
    hwaddr ha = store_pa(env, env->gpr[a->rj]);
    int64_t old_v = ram_ldd(ram, ha);
    int64_t new_v = env->gpr[a->rk] & old_v;
    ram_std(ram, ha, new_v);
    env->gpr[a->rd] = (int64_t)old_v;
    env->pc += 4;
    return true;
}
static bool trans_amor_db_w(CPULoongArchState *env, arg_amor_db_w *a) {
    hwaddr ha = store_pa(env, env->gpr[a->rj]);
    int32_t old_v = ram_ldw(ram, ha);
    int32_t new_v = env->gpr[a->rk] | old_v;
    ram_stw(ram, ha, new_v);
    env->gpr[a->rd] = (int64_t)old_v;
    env->pc += 4;
    return true;
}
static bool trans_amor_db_d(CPULoongArchState *env, arg_amor_db_d *a) {
    hwaddr ha = store_pa(env, env->gpr[a->rj]);
    int64_t old_v = ram_ldd(ram, ha);
    int64_t new_v = env->gpr[a->rk] | old_v;
    ram_std(ram, ha, new_v);
    env->gpr[a->rd] = (int64_t)old_v;
    env->pc += 4;
    return true;
}
static bool trans_amxor_db_w(CPULoongArchState *env, arg_amxor_db_w *a) {__NOT_IMPLEMENTED__}
static bool trans_amxor_db_d(CPULoongArchState *env, arg_amxor_db_d *a) {__NOT_IMPLEMENTED__}
static bool trans_ammax_db_w(CPULoongArchState *env, arg_ammax_db_w *a) {__NOT_IMPLEMENTED__}
static bool trans_ammax_db_d(CPULoongArchState *env, arg_ammax_db_d *a) {__NOT_IMPLEMENTED__}
static bool trans_ammin_db_w(CPULoongArchState *env, arg_ammin_db_w *a) {__NOT_IMPLEMENTED__}
static bool trans_ammin_db_d(CPULoongArchState *env, arg_ammin_db_d *a) {__NOT_IMPLEMENTED__}
static bool trans_ammax_db_wu(CPULoongArchState *env, arg_ammax_db_wu *a) {__NOT_IMPLEMENTED__}
static bool trans_ammax_db_du(CPULoongArchState *env, arg_ammax_db_du *a) {__NOT_IMPLEMENTED__}
static bool trans_ammin_db_wu(CPULoongArchState *env, arg_ammin_db_wu *a) {__NOT_IMPLEMENTED__}
static bool trans_ammin_db_du(CPULoongArchState *env, arg_ammin_db_du *a) {__NOT_IMPLEMENTED__}
static bool trans_crc_w_b_w(CPULoongArchState *env, arg_crc_w_b_w *a) {__NOT_IMPLEMENTED__}
static bool trans_crc_w_h_w(CPULoongArchState *env, arg_crc_w_h_w *a) {__NOT_IMPLEMENTED__}
static bool trans_crc_w_w_w(CPULoongArchState *env, arg_crc_w_w_w *a) {__NOT_IMPLEMENTED__}
static bool trans_crc_w_d_w(CPULoongArchState *env, arg_crc_w_d_w *a) {__NOT_IMPLEMENTED__}
static bool trans_crcc_w_b_w(CPULoongArchState *env, arg_crcc_w_b_w *a) {__NOT_IMPLEMENTED__}
static bool trans_crcc_w_h_w(CPULoongArchState *env, arg_crcc_w_h_w *a) {__NOT_IMPLEMENTED__}
static bool trans_crcc_w_w_w(CPULoongArchState *env, arg_crcc_w_w_w *a) {__NOT_IMPLEMENTED__}
static bool trans_crcc_w_d_w(CPULoongArchState *env, arg_crcc_w_d_w *a) {__NOT_IMPLEMENTED__}
static bool trans_break(CPULoongArchState *env, arg_break *a) {

    printf("trans_break\n");
    exit(0);

    __NOT_IMPLEMENTED__
}
static bool trans_syscall(CPULoongArchState *env, arg_syscall *a) {
    do_raise_exception(env, EXCCODE_SYS, 0);
}
static bool trans_asrtle_d(CPULoongArchState *env, arg_asrtle_d *a) {__NOT_IMPLEMENTED__}
static bool trans_asrtgt_d(CPULoongArchState *env, arg_asrtgt_d *a) {__NOT_IMPLEMENTED__}
static bool trans_rdtimel_w(CPULoongArchState *env, arg_rdtimel_w *a) {__NOT_IMPLEMENTED__}
static bool trans_rdtimeh_w(CPULoongArchState *env, arg_rdtimeh_w *a) {__NOT_IMPLEMENTED__}
static bool trans_rdtime_d(CPULoongArchState *env, arg_rdtime_d *a) {
    env->gpr[a->rd] = get_tsc();
    env->gpr[a->rj] = 0;
    env->pc += 4;
    return true;
}
static bool trans_cpucfg(CPULoongArchState *env, arg_cpucfg *a) {
    int index = env->gpr[a->rj];
    env->gpr[a->rd] = index >= ARRAY_SIZE(env->cpucfg) ? 0 : env->cpucfg[index];
    env->pc += 4;
    return true;
}
static bool trans_fadd_s(CPULoongArchState *env, arg_fadd_s *a) {__NOT_IMPLEMENTED__}
static bool trans_fadd_d(CPULoongArchState *env, arg_fadd_d *a) {__NOT_IMPLEMENTED__}
static bool trans_fsub_s(CPULoongArchState *env, arg_fsub_s *a) {__NOT_IMPLEMENTED__}
static bool trans_fsub_d(CPULoongArchState *env, arg_fsub_d *a) {__NOT_IMPLEMENTED__}
static bool trans_fmul_s(CPULoongArchState *env, arg_fmul_s *a) {__NOT_IMPLEMENTED__}
static bool trans_fmul_d(CPULoongArchState *env, arg_fmul_d *a) {__NOT_IMPLEMENTED__}
static bool trans_fdiv_s(CPULoongArchState *env, arg_fdiv_s *a) {__NOT_IMPLEMENTED__}
static bool trans_fdiv_d(CPULoongArchState *env, arg_fdiv_d *a) {__NOT_IMPLEMENTED__}
static bool trans_fmadd_s(CPULoongArchState *env, arg_fmadd_s *a) {__NOT_IMPLEMENTED__}
static bool trans_fmadd_d(CPULoongArchState *env, arg_fmadd_d *a) {__NOT_IMPLEMENTED__}
static bool trans_fmsub_s(CPULoongArchState *env, arg_fmsub_s *a) {__NOT_IMPLEMENTED__}
static bool trans_fmsub_d(CPULoongArchState *env, arg_fmsub_d *a) {__NOT_IMPLEMENTED__}
static bool trans_fnmadd_s(CPULoongArchState *env, arg_fnmadd_s *a) {__NOT_IMPLEMENTED__}
static bool trans_fnmadd_d(CPULoongArchState *env, arg_fnmadd_d *a) {__NOT_IMPLEMENTED__}
static bool trans_fnmsub_s(CPULoongArchState *env, arg_fnmsub_s *a) {__NOT_IMPLEMENTED__}
static bool trans_fnmsub_d(CPULoongArchState *env, arg_fnmsub_d *a) {__NOT_IMPLEMENTED__}
static bool trans_fmax_s(CPULoongArchState *env, arg_fmax_s *a) {__NOT_IMPLEMENTED__}
static bool trans_fmax_d(CPULoongArchState *env, arg_fmax_d *a) {__NOT_IMPLEMENTED__}
static bool trans_fmin_s(CPULoongArchState *env, arg_fmin_s *a) {__NOT_IMPLEMENTED__}
static bool trans_fmin_d(CPULoongArchState *env, arg_fmin_d *a) {__NOT_IMPLEMENTED__}
static bool trans_fmaxa_s(CPULoongArchState *env, arg_fmaxa_s *a) {__NOT_IMPLEMENTED__}
static bool trans_fmaxa_d(CPULoongArchState *env, arg_fmaxa_d *a) {__NOT_IMPLEMENTED__}
static bool trans_fmina_s(CPULoongArchState *env, arg_fmina_s *a) {__NOT_IMPLEMENTED__}
static bool trans_fmina_d(CPULoongArchState *env, arg_fmina_d *a) {__NOT_IMPLEMENTED__}
static bool trans_fabs_s(CPULoongArchState *env, arg_fabs_s *a) {__NOT_IMPLEMENTED__}
static bool trans_fabs_d(CPULoongArchState *env, arg_fabs_d *a) {__NOT_IMPLEMENTED__}
static bool trans_fneg_s(CPULoongArchState *env, arg_fneg_s *a) {__NOT_IMPLEMENTED__}
static bool trans_fneg_d(CPULoongArchState *env, arg_fneg_d *a) {__NOT_IMPLEMENTED__}
static bool trans_fsqrt_s(CPULoongArchState *env, arg_fsqrt_s *a) {__NOT_IMPLEMENTED__}
static bool trans_fsqrt_d(CPULoongArchState *env, arg_fsqrt_d *a) {__NOT_IMPLEMENTED__}
static bool trans_frecip_s(CPULoongArchState *env, arg_frecip_s *a) {__NOT_IMPLEMENTED__}
static bool trans_frecip_d(CPULoongArchState *env, arg_frecip_d *a) {__NOT_IMPLEMENTED__}
static bool trans_frsqrt_s(CPULoongArchState *env, arg_frsqrt_s *a) {__NOT_IMPLEMENTED__}
static bool trans_frsqrt_d(CPULoongArchState *env, arg_frsqrt_d *a) {__NOT_IMPLEMENTED__}
static bool trans_fscaleb_s(CPULoongArchState *env, arg_fscaleb_s *a) {__NOT_IMPLEMENTED__}
static bool trans_fscaleb_d(CPULoongArchState *env, arg_fscaleb_d *a) {__NOT_IMPLEMENTED__}
static bool trans_flogb_s(CPULoongArchState *env, arg_flogb_s *a) {__NOT_IMPLEMENTED__}
static bool trans_flogb_d(CPULoongArchState *env, arg_flogb_d *a) {__NOT_IMPLEMENTED__}
static bool trans_fcopysign_s(CPULoongArchState *env, arg_fcopysign_s *a) {__NOT_IMPLEMENTED__}
static bool trans_fcopysign_d(CPULoongArchState *env, arg_fcopysign_d *a) {__NOT_IMPLEMENTED__}
static bool trans_fclass_s(CPULoongArchState *env, arg_fclass_s *a) {__NOT_IMPLEMENTED__}
static bool trans_fclass_d(CPULoongArchState *env, arg_fclass_d *a) {__NOT_IMPLEMENTED__}
static bool trans_fcmp_cond_s(CPULoongArchState *env, arg_fcmp_cond_s *a) {__NOT_IMPLEMENTED__}
static bool trans_fcmp_cond_d(CPULoongArchState *env, arg_fcmp_cond_d *a) {__NOT_IMPLEMENTED__}
static bool trans_fcvt_s_d(CPULoongArchState *env, arg_fcvt_s_d *a) {__NOT_IMPLEMENTED__}
static bool trans_fcvt_d_s(CPULoongArchState *env, arg_fcvt_d_s *a) {__NOT_IMPLEMENTED__}
static bool trans_ftintrm_w_s(CPULoongArchState *env, arg_ftintrm_w_s *a) {__NOT_IMPLEMENTED__}
static bool trans_ftintrm_w_d(CPULoongArchState *env, arg_ftintrm_w_d *a) {__NOT_IMPLEMENTED__}
static bool trans_ftintrm_l_s(CPULoongArchState *env, arg_ftintrm_l_s *a) {__NOT_IMPLEMENTED__}
static bool trans_ftintrm_l_d(CPULoongArchState *env, arg_ftintrm_l_d *a) {__NOT_IMPLEMENTED__}
static bool trans_ftintrp_w_s(CPULoongArchState *env, arg_ftintrp_w_s *a) {__NOT_IMPLEMENTED__}
static bool trans_ftintrp_w_d(CPULoongArchState *env, arg_ftintrp_w_d *a) {__NOT_IMPLEMENTED__}
static bool trans_ftintrp_l_s(CPULoongArchState *env, arg_ftintrp_l_s *a) {__NOT_IMPLEMENTED__}
static bool trans_ftintrp_l_d(CPULoongArchState *env, arg_ftintrp_l_d *a) {__NOT_IMPLEMENTED__}
static bool trans_ftintrz_w_s(CPULoongArchState *env, arg_ftintrz_w_s *a) {__NOT_IMPLEMENTED__}
static bool trans_ftintrz_w_d(CPULoongArchState *env, arg_ftintrz_w_d *a) {__NOT_IMPLEMENTED__}
static bool trans_ftintrz_l_s(CPULoongArchState *env, arg_ftintrz_l_s *a) {__NOT_IMPLEMENTED__}
static bool trans_ftintrz_l_d(CPULoongArchState *env, arg_ftintrz_l_d *a) {__NOT_IMPLEMENTED__}
static bool trans_ftintrne_w_s(CPULoongArchState *env, arg_ftintrne_w_s *a) {__NOT_IMPLEMENTED__}
static bool trans_ftintrne_w_d(CPULoongArchState *env, arg_ftintrne_w_d *a) {__NOT_IMPLEMENTED__}
static bool trans_ftintrne_l_s(CPULoongArchState *env, arg_ftintrne_l_s *a) {__NOT_IMPLEMENTED__}
static bool trans_ftintrne_l_d(CPULoongArchState *env, arg_ftintrne_l_d *a) {__NOT_IMPLEMENTED__}
static bool trans_ftint_w_s(CPULoongArchState *env, arg_ftint_w_s *a) {__NOT_IMPLEMENTED__}
static bool trans_ftint_w_d(CPULoongArchState *env, arg_ftint_w_d *a) {__NOT_IMPLEMENTED__}
static bool trans_ftint_l_s(CPULoongArchState *env, arg_ftint_l_s *a) {__NOT_IMPLEMENTED__}
static bool trans_ftint_l_d(CPULoongArchState *env, arg_ftint_l_d *a) {__NOT_IMPLEMENTED__}
static bool trans_ffint_s_w(CPULoongArchState *env, arg_ffint_s_w *a) {__NOT_IMPLEMENTED__}
static bool trans_ffint_s_l(CPULoongArchState *env, arg_ffint_s_l *a) {__NOT_IMPLEMENTED__}
static bool trans_ffint_d_w(CPULoongArchState *env, arg_ffint_d_w *a) {__NOT_IMPLEMENTED__}
static bool trans_ffint_d_l(CPULoongArchState *env, arg_ffint_d_l *a) {__NOT_IMPLEMENTED__}
static bool trans_frint_s(CPULoongArchState *env, arg_frint_s *a) {__NOT_IMPLEMENTED__}
static bool trans_frint_d(CPULoongArchState *env, arg_frint_d *a) {__NOT_IMPLEMENTED__}
static bool trans_fmov_s(CPULoongArchState *env, arg_fmov_s *a) {__NOT_IMPLEMENTED__}
static bool trans_fmov_d(CPULoongArchState *env, arg_fmov_d *a) {__NOT_IMPLEMENTED__}
static bool trans_fsel(CPULoongArchState *env, arg_fsel *a) {__NOT_IMPLEMENTED__}
static bool trans_movgr2fr_w(CPULoongArchState *env, arg_movgr2fr_w *a) {__NOT_IMPLEMENTED__}
static bool trans_movgr2fr_d(CPULoongArchState *env, arg_movgr2fr_d *a) {__NOT_IMPLEMENTED__}
static bool trans_movgr2frh_w(CPULoongArchState *env, arg_movgr2frh_w *a) {__NOT_IMPLEMENTED__}
static bool trans_movfr2gr_s(CPULoongArchState *env, arg_movfr2gr_s *a) {__NOT_IMPLEMENTED__}
static bool trans_movfr2gr_d(CPULoongArchState *env, arg_movfr2gr_d *a) {__NOT_IMPLEMENTED__}
static bool trans_movfrh2gr_s(CPULoongArchState *env, arg_movfrh2gr_s *a) {__NOT_IMPLEMENTED__}
static bool trans_movgr2fcsr(CPULoongArchState *env, arg_movgr2fcsr *a) {__NOT_IMPLEMENTED__}
static bool trans_movfcsr2gr(CPULoongArchState *env, arg_movfcsr2gr *a) {__NOT_IMPLEMENTED__}
static bool trans_movfr2cf(CPULoongArchState *env, arg_movfr2cf *a) {__NOT_IMPLEMENTED__}
static bool trans_movcf2fr(CPULoongArchState *env, arg_movcf2fr *a) {__NOT_IMPLEMENTED__}
static bool trans_movgr2cf(CPULoongArchState *env, arg_movgr2cf *a) {__NOT_IMPLEMENTED__}
static bool trans_movcf2gr(CPULoongArchState *env, arg_movcf2gr *a) {__NOT_IMPLEMENTED__}
static bool trans_fld_s(CPULoongArchState *env, arg_fld_s *a) {__NOT_IMPLEMENTED__}
static bool trans_fst_s(CPULoongArchState *env, arg_fst_s *a) {__NOT_IMPLEMENTED__}
static bool trans_fld_d(CPULoongArchState *env, arg_fld_d *a) {__NOT_IMPLEMENTED__}
static bool trans_fst_d(CPULoongArchState *env, arg_fst_d *a) {__NOT_IMPLEMENTED__}
static bool trans_fldx_s(CPULoongArchState *env, arg_fldx_s *a) {__NOT_IMPLEMENTED__}
static bool trans_fldx_d(CPULoongArchState *env, arg_fldx_d *a) {__NOT_IMPLEMENTED__}
static bool trans_fstx_s(CPULoongArchState *env, arg_fstx_s *a) {__NOT_IMPLEMENTED__}
static bool trans_fstx_d(CPULoongArchState *env, arg_fstx_d *a) {__NOT_IMPLEMENTED__}
static bool trans_fldgt_s(CPULoongArchState *env, arg_fldgt_s *a) {__NOT_IMPLEMENTED__}
static bool trans_fldgt_d(CPULoongArchState *env, arg_fldgt_d *a) {__NOT_IMPLEMENTED__}
static bool trans_fldle_s(CPULoongArchState *env, arg_fldle_s *a) {__NOT_IMPLEMENTED__}
static bool trans_fldle_d(CPULoongArchState *env, arg_fldle_d *a) {__NOT_IMPLEMENTED__}
static bool trans_fstgt_s(CPULoongArchState *env, arg_fstgt_s *a) {__NOT_IMPLEMENTED__}
static bool trans_fstgt_d(CPULoongArchState *env, arg_fstgt_d *a) {__NOT_IMPLEMENTED__}
static bool trans_fstle_s(CPULoongArchState *env, arg_fstle_s *a) {__NOT_IMPLEMENTED__}
static bool trans_fstle_d(CPULoongArchState *env, arg_fstle_d *a) {__NOT_IMPLEMENTED__}
static bool trans_beqz(CPULoongArchState *env, arg_beqz *a) {
    if ((int64_t)env->gpr[a->rj] == 0) {
        env->pc += a->offs;
    } else {
        env->pc += 4;
    }
    return true;
}
static bool trans_bnez(CPULoongArchState *env, arg_bnez *a) {
    if ((int64_t)env->gpr[a->rj] != 0) {
        env->pc += a->offs;
    } else {
        env->pc += 4;
    }
    return true;
}
static bool trans_bceqz(CPULoongArchState *env, arg_bceqz *a) {__NOT_IMPLEMENTED__}
static bool trans_bcnez(CPULoongArchState *env, arg_bcnez *a) {__NOT_IMPLEMENTED__}
static bool trans_jirl(CPULoongArchState *env, arg_jirl *a) {
    uint64_t old_pc = env->pc;
    env->pc = env->gpr[a->rj] + a->imm;
    env->gpr[a->rd] = old_pc + 4;
    return true;
}
static bool trans_b(CPULoongArchState *env, arg_b *a) {
    if (!a->offs) {
        exit(EXIT_SUCCESS);
    }
    env->pc += a->offs;
    return true;
}
static bool trans_bl(CPULoongArchState *env, arg_bl *a) {
    env->gpr[1] = env->pc + 4;
    env->pc += a->offs;
    return true;
}
static bool trans_beq(CPULoongArchState *env, arg_beq *a) {
    if ((int64_t)env->gpr[a->rj] == (int64_t)env->gpr[a->rd]) {
        env->pc += a->offs;
    } else {
        env->pc += 4;
    }
    return true;
}
static bool trans_bne(CPULoongArchState *env, arg_bne *a) {
    if ((int64_t)env->gpr[a->rj] != (int64_t)env->gpr[a->rd]) {
        env->pc += a->offs;
    } else {
        env->pc += 4;
    }
    return true;
}
static bool trans_blt(CPULoongArchState *env, arg_blt *a) {
    if ((int64_t)env->gpr[a->rj] < (int64_t)env->gpr[a->rd]) {
        env->pc += a->offs;
    } else {
        env->pc += 4;
    }
    return true;
}
static bool trans_bge(CPULoongArchState *env, arg_bge *a) {
    if ((int64_t)env->gpr[a->rj] >= (int64_t)env->gpr[a->rd]) {
        env->pc += a->offs;
    } else {
        env->pc += 4;
    }
    return true;
}
static bool trans_bltu(CPULoongArchState *env, arg_bltu *a) {
    if ((uint64_t)env->gpr[a->rj] < (uint64_t)env->gpr[a->rd]) {
        env->pc += a->offs;
    } else {
        env->pc += 4;
    }
    return true;
}
static bool trans_bgeu(CPULoongArchState *env, arg_bgeu *a) {
    if ((uint64_t)env->gpr[a->rj] >= (uint64_t)env->gpr[a->rd]) {
        env->pc += a->offs;
    } else {
        env->pc += 4;
    }
    return true;
}
static bool trans_csrrd(CPULoongArchState *env, arg_csrrd *a) {
    uint64_t old_v = 0;
    switch (a->csr) {
        case LOONGARCH_CSR_CRMD           :old_v = env->CSR_CRMD; break;
        case LOONGARCH_CSR_PRMD           :old_v = env->CSR_PRMD; break;
        case LOONGARCH_CSR_EUEN           :old_v = env->CSR_EUEN; break;
        case LOONGARCH_CSR_MISC           :old_v = env->CSR_MISC; break;
        case LOONGARCH_CSR_ECFG           :old_v = env->CSR_ECFG; break;
        case LOONGARCH_CSR_ESTAT          :old_v = env->CSR_ESTAT; break;
        case LOONGARCH_CSR_ERA            :old_v = env->CSR_ERA; break;
        case LOONGARCH_CSR_BADV           :old_v = env->CSR_BADV; break;
        case LOONGARCH_CSR_BADI           :old_v = env->CSR_BADI; break;
        case LOONGARCH_CSR_EENTRY         :old_v = env->CSR_EENTRY; break;
        case LOONGARCH_CSR_TLBIDX         :old_v = env->CSR_TLBIDX; break;
        case LOONGARCH_CSR_TLBEHI         :old_v = env->CSR_TLBEHI; break;
        case LOONGARCH_CSR_TLBELO0        :old_v = env->CSR_TLBELO0; break;
        case LOONGARCH_CSR_TLBELO1        :old_v = env->CSR_TLBELO1; break;
        case LOONGARCH_CSR_ASID           :old_v = env->CSR_ASID; break;
        case LOONGARCH_CSR_PGDL           :old_v = env->CSR_PGDL; break;
        case LOONGARCH_CSR_PGDH           :old_v = env->CSR_PGDH; break;
        case LOONGARCH_CSR_PGD            :old_v = env->CSR_PGD; break;
        case LOONGARCH_CSR_PWCL           :old_v = env->CSR_PWCL; break;
        case LOONGARCH_CSR_PWCH           :old_v = env->CSR_PWCH; break;
        case LOONGARCH_CSR_STLBPS         :old_v = env->CSR_STLBPS; break;
        case LOONGARCH_CSR_RVACFG         :old_v = env->CSR_RVACFG; break;
        case LOONGARCH_CSR_CPUID          :old_v = env->CSR_CPUID; break;
        case LOONGARCH_CSR_PRCFG1         :old_v = env->CSR_PRCFG1; break;
        case LOONGARCH_CSR_PRCFG2         :old_v = env->CSR_PRCFG2; break;
        case LOONGARCH_CSR_PRCFG3         :old_v = env->CSR_PRCFG3; break;
        case LOONGARCH_CSR_SAVE(0)        :old_v = env->CSR_SAVE[0]; break;
        case LOONGARCH_CSR_SAVE(1)        :old_v = env->CSR_SAVE[1]; break;
        case LOONGARCH_CSR_SAVE(2)        :old_v = env->CSR_SAVE[2]; break;
        case LOONGARCH_CSR_SAVE(3)        :old_v = env->CSR_SAVE[3]; break;
        case LOONGARCH_CSR_SAVE(4)        :old_v = env->CSR_SAVE[4]; break;
        case LOONGARCH_CSR_SAVE(5)        :old_v = env->CSR_SAVE[5]; break;
        case LOONGARCH_CSR_SAVE(6)        :old_v = env->CSR_SAVE[6]; break;
        case LOONGARCH_CSR_SAVE(7)        :old_v = env->CSR_SAVE[7]; break;
        case LOONGARCH_CSR_TID            :old_v = env->CSR_TID; break;
        case LOONGARCH_CSR_TCFG           :old_v = env->CSR_TCFG; break;
        case LOONGARCH_CSR_TVAL           :old_v = env->CSR_TVAL; break;
        case LOONGARCH_CSR_CNTC           :old_v = env->CSR_CNTC; break;
        case LOONGARCH_CSR_TICLR          :old_v = env->CSR_TICLR; break;
        case LOONGARCH_CSR_LLBCTL         :old_v = env->CSR_LLBCTL; break;
        case LOONGARCH_CSR_IMPCTL1        :old_v = env->CSR_IMPCTL1; break;
        case LOONGARCH_CSR_IMPCTL2        :old_v = env->CSR_IMPCTL2; break;
        case LOONGARCH_CSR_TLBRENTRY      :old_v = env->CSR_TLBRENTRY; break;
        case LOONGARCH_CSR_TLBRBADV       :old_v = env->CSR_TLBRBADV; break;
        case LOONGARCH_CSR_TLBRERA        :old_v = env->CSR_TLBRERA; break;
        case LOONGARCH_CSR_TLBRSAVE       :old_v = env->CSR_TLBRSAVE; break;
        case LOONGARCH_CSR_TLBRELO0       :old_v = env->CSR_TLBRELO0; break;
        case LOONGARCH_CSR_TLBRELO1       :old_v = env->CSR_TLBRELO1; break;
        case LOONGARCH_CSR_TLBREHI        :old_v = env->CSR_TLBREHI; break;
        case LOONGARCH_CSR_TLBRPRMD       :old_v = env->CSR_TLBRPRMD; break;
        case LOONGARCH_CSR_MERRCTL        :old_v = env->CSR_MERRCTL; break;
        case LOONGARCH_CSR_MERRINFO1      :old_v = env->CSR_MERRINFO1; break;
        case LOONGARCH_CSR_MERRINFO2      :old_v = env->CSR_MERRINFO2; break;
        case LOONGARCH_CSR_MERRENTRY      :old_v = env->CSR_MERRENTRY; break;
        case LOONGARCH_CSR_MERRERA        :old_v = env->CSR_MERRERA; break;
        case LOONGARCH_CSR_MERRSAVE       :old_v = env->CSR_MERRSAVE; break;
        case LOONGARCH_CSR_CTAG           :old_v = env->CSR_CTAG; break;
        case LOONGARCH_CSR_DMW(0)         :old_v = env->CSR_DMW[0]; break;
        case LOONGARCH_CSR_DMW(1)         :old_v = env->CSR_DMW[1]; break;
        case LOONGARCH_CSR_DMW(2)         :old_v = env->CSR_DMW[2]; break;
        case LOONGARCH_CSR_DMW(3)         :old_v = env->CSR_DMW[3]; break;
        case LOONGARCH_CSR_DBG            :old_v = env->CSR_DBG; break;
        case LOONGARCH_CSR_DERA           :old_v = env->CSR_DERA; break;
        case LOONGARCH_CSR_DSAVE          :old_v = env->CSR_DSAVE; break;
        default:
            fprintf(stderr, "NOT IMPLEMENTED %s %x\n", __func__, a->csr);
    }
    env->gpr[a->rd] = old_v;
    env->pc += 4;
    return true;
}
static bool trans_csrwr(CPULoongArchState *env, arg_csrwr *a) {
    uint64_t old_v = 0;
    switch (a->csr) {
        case LOONGARCH_CSR_CRMD           :old_v = env->CSR_CRMD; env->CSR_CRMD = env->gpr[a->rd]; break;
        case LOONGARCH_CSR_PRMD           :old_v = env->CSR_PRMD; env->CSR_PRMD = env->gpr[a->rd]; break;
        case LOONGARCH_CSR_EUEN           :old_v = env->CSR_EUEN; env->CSR_EUEN = env->gpr[a->rd]; break;
        case LOONGARCH_CSR_MISC           :old_v = env->CSR_MISC; env->CSR_MISC = env->gpr[a->rd]; break;
        case LOONGARCH_CSR_ECFG           :old_v = env->CSR_ECFG; env->CSR_ECFG = env->gpr[a->rd]; break;
        case LOONGARCH_CSR_ESTAT          :old_v = env->CSR_ESTAT; env->CSR_ESTAT = env->gpr[a->rd]; break;
        case LOONGARCH_CSR_ERA            :old_v = env->CSR_ERA; env->CSR_ERA = env->gpr[a->rd]; break;
        case LOONGARCH_CSR_BADV           :old_v = env->CSR_BADV; env->CSR_BADV = env->gpr[a->rd]; break;
        case LOONGARCH_CSR_BADI           :old_v = env->CSR_BADI; env->CSR_BADI = env->gpr[a->rd]; break;
        case LOONGARCH_CSR_EENTRY         :old_v = env->CSR_EENTRY; env->CSR_EENTRY = env->gpr[a->rd]; break;
        case LOONGARCH_CSR_TLBIDX         :old_v = env->CSR_TLBIDX; env->CSR_TLBIDX = env->gpr[a->rd]; break;
        case LOONGARCH_CSR_TLBEHI         :old_v = env->CSR_TLBEHI; env->CSR_TLBEHI = env->gpr[a->rd]; break;
        case LOONGARCH_CSR_TLBELO0        :old_v = env->CSR_TLBELO0; env->CSR_TLBELO0 = env->gpr[a->rd]; break;
        case LOONGARCH_CSR_TLBELO1        :old_v = env->CSR_TLBELO1; env->CSR_TLBELO1 = env->gpr[a->rd]; break;
        case LOONGARCH_CSR_ASID           :old_v = env->CSR_ASID; env->CSR_ASID = env->gpr[a->rd]; break;
        case LOONGARCH_CSR_PGDL           :old_v = env->CSR_PGDL; env->CSR_PGDL = env->gpr[a->rd]; break;
        case LOONGARCH_CSR_PGDH           :old_v = env->CSR_PGDH; env->CSR_PGDH = env->gpr[a->rd]; break;
        case LOONGARCH_CSR_PGD            :old_v = env->CSR_PGD; env->CSR_PGD = env->gpr[a->rd]; break;
        case LOONGARCH_CSR_PWCL           :old_v = env->CSR_PWCL; env->CSR_PWCL = env->gpr[a->rd]; break;
        case LOONGARCH_CSR_PWCH           :old_v = env->CSR_PWCH; env->CSR_PWCH = env->gpr[a->rd]; break;
        case LOONGARCH_CSR_STLBPS         :old_v = env->CSR_STLBPS; env->CSR_STLBPS = env->gpr[a->rd]; break;
        case LOONGARCH_CSR_RVACFG         :old_v = env->CSR_RVACFG; env->CSR_RVACFG = env->gpr[a->rd]; break;
        case LOONGARCH_CSR_CPUID          :old_v = env->CSR_CPUID; env->CSR_CPUID = env->gpr[a->rd]; break;
        case LOONGARCH_CSR_PRCFG1         :old_v = env->CSR_PRCFG1; env->CSR_PRCFG1 = env->gpr[a->rd]; break;
        case LOONGARCH_CSR_PRCFG2         :old_v = env->CSR_PRCFG2; env->CSR_PRCFG2 = env->gpr[a->rd]; break;
        case LOONGARCH_CSR_PRCFG3         :old_v = env->CSR_PRCFG3; env->CSR_PRCFG3 = env->gpr[a->rd]; break;
        case LOONGARCH_CSR_SAVE(0)        :old_v = env->CSR_SAVE[0]; env->CSR_SAVE[0] = env->gpr[a->rd]; break;
        case LOONGARCH_CSR_SAVE(1)        :old_v = env->CSR_SAVE[1]; env->CSR_SAVE[1] = env->gpr[a->rd]; break;
        case LOONGARCH_CSR_SAVE(2)        :old_v = env->CSR_SAVE[2]; env->CSR_SAVE[2] = env->gpr[a->rd]; break;
        case LOONGARCH_CSR_SAVE(3)        :old_v = env->CSR_SAVE[3]; env->CSR_SAVE[3] = env->gpr[a->rd]; break;
        case LOONGARCH_CSR_SAVE(4)        :old_v = env->CSR_SAVE[4]; env->CSR_SAVE[4] = env->gpr[a->rd]; break;
        case LOONGARCH_CSR_SAVE(5)        :old_v = env->CSR_SAVE[5]; env->CSR_SAVE[5] = env->gpr[a->rd]; break;
        case LOONGARCH_CSR_SAVE(6)        :old_v = env->CSR_SAVE[6]; env->CSR_SAVE[6] = env->gpr[a->rd]; break;
        case LOONGARCH_CSR_SAVE(7)        :old_v = env->CSR_SAVE[7]; env->CSR_SAVE[7] = env->gpr[a->rd]; break;
        case LOONGARCH_CSR_TID            :old_v = env->CSR_TID; env->CSR_TID = env->gpr[a->rd]; break;
        case LOONGARCH_CSR_TCFG           :old_v = env->CSR_TCFG; env->CSR_TCFG = env->gpr[a->rd]; break;
        case LOONGARCH_CSR_TVAL           :old_v = env->CSR_TVAL; env->CSR_TVAL = env->gpr[a->rd]; break;
        case LOONGARCH_CSR_CNTC           :old_v = env->CSR_CNTC; env->CSR_CNTC = env->gpr[a->rd]; break;
        case LOONGARCH_CSR_TICLR          :old_v = env->CSR_TICLR; env->CSR_TICLR = env->gpr[a->rd]; break;
        case LOONGARCH_CSR_LLBCTL         :old_v = env->CSR_LLBCTL; env->CSR_LLBCTL = env->gpr[a->rd]; break;
        case LOONGARCH_CSR_IMPCTL1        :old_v = env->CSR_IMPCTL1; env->CSR_IMPCTL1 = env->gpr[a->rd]; break;
        case LOONGARCH_CSR_IMPCTL2        :old_v = env->CSR_IMPCTL2; env->CSR_IMPCTL2 = env->gpr[a->rd]; break;
        case LOONGARCH_CSR_TLBRENTRY      :old_v = env->CSR_TLBRENTRY; env->CSR_TLBRENTRY = env->gpr[a->rd]; break;
        case LOONGARCH_CSR_TLBRBADV       :old_v = env->CSR_TLBRBADV; env->CSR_TLBRBADV = env->gpr[a->rd]; break;
        case LOONGARCH_CSR_TLBRERA        :old_v = env->CSR_TLBRERA; env->CSR_TLBRERA = env->gpr[a->rd]; break;
        case LOONGARCH_CSR_TLBRSAVE       :old_v = env->CSR_TLBRSAVE; env->CSR_TLBRSAVE = env->gpr[a->rd]; break;
        case LOONGARCH_CSR_TLBRELO0       :old_v = env->CSR_TLBRELO0; env->CSR_TLBRELO0 = env->gpr[a->rd]; break;
        case LOONGARCH_CSR_TLBRELO1       :old_v = env->CSR_TLBRELO1; env->CSR_TLBRELO1 = env->gpr[a->rd]; break;
        case LOONGARCH_CSR_TLBREHI        :old_v = env->CSR_TLBREHI; env->CSR_TLBREHI = env->gpr[a->rd]; break;
        case LOONGARCH_CSR_TLBRPRMD       :old_v = env->CSR_TLBRPRMD; env->CSR_TLBRPRMD = env->gpr[a->rd]; break;
        case LOONGARCH_CSR_MERRCTL        :old_v = env->CSR_MERRCTL; env->CSR_MERRCTL = env->gpr[a->rd]; break;
        case LOONGARCH_CSR_MERRINFO1      :old_v = env->CSR_MERRINFO1; env->CSR_MERRINFO1 = env->gpr[a->rd]; break;
        case LOONGARCH_CSR_MERRINFO2      :old_v = env->CSR_MERRINFO2; env->CSR_MERRINFO2 = env->gpr[a->rd]; break;
        case LOONGARCH_CSR_MERRENTRY      :old_v = env->CSR_MERRENTRY; env->CSR_MERRENTRY = env->gpr[a->rd]; break;
        case LOONGARCH_CSR_MERRERA        :old_v = env->CSR_MERRERA; env->CSR_MERRERA = env->gpr[a->rd]; break;
        case LOONGARCH_CSR_MERRSAVE       :old_v = env->CSR_MERRSAVE; env->CSR_MERRSAVE = env->gpr[a->rd]; break;
        case LOONGARCH_CSR_CTAG           :old_v = env->CSR_CTAG; env->CSR_CTAG = env->gpr[a->rd]; break;
        case LOONGARCH_CSR_DMW(0)         :old_v = env->CSR_DMW[0]; env->CSR_DMW[0] = env->gpr[a->rd]; break;
        case LOONGARCH_CSR_DMW(1)         :old_v = env->CSR_DMW[1]; env->CSR_DMW[1] = env->gpr[a->rd]; break;
        case LOONGARCH_CSR_DMW(2)         :old_v = env->CSR_DMW[2]; env->CSR_DMW[2] = env->gpr[a->rd]; break;
        case LOONGARCH_CSR_DMW(3)         :old_v = env->CSR_DMW[3]; env->CSR_DMW[3] = env->gpr[a->rd]; break;
        case LOONGARCH_CSR_DBG            :old_v = env->CSR_DBG; env->CSR_DBG = env->gpr[a->rd]; break;
        case LOONGARCH_CSR_DERA           :old_v = env->CSR_DERA; env->CSR_DERA = env->gpr[a->rd]; break;
        case LOONGARCH_CSR_DSAVE          :old_v = env->CSR_DSAVE; env->CSR_DSAVE = env->gpr[a->rd]; break;
        default:
            fprintf(stderr, "NOT IMPLEMENTED %s %x\n", __func__, a->csr);
    }
    env->gpr[a->rd] = old_v;
    env->pc += 4;
    return true;
}
static bool trans_csrxchg(CPULoongArchState *env, arg_csrxchg *a) {
    uint64_t mask = env->gpr[a->rj];
    uint64_t old_v = 0;
    switch (a->csr) {
        case LOONGARCH_CSR_CRMD           :old_v = env->CSR_CRMD;        env->CSR_CRMD &= (~mask);        env->CSR_CRMD |= (env->gpr[a->rd] & mask); break;
        case LOONGARCH_CSR_PRMD           :old_v = env->CSR_PRMD;        env->CSR_PRMD &= (~mask);        env->CSR_PRMD |= (env->gpr[a->rd] & mask); break;
        case LOONGARCH_CSR_EUEN           :old_v = env->CSR_EUEN;        env->CSR_EUEN &= (~mask);        env->CSR_EUEN |= (env->gpr[a->rd] & mask); break;
        case LOONGARCH_CSR_MISC           :old_v = env->CSR_MISC;        env->CSR_MISC &= (~mask);        env->CSR_MISC |= (env->gpr[a->rd] & mask); break;
        case LOONGARCH_CSR_ECFG           :old_v = env->CSR_ECFG;        env->CSR_ECFG &= (~mask);        env->CSR_ECFG |= (env->gpr[a->rd] & mask); break;
        case LOONGARCH_CSR_ESTAT          :old_v = env->CSR_ESTAT;       env->CSR_ESTAT &= (~mask);       env->CSR_ESTAT |= (env->gpr[a->rd] & mask); break;
        case LOONGARCH_CSR_ERA            :old_v = env->CSR_ERA;         env->CSR_ERA &= (~mask);         env->CSR_ERA |= (env->gpr[a->rd] & mask); break;
        case LOONGARCH_CSR_BADV           :old_v = env->CSR_BADV;        env->CSR_BADV &= (~mask);        env->CSR_BADV |= (env->gpr[a->rd] & mask); break;
        case LOONGARCH_CSR_BADI           :old_v = env->CSR_BADI;        env->CSR_BADI &= (~mask);        env->CSR_BADI |= (env->gpr[a->rd] & mask); break;
        case LOONGARCH_CSR_EENTRY         :old_v = env->CSR_EENTRY;      env->CSR_EENTRY &= (~mask);      env->CSR_EENTRY |= (env->gpr[a->rd] & mask); break;
        case LOONGARCH_CSR_TLBIDX         :old_v = env->CSR_TLBIDX;      env->CSR_TLBIDX &= (~mask);      env->CSR_TLBIDX |= (env->gpr[a->rd] & mask); break;
        case LOONGARCH_CSR_TLBEHI         :old_v = env->CSR_TLBEHI;      env->CSR_TLBEHI &= (~mask);      env->CSR_TLBEHI |= (env->gpr[a->rd] & mask); break;
        case LOONGARCH_CSR_TLBELO0        :old_v = env->CSR_TLBELO0;     env->CSR_TLBELO0 &= (~mask);     env->CSR_TLBELO0 |= (env->gpr[a->rd] & mask); break;
        case LOONGARCH_CSR_TLBELO1        :old_v = env->CSR_TLBELO1;     env->CSR_TLBELO1 &= (~mask);     env->CSR_TLBELO1 |= (env->gpr[a->rd] & mask); break;
        case LOONGARCH_CSR_ASID           :old_v = env->CSR_ASID;        env->CSR_ASID &= (~mask);        env->CSR_ASID |= (env->gpr[a->rd] & mask); break;
        case LOONGARCH_CSR_PGDL           :old_v = env->CSR_PGDL;        env->CSR_PGDL &= (~mask);        env->CSR_PGDL |= (env->gpr[a->rd] & mask); break;
        case LOONGARCH_CSR_PGDH           :old_v = env->CSR_PGDH;        env->CSR_PGDH &= (~mask);        env->CSR_PGDH |= (env->gpr[a->rd] & mask); break;
        case LOONGARCH_CSR_PGD            :old_v = env->CSR_PGD;         env->CSR_PGD &= (~mask);         env->CSR_PGD |= (env->gpr[a->rd] & mask); break;
        case LOONGARCH_CSR_PWCL           :old_v = env->CSR_PWCL;        env->CSR_PWCL &= (~mask);        env->CSR_PWCL |= (env->gpr[a->rd] & mask); break;
        case LOONGARCH_CSR_PWCH           :old_v = env->CSR_PWCH;        env->CSR_PWCH &= (~mask);        env->CSR_PWCH |= (env->gpr[a->rd] & mask); break;
        case LOONGARCH_CSR_STLBPS         :old_v = env->CSR_STLBPS;      env->CSR_STLBPS &= (~mask);      env->CSR_STLBPS |= (env->gpr[a->rd] & mask); break;
        case LOONGARCH_CSR_RVACFG         :old_v = env->CSR_RVACFG;      env->CSR_RVACFG &= (~mask);      env->CSR_RVACFG |= (env->gpr[a->rd] & mask); break;
        case LOONGARCH_CSR_CPUID          :old_v = env->CSR_CPUID;       env->CSR_CPUID &= (~mask);       env->CSR_CPUID |= (env->gpr[a->rd] & mask); break;
        case LOONGARCH_CSR_PRCFG1         :old_v = env->CSR_PRCFG1;      env->CSR_PRCFG1 &= (~mask);      env->CSR_PRCFG1 |= (env->gpr[a->rd] & mask); break;
        case LOONGARCH_CSR_PRCFG2         :old_v = env->CSR_PRCFG2;      env->CSR_PRCFG2 &= (~mask);      env->CSR_PRCFG2 |= (env->gpr[a->rd] & mask); break;
        case LOONGARCH_CSR_PRCFG3         :old_v = env->CSR_PRCFG3;      env->CSR_PRCFG3 &= (~mask);      env->CSR_PRCFG3 |= (env->gpr[a->rd] & mask); break;
        case LOONGARCH_CSR_SAVE(0)        :old_v = env->CSR_SAVE[0];     env->CSR_SAVE[0] &= (~mask);     env->CSR_SAVE[0] |= (env->gpr[a->rd] & mask); break;
        case LOONGARCH_CSR_SAVE(1)        :old_v = env->CSR_SAVE[1];     env->CSR_SAVE[1] &= (~mask);     env->CSR_SAVE[1] |= (env->gpr[a->rd] & mask); break;
        case LOONGARCH_CSR_SAVE(2)        :old_v = env->CSR_SAVE[2];     env->CSR_SAVE[2] &= (~mask);     env->CSR_SAVE[2] |= (env->gpr[a->rd] & mask); break;
        case LOONGARCH_CSR_SAVE(3)        :old_v = env->CSR_SAVE[3];     env->CSR_SAVE[3] &= (~mask);     env->CSR_SAVE[3] |= (env->gpr[a->rd] & mask); break;
        case LOONGARCH_CSR_SAVE(4)        :old_v = env->CSR_SAVE[4];     env->CSR_SAVE[4] &= (~mask);     env->CSR_SAVE[4] |= (env->gpr[a->rd] & mask); break;
        case LOONGARCH_CSR_SAVE(5)        :old_v = env->CSR_SAVE[5];     env->CSR_SAVE[5] &= (~mask);     env->CSR_SAVE[5] |= (env->gpr[a->rd] & mask); break;
        case LOONGARCH_CSR_SAVE(6)        :old_v = env->CSR_SAVE[6];     env->CSR_SAVE[6] &= (~mask);     env->CSR_SAVE[6] |= (env->gpr[a->rd] & mask); break;
        case LOONGARCH_CSR_SAVE(7)        :old_v = env->CSR_SAVE[7];     env->CSR_SAVE[7] &= (~mask);     env->CSR_SAVE[7] |= (env->gpr[a->rd] & mask); break;
        case LOONGARCH_CSR_TID            :old_v = env->CSR_TID;         env->CSR_TID &= (~mask);         env->CSR_TID |= (env->gpr[a->rd] & mask); break;
        case LOONGARCH_CSR_TCFG           :old_v = env->CSR_TCFG;        env->CSR_TCFG &= (~mask);        env->CSR_TCFG |= (env->gpr[a->rd] & mask); break;
        case LOONGARCH_CSR_TVAL           :old_v = env->CSR_TVAL;        env->CSR_TVAL &= (~mask);        env->CSR_TVAL |= (env->gpr[a->rd] & mask); break;
        case LOONGARCH_CSR_CNTC           :old_v = env->CSR_CNTC;        env->CSR_CNTC &= (~mask);        env->CSR_CNTC |= (env->gpr[a->rd] & mask); break;
        case LOONGARCH_CSR_TICLR          :old_v = env->CSR_TICLR;       env->CSR_TICLR &= (~mask);       env->CSR_TICLR |= (env->gpr[a->rd] & mask); break;
        case LOONGARCH_CSR_LLBCTL         :old_v = env->CSR_LLBCTL;      env->CSR_LLBCTL &= (~mask);      env->CSR_LLBCTL |= (env->gpr[a->rd] & mask); break;
        case LOONGARCH_CSR_IMPCTL1        :old_v = env->CSR_IMPCTL1;     env->CSR_IMPCTL1 &= (~mask);     env->CSR_IMPCTL1 |= (env->gpr[a->rd] & mask); break;
        case LOONGARCH_CSR_IMPCTL2        :old_v = env->CSR_IMPCTL2;     env->CSR_IMPCTL2 &= (~mask);     env->CSR_IMPCTL2 |= (env->gpr[a->rd] & mask); break;
        case LOONGARCH_CSR_TLBRENTRY      :old_v = env->CSR_TLBRENTRY;   env->CSR_TLBRENTRY &= (~mask);   env->CSR_TLBRENTRY |= (env->gpr[a->rd] & mask); break;
        case LOONGARCH_CSR_TLBRBADV       :old_v = env->CSR_TLBRBADV;    env->CSR_TLBRBADV &= (~mask);    env->CSR_TLBRBADV |= (env->gpr[a->rd] & mask); break;
        case LOONGARCH_CSR_TLBRERA        :old_v = env->CSR_TLBRERA;     env->CSR_TLBRERA &= (~mask);     env->CSR_TLBRERA |= (env->gpr[a->rd] & mask); break;
        case LOONGARCH_CSR_TLBRSAVE       :old_v = env->CSR_TLBRSAVE;    env->CSR_TLBRSAVE &= (~mask);    env->CSR_TLBRSAVE |= (env->gpr[a->rd] & mask); break;
        case LOONGARCH_CSR_TLBRELO0       :old_v = env->CSR_TLBRELO0;    env->CSR_TLBRELO0 &= (~mask);    env->CSR_TLBRELO0 |= (env->gpr[a->rd] & mask); break;
        case LOONGARCH_CSR_TLBRELO1       :old_v = env->CSR_TLBRELO1;    env->CSR_TLBRELO1 &= (~mask);    env->CSR_TLBRELO1 |= (env->gpr[a->rd] & mask); break;
        case LOONGARCH_CSR_TLBREHI        :old_v = env->CSR_TLBREHI;     env->CSR_TLBREHI &= (~mask);     env->CSR_TLBREHI |= (env->gpr[a->rd] & mask); break;
        case LOONGARCH_CSR_TLBRPRMD       :old_v = env->CSR_TLBRPRMD;    env->CSR_TLBRPRMD &= (~mask);    env->CSR_TLBRPRMD |= (env->gpr[a->rd] & mask); break;
        case LOONGARCH_CSR_MERRCTL        :old_v = env->CSR_MERRCTL;     env->CSR_MERRCTL &= (~mask);     env->CSR_MERRCTL |= (env->gpr[a->rd] & mask); break;
        case LOONGARCH_CSR_MERRINFO1      :old_v = env->CSR_MERRINFO1;   env->CSR_MERRINFO1 &= (~mask);   env->CSR_MERRINFO1 |= (env->gpr[a->rd] & mask); break;
        case LOONGARCH_CSR_MERRINFO2      :old_v = env->CSR_MERRINFO2;   env->CSR_MERRINFO2 &= (~mask);   env->CSR_MERRINFO2 |= (env->gpr[a->rd] & mask); break;
        case LOONGARCH_CSR_MERRENTRY      :old_v = env->CSR_MERRENTRY;   env->CSR_MERRENTRY &= (~mask);   env->CSR_MERRENTRY |= (env->gpr[a->rd] & mask); break;
        case LOONGARCH_CSR_MERRERA        :old_v = env->CSR_MERRERA;     env->CSR_MERRERA &= (~mask);     env->CSR_MERRERA |= (env->gpr[a->rd] & mask); break;
        case LOONGARCH_CSR_MERRSAVE       :old_v = env->CSR_MERRSAVE;    env->CSR_MERRSAVE &= (~mask);    env->CSR_MERRSAVE |= (env->gpr[a->rd] & mask); break;
        case LOONGARCH_CSR_CTAG           :old_v = env->CSR_CTAG;        env->CSR_CTAG &= (~mask);        env->CSR_CTAG |= (env->gpr[a->rd] & mask); break;
        case LOONGARCH_CSR_DMW(0)         :old_v = env->CSR_DMW[0];      env->CSR_DMW[0] &= (~mask);      env->CSR_DMW[0] |= (env->gpr[a->rd] & mask); break;
        case LOONGARCH_CSR_DMW(1)         :old_v = env->CSR_DMW[1];      env->CSR_DMW[1] &= (~mask);      env->CSR_DMW[1] |= (env->gpr[a->rd] & mask); break;
        case LOONGARCH_CSR_DMW(2)         :old_v = env->CSR_DMW[2];      env->CSR_DMW[2] &= (~mask);      env->CSR_DMW[2] |= (env->gpr[a->rd] & mask); break;
        case LOONGARCH_CSR_DMW(3)         :old_v = env->CSR_DMW[3];      env->CSR_DMW[3] &= (~mask);      env->CSR_DMW[3] |= (env->gpr[a->rd] & mask); break;
        case LOONGARCH_CSR_DBG            :old_v = env->CSR_DBG;         env->CSR_DBG &= (~mask);         env->CSR_DBG |= (env->gpr[a->rd] & mask); break;
        case LOONGARCH_CSR_DERA           :old_v = env->CSR_DERA;        env->CSR_DERA &= (~mask);        env->CSR_DERA |= (env->gpr[a->rd] & mask); break;
        case LOONGARCH_CSR_DSAVE          :old_v = env->CSR_DSAVE;       env->CSR_DSAVE &= (~mask);       env->CSR_DSAVE |= (env->gpr[a->rd] & mask); break;
        default:
            fprintf(stderr, "NOT IMPLEMENTED %s %x\n", __func__, a->csr);
    }
    env->gpr[a->rd] = old_v;
    env->pc += 4;
    return true;
}
static bool trans_iocsrrd_b(CPULoongArchState *env, arg_iocsrrd_b *a) {__NOT_IMPLEMENTED__}
static bool trans_iocsrrd_h(CPULoongArchState *env, arg_iocsrrd_h *a) {__NOT_IMPLEMENTED__}
static bool trans_iocsrrd_w(CPULoongArchState *env, arg_iocsrrd_w *a) {__NOT_IMPLEMENTED__}
static bool trans_iocsrrd_d(CPULoongArchState *env, arg_iocsrrd_d *a) {__NOT_IMPLEMENTED__}
static bool trans_iocsrwr_b(CPULoongArchState *env, arg_iocsrwr_b *a) {__NOT_IMPLEMENTED__}
static bool trans_iocsrwr_h(CPULoongArchState *env, arg_iocsrwr_h *a) {__NOT_IMPLEMENTED__}
static bool trans_iocsrwr_w(CPULoongArchState *env, arg_iocsrwr_w *a) {__NOT_IMPLEMENTED__}
static bool trans_iocsrwr_d(CPULoongArchState *env, arg_iocsrwr_d *a) {__NOT_IMPLEMENTED__}
static bool trans_tlbsrch(CPULoongArchState *env, arg_tlbsrch *a) {
    helper_tlbsrch(env);
    env->pc += 4;
    return true;
}
static bool trans_tlbrd(CPULoongArchState *env, arg_tlbrd *a) {
    helper_tlbrd(env);
    env->pc += 4;
    return true;
}
static bool trans_tlbwr(CPULoongArchState *env, arg_tlbwr *a) {
    helper_tlbwr(env);
    env->pc += 4;
    return true;
}
static bool trans_tlbfill(CPULoongArchState *env, arg_tlbfill *a) {
    helper_tlbfill(env);
    env->pc += 4;
    return true;
}
static bool trans_tlbclr(CPULoongArchState *env, arg_tlbclr *a) {__NOT_IMPLEMENTED__}
static bool trans_tlbflush(CPULoongArchState *env, arg_tlbflush *a) {__NOT_IMPLEMENTED__}
static bool trans_invtlb(CPULoongArchState *env, arg_invtlb *a) {
    helper_invtlb_all(env);
    env->pc += 4;
    return true;
}
static bool trans_cacop(CPULoongArchState *env, arg_cacop *a) {__NOT_IMPLEMENTED__}
static bool trans_lddir(CPULoongArchState *env, arg_lddir *a) {
    env->gpr[a->rd] = helper_lddir(env, env->gpr[a->rj], a->imm, 0);
    env->pc += 4;
    return true;
}
static bool trans_ldpte(CPULoongArchState *env, arg_ldpte *a) {
    helper_ldpte(env, env->gpr[a->rj], a->imm, 0);
    env->pc += 4;
    return true;
}
static bool trans_ertn(CPULoongArchState *env, arg_ertn *a) {
    helper_ertn(env);
    return true;
}
static bool trans_idle(CPULoongArchState *env, arg_idle *a) {__NOT_IMPLEMENTED__}
static bool trans_dbcl(CPULoongArchState *env, arg_dbcl *a) {__NOT_IMPLEMENTED__}
static bool trans_vadd_b(CPULoongArchState *env, arg_vadd_b *a) {__NOT_IMPLEMENTED__}
static bool trans_vadd_h(CPULoongArchState *env, arg_vadd_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vadd_w(CPULoongArchState *env, arg_vadd_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vadd_d(CPULoongArchState *env, arg_vadd_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vadd_q(CPULoongArchState *env, arg_vadd_q *a) {__NOT_IMPLEMENTED__}
static bool trans_vsub_b(CPULoongArchState *env, arg_vsub_b *a) {__NOT_IMPLEMENTED__}
static bool trans_vsub_h(CPULoongArchState *env, arg_vsub_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vsub_w(CPULoongArchState *env, arg_vsub_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vsub_d(CPULoongArchState *env, arg_vsub_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vsub_q(CPULoongArchState *env, arg_vsub_q *a) {__NOT_IMPLEMENTED__}
static bool trans_vaddi_bu(CPULoongArchState *env, arg_vaddi_bu *a) {__NOT_IMPLEMENTED__}
static bool trans_vaddi_hu(CPULoongArchState *env, arg_vaddi_hu *a) {__NOT_IMPLEMENTED__}
static bool trans_vaddi_wu(CPULoongArchState *env, arg_vaddi_wu *a) {__NOT_IMPLEMENTED__}
static bool trans_vaddi_du(CPULoongArchState *env, arg_vaddi_du *a) {__NOT_IMPLEMENTED__}
static bool trans_vsubi_bu(CPULoongArchState *env, arg_vsubi_bu *a) {__NOT_IMPLEMENTED__}
static bool trans_vsubi_hu(CPULoongArchState *env, arg_vsubi_hu *a) {__NOT_IMPLEMENTED__}
static bool trans_vsubi_wu(CPULoongArchState *env, arg_vsubi_wu *a) {__NOT_IMPLEMENTED__}
static bool trans_vsubi_du(CPULoongArchState *env, arg_vsubi_du *a) {__NOT_IMPLEMENTED__}
static bool trans_vneg_b(CPULoongArchState *env, arg_vneg_b *a) {__NOT_IMPLEMENTED__}
static bool trans_vneg_h(CPULoongArchState *env, arg_vneg_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vneg_w(CPULoongArchState *env, arg_vneg_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vneg_d(CPULoongArchState *env, arg_vneg_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vsadd_b(CPULoongArchState *env, arg_vsadd_b *a) {__NOT_IMPLEMENTED__}
static bool trans_vsadd_h(CPULoongArchState *env, arg_vsadd_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vsadd_w(CPULoongArchState *env, arg_vsadd_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vsadd_d(CPULoongArchState *env, arg_vsadd_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vsadd_bu(CPULoongArchState *env, arg_vsadd_bu *a) {__NOT_IMPLEMENTED__}
static bool trans_vsadd_hu(CPULoongArchState *env, arg_vsadd_hu *a) {__NOT_IMPLEMENTED__}
static bool trans_vsadd_wu(CPULoongArchState *env, arg_vsadd_wu *a) {__NOT_IMPLEMENTED__}
static bool trans_vsadd_du(CPULoongArchState *env, arg_vsadd_du *a) {__NOT_IMPLEMENTED__}
static bool trans_vssub_b(CPULoongArchState *env, arg_vssub_b *a) {__NOT_IMPLEMENTED__}
static bool trans_vssub_h(CPULoongArchState *env, arg_vssub_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vssub_w(CPULoongArchState *env, arg_vssub_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vssub_d(CPULoongArchState *env, arg_vssub_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vssub_bu(CPULoongArchState *env, arg_vssub_bu *a) {__NOT_IMPLEMENTED__}
static bool trans_vssub_hu(CPULoongArchState *env, arg_vssub_hu *a) {__NOT_IMPLEMENTED__}
static bool trans_vssub_wu(CPULoongArchState *env, arg_vssub_wu *a) {__NOT_IMPLEMENTED__}
static bool trans_vssub_du(CPULoongArchState *env, arg_vssub_du *a) {__NOT_IMPLEMENTED__}
static bool trans_vhaddw_h_b(CPULoongArchState *env, arg_vhaddw_h_b *a) {__NOT_IMPLEMENTED__}
static bool trans_vhaddw_w_h(CPULoongArchState *env, arg_vhaddw_w_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vhaddw_d_w(CPULoongArchState *env, arg_vhaddw_d_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vhaddw_q_d(CPULoongArchState *env, arg_vhaddw_q_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vhaddw_hu_bu(CPULoongArchState *env, arg_vhaddw_hu_bu *a) {__NOT_IMPLEMENTED__}
static bool trans_vhaddw_wu_hu(CPULoongArchState *env, arg_vhaddw_wu_hu *a) {__NOT_IMPLEMENTED__}
static bool trans_vhaddw_du_wu(CPULoongArchState *env, arg_vhaddw_du_wu *a) {__NOT_IMPLEMENTED__}
static bool trans_vhaddw_qu_du(CPULoongArchState *env, arg_vhaddw_qu_du *a) {__NOT_IMPLEMENTED__}
static bool trans_vhsubw_h_b(CPULoongArchState *env, arg_vhsubw_h_b *a) {__NOT_IMPLEMENTED__}
static bool trans_vhsubw_w_h(CPULoongArchState *env, arg_vhsubw_w_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vhsubw_d_w(CPULoongArchState *env, arg_vhsubw_d_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vhsubw_q_d(CPULoongArchState *env, arg_vhsubw_q_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vhsubw_hu_bu(CPULoongArchState *env, arg_vhsubw_hu_bu *a) {__NOT_IMPLEMENTED__}
static bool trans_vhsubw_wu_hu(CPULoongArchState *env, arg_vhsubw_wu_hu *a) {__NOT_IMPLEMENTED__}
static bool trans_vhsubw_du_wu(CPULoongArchState *env, arg_vhsubw_du_wu *a) {__NOT_IMPLEMENTED__}
static bool trans_vhsubw_qu_du(CPULoongArchState *env, arg_vhsubw_qu_du *a) {__NOT_IMPLEMENTED__}
static bool trans_vaddwev_h_b(CPULoongArchState *env, arg_vaddwev_h_b *a) {__NOT_IMPLEMENTED__}
static bool trans_vaddwev_w_h(CPULoongArchState *env, arg_vaddwev_w_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vaddwev_d_w(CPULoongArchState *env, arg_vaddwev_d_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vaddwev_q_d(CPULoongArchState *env, arg_vaddwev_q_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vaddwod_h_b(CPULoongArchState *env, arg_vaddwod_h_b *a) {__NOT_IMPLEMENTED__}
static bool trans_vaddwod_w_h(CPULoongArchState *env, arg_vaddwod_w_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vaddwod_d_w(CPULoongArchState *env, arg_vaddwod_d_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vaddwod_q_d(CPULoongArchState *env, arg_vaddwod_q_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vsubwev_h_b(CPULoongArchState *env, arg_vsubwev_h_b *a) {__NOT_IMPLEMENTED__}
static bool trans_vsubwev_w_h(CPULoongArchState *env, arg_vsubwev_w_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vsubwev_d_w(CPULoongArchState *env, arg_vsubwev_d_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vsubwev_q_d(CPULoongArchState *env, arg_vsubwev_q_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vsubwod_h_b(CPULoongArchState *env, arg_vsubwod_h_b *a) {__NOT_IMPLEMENTED__}
static bool trans_vsubwod_w_h(CPULoongArchState *env, arg_vsubwod_w_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vsubwod_d_w(CPULoongArchState *env, arg_vsubwod_d_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vsubwod_q_d(CPULoongArchState *env, arg_vsubwod_q_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vaddwev_h_bu(CPULoongArchState *env, arg_vaddwev_h_bu *a) {__NOT_IMPLEMENTED__}
static bool trans_vaddwev_w_hu(CPULoongArchState *env, arg_vaddwev_w_hu *a) {__NOT_IMPLEMENTED__}
static bool trans_vaddwev_d_wu(CPULoongArchState *env, arg_vaddwev_d_wu *a) {__NOT_IMPLEMENTED__}
static bool trans_vaddwev_q_du(CPULoongArchState *env, arg_vaddwev_q_du *a) {__NOT_IMPLEMENTED__}
static bool trans_vaddwod_h_bu(CPULoongArchState *env, arg_vaddwod_h_bu *a) {__NOT_IMPLEMENTED__}
static bool trans_vaddwod_w_hu(CPULoongArchState *env, arg_vaddwod_w_hu *a) {__NOT_IMPLEMENTED__}
static bool trans_vaddwod_d_wu(CPULoongArchState *env, arg_vaddwod_d_wu *a) {__NOT_IMPLEMENTED__}
static bool trans_vaddwod_q_du(CPULoongArchState *env, arg_vaddwod_q_du *a) {__NOT_IMPLEMENTED__}
static bool trans_vsubwev_h_bu(CPULoongArchState *env, arg_vsubwev_h_bu *a) {__NOT_IMPLEMENTED__}
static bool trans_vsubwev_w_hu(CPULoongArchState *env, arg_vsubwev_w_hu *a) {__NOT_IMPLEMENTED__}
static bool trans_vsubwev_d_wu(CPULoongArchState *env, arg_vsubwev_d_wu *a) {__NOT_IMPLEMENTED__}
static bool trans_vsubwev_q_du(CPULoongArchState *env, arg_vsubwev_q_du *a) {__NOT_IMPLEMENTED__}
static bool trans_vsubwod_h_bu(CPULoongArchState *env, arg_vsubwod_h_bu *a) {__NOT_IMPLEMENTED__}
static bool trans_vsubwod_w_hu(CPULoongArchState *env, arg_vsubwod_w_hu *a) {__NOT_IMPLEMENTED__}
static bool trans_vsubwod_d_wu(CPULoongArchState *env, arg_vsubwod_d_wu *a) {__NOT_IMPLEMENTED__}
static bool trans_vsubwod_q_du(CPULoongArchState *env, arg_vsubwod_q_du *a) {__NOT_IMPLEMENTED__}
static bool trans_vaddwev_h_bu_b(CPULoongArchState *env, arg_vaddwev_h_bu_b *a) {__NOT_IMPLEMENTED__}
static bool trans_vaddwev_w_hu_h(CPULoongArchState *env, arg_vaddwev_w_hu_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vaddwev_d_wu_w(CPULoongArchState *env, arg_vaddwev_d_wu_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vaddwev_q_du_d(CPULoongArchState *env, arg_vaddwev_q_du_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vaddwod_h_bu_b(CPULoongArchState *env, arg_vaddwod_h_bu_b *a) {__NOT_IMPLEMENTED__}
static bool trans_vaddwod_w_hu_h(CPULoongArchState *env, arg_vaddwod_w_hu_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vaddwod_d_wu_w(CPULoongArchState *env, arg_vaddwod_d_wu_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vaddwod_q_du_d(CPULoongArchState *env, arg_vaddwod_q_du_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vavg_b(CPULoongArchState *env, arg_vavg_b *a) {__NOT_IMPLEMENTED__}
static bool trans_vavg_h(CPULoongArchState *env, arg_vavg_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vavg_w(CPULoongArchState *env, arg_vavg_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vavg_d(CPULoongArchState *env, arg_vavg_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vavg_bu(CPULoongArchState *env, arg_vavg_bu *a) {__NOT_IMPLEMENTED__}
static bool trans_vavg_hu(CPULoongArchState *env, arg_vavg_hu *a) {__NOT_IMPLEMENTED__}
static bool trans_vavg_wu(CPULoongArchState *env, arg_vavg_wu *a) {__NOT_IMPLEMENTED__}
static bool trans_vavg_du(CPULoongArchState *env, arg_vavg_du *a) {__NOT_IMPLEMENTED__}
static bool trans_vavgr_b(CPULoongArchState *env, arg_vavgr_b *a) {__NOT_IMPLEMENTED__}
static bool trans_vavgr_h(CPULoongArchState *env, arg_vavgr_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vavgr_w(CPULoongArchState *env, arg_vavgr_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vavgr_d(CPULoongArchState *env, arg_vavgr_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vavgr_bu(CPULoongArchState *env, arg_vavgr_bu *a) {__NOT_IMPLEMENTED__}
static bool trans_vavgr_hu(CPULoongArchState *env, arg_vavgr_hu *a) {__NOT_IMPLEMENTED__}
static bool trans_vavgr_wu(CPULoongArchState *env, arg_vavgr_wu *a) {__NOT_IMPLEMENTED__}
static bool trans_vavgr_du(CPULoongArchState *env, arg_vavgr_du *a) {__NOT_IMPLEMENTED__}
static bool trans_vabsd_b(CPULoongArchState *env, arg_vabsd_b *a) {__NOT_IMPLEMENTED__}
static bool trans_vabsd_h(CPULoongArchState *env, arg_vabsd_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vabsd_w(CPULoongArchState *env, arg_vabsd_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vabsd_d(CPULoongArchState *env, arg_vabsd_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vabsd_bu(CPULoongArchState *env, arg_vabsd_bu *a) {__NOT_IMPLEMENTED__}
static bool trans_vabsd_hu(CPULoongArchState *env, arg_vabsd_hu *a) {__NOT_IMPLEMENTED__}
static bool trans_vabsd_wu(CPULoongArchState *env, arg_vabsd_wu *a) {__NOT_IMPLEMENTED__}
static bool trans_vabsd_du(CPULoongArchState *env, arg_vabsd_du *a) {__NOT_IMPLEMENTED__}
static bool trans_vadda_b(CPULoongArchState *env, arg_vadda_b *a) {__NOT_IMPLEMENTED__}
static bool trans_vadda_h(CPULoongArchState *env, arg_vadda_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vadda_w(CPULoongArchState *env, arg_vadda_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vadda_d(CPULoongArchState *env, arg_vadda_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vmax_b(CPULoongArchState *env, arg_vmax_b *a) {__NOT_IMPLEMENTED__}
static bool trans_vmax_h(CPULoongArchState *env, arg_vmax_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vmax_w(CPULoongArchState *env, arg_vmax_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vmax_d(CPULoongArchState *env, arg_vmax_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vmaxi_b(CPULoongArchState *env, arg_vmaxi_b *a) {__NOT_IMPLEMENTED__}
static bool trans_vmaxi_h(CPULoongArchState *env, arg_vmaxi_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vmaxi_w(CPULoongArchState *env, arg_vmaxi_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vmaxi_d(CPULoongArchState *env, arg_vmaxi_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vmax_bu(CPULoongArchState *env, arg_vmax_bu *a) {__NOT_IMPLEMENTED__}
static bool trans_vmax_hu(CPULoongArchState *env, arg_vmax_hu *a) {__NOT_IMPLEMENTED__}
static bool trans_vmax_wu(CPULoongArchState *env, arg_vmax_wu *a) {__NOT_IMPLEMENTED__}
static bool trans_vmax_du(CPULoongArchState *env, arg_vmax_du *a) {__NOT_IMPLEMENTED__}
static bool trans_vmaxi_bu(CPULoongArchState *env, arg_vmaxi_bu *a) {__NOT_IMPLEMENTED__}
static bool trans_vmaxi_hu(CPULoongArchState *env, arg_vmaxi_hu *a) {__NOT_IMPLEMENTED__}
static bool trans_vmaxi_wu(CPULoongArchState *env, arg_vmaxi_wu *a) {__NOT_IMPLEMENTED__}
static bool trans_vmaxi_du(CPULoongArchState *env, arg_vmaxi_du *a) {__NOT_IMPLEMENTED__}
static bool trans_vmin_b(CPULoongArchState *env, arg_vmin_b *a) {__NOT_IMPLEMENTED__}
static bool trans_vmin_h(CPULoongArchState *env, arg_vmin_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vmin_w(CPULoongArchState *env, arg_vmin_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vmin_d(CPULoongArchState *env, arg_vmin_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vmini_b(CPULoongArchState *env, arg_vmini_b *a) {__NOT_IMPLEMENTED__}
static bool trans_vmini_h(CPULoongArchState *env, arg_vmini_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vmini_w(CPULoongArchState *env, arg_vmini_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vmini_d(CPULoongArchState *env, arg_vmini_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vmin_bu(CPULoongArchState *env, arg_vmin_bu *a) {__NOT_IMPLEMENTED__}
static bool trans_vmin_hu(CPULoongArchState *env, arg_vmin_hu *a) {__NOT_IMPLEMENTED__}
static bool trans_vmin_wu(CPULoongArchState *env, arg_vmin_wu *a) {__NOT_IMPLEMENTED__}
static bool trans_vmin_du(CPULoongArchState *env, arg_vmin_du *a) {__NOT_IMPLEMENTED__}
static bool trans_vmini_bu(CPULoongArchState *env, arg_vmini_bu *a) {__NOT_IMPLEMENTED__}
static bool trans_vmini_hu(CPULoongArchState *env, arg_vmini_hu *a) {__NOT_IMPLEMENTED__}
static bool trans_vmini_wu(CPULoongArchState *env, arg_vmini_wu *a) {__NOT_IMPLEMENTED__}
static bool trans_vmini_du(CPULoongArchState *env, arg_vmini_du *a) {__NOT_IMPLEMENTED__}
static bool trans_vmul_b(CPULoongArchState *env, arg_vmul_b *a) {__NOT_IMPLEMENTED__}
static bool trans_vmul_h(CPULoongArchState *env, arg_vmul_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vmul_w(CPULoongArchState *env, arg_vmul_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vmul_d(CPULoongArchState *env, arg_vmul_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vmuh_b(CPULoongArchState *env, arg_vmuh_b *a) {__NOT_IMPLEMENTED__}
static bool trans_vmuh_h(CPULoongArchState *env, arg_vmuh_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vmuh_w(CPULoongArchState *env, arg_vmuh_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vmuh_d(CPULoongArchState *env, arg_vmuh_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vmuh_bu(CPULoongArchState *env, arg_vmuh_bu *a) {__NOT_IMPLEMENTED__}
static bool trans_vmuh_hu(CPULoongArchState *env, arg_vmuh_hu *a) {__NOT_IMPLEMENTED__}
static bool trans_vmuh_wu(CPULoongArchState *env, arg_vmuh_wu *a) {__NOT_IMPLEMENTED__}
static bool trans_vmuh_du(CPULoongArchState *env, arg_vmuh_du *a) {__NOT_IMPLEMENTED__}
static bool trans_vmulwev_h_b(CPULoongArchState *env, arg_vmulwev_h_b *a) {__NOT_IMPLEMENTED__}
static bool trans_vmulwev_w_h(CPULoongArchState *env, arg_vmulwev_w_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vmulwev_d_w(CPULoongArchState *env, arg_vmulwev_d_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vmulwev_q_d(CPULoongArchState *env, arg_vmulwev_q_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vmulwod_h_b(CPULoongArchState *env, arg_vmulwod_h_b *a) {__NOT_IMPLEMENTED__}
static bool trans_vmulwod_w_h(CPULoongArchState *env, arg_vmulwod_w_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vmulwod_d_w(CPULoongArchState *env, arg_vmulwod_d_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vmulwod_q_d(CPULoongArchState *env, arg_vmulwod_q_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vmulwev_h_bu(CPULoongArchState *env, arg_vmulwev_h_bu *a) {__NOT_IMPLEMENTED__}
static bool trans_vmulwev_w_hu(CPULoongArchState *env, arg_vmulwev_w_hu *a) {__NOT_IMPLEMENTED__}
static bool trans_vmulwev_d_wu(CPULoongArchState *env, arg_vmulwev_d_wu *a) {__NOT_IMPLEMENTED__}
static bool trans_vmulwev_q_du(CPULoongArchState *env, arg_vmulwev_q_du *a) {__NOT_IMPLEMENTED__}
static bool trans_vmulwod_h_bu(CPULoongArchState *env, arg_vmulwod_h_bu *a) {__NOT_IMPLEMENTED__}
static bool trans_vmulwod_w_hu(CPULoongArchState *env, arg_vmulwod_w_hu *a) {__NOT_IMPLEMENTED__}
static bool trans_vmulwod_d_wu(CPULoongArchState *env, arg_vmulwod_d_wu *a) {__NOT_IMPLEMENTED__}
static bool trans_vmulwod_q_du(CPULoongArchState *env, arg_vmulwod_q_du *a) {__NOT_IMPLEMENTED__}
static bool trans_vmulwev_h_bu_b(CPULoongArchState *env, arg_vmulwev_h_bu_b *a) {__NOT_IMPLEMENTED__}
static bool trans_vmulwev_w_hu_h(CPULoongArchState *env, arg_vmulwev_w_hu_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vmulwev_d_wu_w(CPULoongArchState *env, arg_vmulwev_d_wu_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vmulwev_q_du_d(CPULoongArchState *env, arg_vmulwev_q_du_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vmulwod_h_bu_b(CPULoongArchState *env, arg_vmulwod_h_bu_b *a) {__NOT_IMPLEMENTED__}
static bool trans_vmulwod_w_hu_h(CPULoongArchState *env, arg_vmulwod_w_hu_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vmulwod_d_wu_w(CPULoongArchState *env, arg_vmulwod_d_wu_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vmulwod_q_du_d(CPULoongArchState *env, arg_vmulwod_q_du_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vmadd_b(CPULoongArchState *env, arg_vmadd_b *a) {__NOT_IMPLEMENTED__}
static bool trans_vmadd_h(CPULoongArchState *env, arg_vmadd_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vmadd_w(CPULoongArchState *env, arg_vmadd_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vmadd_d(CPULoongArchState *env, arg_vmadd_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vmsub_b(CPULoongArchState *env, arg_vmsub_b *a) {__NOT_IMPLEMENTED__}
static bool trans_vmsub_h(CPULoongArchState *env, arg_vmsub_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vmsub_w(CPULoongArchState *env, arg_vmsub_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vmsub_d(CPULoongArchState *env, arg_vmsub_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vmaddwev_h_b(CPULoongArchState *env, arg_vmaddwev_h_b *a) {__NOT_IMPLEMENTED__}
static bool trans_vmaddwev_w_h(CPULoongArchState *env, arg_vmaddwev_w_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vmaddwev_d_w(CPULoongArchState *env, arg_vmaddwev_d_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vmaddwev_q_d(CPULoongArchState *env, arg_vmaddwev_q_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vmaddwod_h_b(CPULoongArchState *env, arg_vmaddwod_h_b *a) {__NOT_IMPLEMENTED__}
static bool trans_vmaddwod_w_h(CPULoongArchState *env, arg_vmaddwod_w_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vmaddwod_d_w(CPULoongArchState *env, arg_vmaddwod_d_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vmaddwod_q_d(CPULoongArchState *env, arg_vmaddwod_q_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vmaddwev_h_bu(CPULoongArchState *env, arg_vmaddwev_h_bu *a) {__NOT_IMPLEMENTED__}
static bool trans_vmaddwev_w_hu(CPULoongArchState *env, arg_vmaddwev_w_hu *a) {__NOT_IMPLEMENTED__}
static bool trans_vmaddwev_d_wu(CPULoongArchState *env, arg_vmaddwev_d_wu *a) {__NOT_IMPLEMENTED__}
static bool trans_vmaddwev_q_du(CPULoongArchState *env, arg_vmaddwev_q_du *a) {__NOT_IMPLEMENTED__}
static bool trans_vmaddwod_h_bu(CPULoongArchState *env, arg_vmaddwod_h_bu *a) {__NOT_IMPLEMENTED__}
static bool trans_vmaddwod_w_hu(CPULoongArchState *env, arg_vmaddwod_w_hu *a) {__NOT_IMPLEMENTED__}
static bool trans_vmaddwod_d_wu(CPULoongArchState *env, arg_vmaddwod_d_wu *a) {__NOT_IMPLEMENTED__}
static bool trans_vmaddwod_q_du(CPULoongArchState *env, arg_vmaddwod_q_du *a) {__NOT_IMPLEMENTED__}
static bool trans_vmaddwev_h_bu_b(CPULoongArchState *env, arg_vmaddwev_h_bu_b *a) {__NOT_IMPLEMENTED__}
static bool trans_vmaddwev_w_hu_h(CPULoongArchState *env, arg_vmaddwev_w_hu_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vmaddwev_d_wu_w(CPULoongArchState *env, arg_vmaddwev_d_wu_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vmaddwev_q_du_d(CPULoongArchState *env, arg_vmaddwev_q_du_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vmaddwod_h_bu_b(CPULoongArchState *env, arg_vmaddwod_h_bu_b *a) {__NOT_IMPLEMENTED__}
static bool trans_vmaddwod_w_hu_h(CPULoongArchState *env, arg_vmaddwod_w_hu_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vmaddwod_d_wu_w(CPULoongArchState *env, arg_vmaddwod_d_wu_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vmaddwod_q_du_d(CPULoongArchState *env, arg_vmaddwod_q_du_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vdiv_b(CPULoongArchState *env, arg_vdiv_b *a) {__NOT_IMPLEMENTED__}
static bool trans_vdiv_h(CPULoongArchState *env, arg_vdiv_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vdiv_w(CPULoongArchState *env, arg_vdiv_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vdiv_d(CPULoongArchState *env, arg_vdiv_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vdiv_bu(CPULoongArchState *env, arg_vdiv_bu *a) {__NOT_IMPLEMENTED__}
static bool trans_vdiv_hu(CPULoongArchState *env, arg_vdiv_hu *a) {__NOT_IMPLEMENTED__}
static bool trans_vdiv_wu(CPULoongArchState *env, arg_vdiv_wu *a) {__NOT_IMPLEMENTED__}
static bool trans_vdiv_du(CPULoongArchState *env, arg_vdiv_du *a) {__NOT_IMPLEMENTED__}
static bool trans_vmod_b(CPULoongArchState *env, arg_vmod_b *a) {__NOT_IMPLEMENTED__}
static bool trans_vmod_h(CPULoongArchState *env, arg_vmod_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vmod_w(CPULoongArchState *env, arg_vmod_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vmod_d(CPULoongArchState *env, arg_vmod_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vmod_bu(CPULoongArchState *env, arg_vmod_bu *a) {__NOT_IMPLEMENTED__}
static bool trans_vmod_hu(CPULoongArchState *env, arg_vmod_hu *a) {__NOT_IMPLEMENTED__}
static bool trans_vmod_wu(CPULoongArchState *env, arg_vmod_wu *a) {__NOT_IMPLEMENTED__}
static bool trans_vmod_du(CPULoongArchState *env, arg_vmod_du *a) {__NOT_IMPLEMENTED__}
static bool trans_vsat_b(CPULoongArchState *env, arg_vsat_b *a) {__NOT_IMPLEMENTED__}
static bool trans_vsat_h(CPULoongArchState *env, arg_vsat_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vsat_w(CPULoongArchState *env, arg_vsat_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vsat_d(CPULoongArchState *env, arg_vsat_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vsat_bu(CPULoongArchState *env, arg_vsat_bu *a) {__NOT_IMPLEMENTED__}
static bool trans_vsat_hu(CPULoongArchState *env, arg_vsat_hu *a) {__NOT_IMPLEMENTED__}
static bool trans_vsat_wu(CPULoongArchState *env, arg_vsat_wu *a) {__NOT_IMPLEMENTED__}
static bool trans_vsat_du(CPULoongArchState *env, arg_vsat_du *a) {__NOT_IMPLEMENTED__}
static bool trans_vexth_h_b(CPULoongArchState *env, arg_vexth_h_b *a) {__NOT_IMPLEMENTED__}
static bool trans_vexth_w_h(CPULoongArchState *env, arg_vexth_w_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vexth_d_w(CPULoongArchState *env, arg_vexth_d_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vexth_q_d(CPULoongArchState *env, arg_vexth_q_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vexth_hu_bu(CPULoongArchState *env, arg_vexth_hu_bu *a) {__NOT_IMPLEMENTED__}
static bool trans_vexth_wu_hu(CPULoongArchState *env, arg_vexth_wu_hu *a) {__NOT_IMPLEMENTED__}
static bool trans_vexth_du_wu(CPULoongArchState *env, arg_vexth_du_wu *a) {__NOT_IMPLEMENTED__}
static bool trans_vexth_qu_du(CPULoongArchState *env, arg_vexth_qu_du *a) {__NOT_IMPLEMENTED__}
static bool trans_vsigncov_b(CPULoongArchState *env, arg_vsigncov_b *a) {__NOT_IMPLEMENTED__}
static bool trans_vsigncov_h(CPULoongArchState *env, arg_vsigncov_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vsigncov_w(CPULoongArchState *env, arg_vsigncov_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vsigncov_d(CPULoongArchState *env, arg_vsigncov_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vmskltz_b(CPULoongArchState *env, arg_vmskltz_b *a) {__NOT_IMPLEMENTED__}
static bool trans_vmskltz_h(CPULoongArchState *env, arg_vmskltz_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vmskltz_w(CPULoongArchState *env, arg_vmskltz_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vmskltz_d(CPULoongArchState *env, arg_vmskltz_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vmskgez_b(CPULoongArchState *env, arg_vmskgez_b *a) {__NOT_IMPLEMENTED__}
static bool trans_vmsknz_b(CPULoongArchState *env, arg_vmsknz_b *a) {__NOT_IMPLEMENTED__}
static bool trans_vldi(CPULoongArchState *env, arg_vldi *a) {__NOT_IMPLEMENTED__}
static bool trans_vand_v(CPULoongArchState *env, arg_vand_v *a) {__NOT_IMPLEMENTED__}
static bool trans_vor_v(CPULoongArchState *env, arg_vor_v *a) {__NOT_IMPLEMENTED__}
static bool trans_vxor_v(CPULoongArchState *env, arg_vxor_v *a) {__NOT_IMPLEMENTED__}
static bool trans_vnor_v(CPULoongArchState *env, arg_vnor_v *a) {__NOT_IMPLEMENTED__}
static bool trans_vandn_v(CPULoongArchState *env, arg_vandn_v *a) {__NOT_IMPLEMENTED__}
static bool trans_vorn_v(CPULoongArchState *env, arg_vorn_v *a) {__NOT_IMPLEMENTED__}
static bool trans_vandi_b(CPULoongArchState *env, arg_vandi_b *a) {__NOT_IMPLEMENTED__}
static bool trans_vori_b(CPULoongArchState *env, arg_vori_b *a) {__NOT_IMPLEMENTED__}
static bool trans_vxori_b(CPULoongArchState *env, arg_vxori_b *a) {__NOT_IMPLEMENTED__}
static bool trans_vnori_b(CPULoongArchState *env, arg_vnori_b *a) {__NOT_IMPLEMENTED__}
static bool trans_vsll_b(CPULoongArchState *env, arg_vsll_b *a) {__NOT_IMPLEMENTED__}
static bool trans_vsll_h(CPULoongArchState *env, arg_vsll_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vsll_w(CPULoongArchState *env, arg_vsll_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vsll_d(CPULoongArchState *env, arg_vsll_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vslli_b(CPULoongArchState *env, arg_vslli_b *a) {__NOT_IMPLEMENTED__}
static bool trans_vslli_h(CPULoongArchState *env, arg_vslli_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vslli_w(CPULoongArchState *env, arg_vslli_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vslli_d(CPULoongArchState *env, arg_vslli_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vsrl_b(CPULoongArchState *env, arg_vsrl_b *a) {__NOT_IMPLEMENTED__}
static bool trans_vsrl_h(CPULoongArchState *env, arg_vsrl_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vsrl_w(CPULoongArchState *env, arg_vsrl_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vsrl_d(CPULoongArchState *env, arg_vsrl_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vsrli_b(CPULoongArchState *env, arg_vsrli_b *a) {__NOT_IMPLEMENTED__}
static bool trans_vsrli_h(CPULoongArchState *env, arg_vsrli_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vsrli_w(CPULoongArchState *env, arg_vsrli_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vsrli_d(CPULoongArchState *env, arg_vsrli_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vsra_b(CPULoongArchState *env, arg_vsra_b *a) {__NOT_IMPLEMENTED__}
static bool trans_vsra_h(CPULoongArchState *env, arg_vsra_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vsra_w(CPULoongArchState *env, arg_vsra_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vsra_d(CPULoongArchState *env, arg_vsra_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vsrai_b(CPULoongArchState *env, arg_vsrai_b *a) {__NOT_IMPLEMENTED__}
static bool trans_vsrai_h(CPULoongArchState *env, arg_vsrai_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vsrai_w(CPULoongArchState *env, arg_vsrai_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vsrai_d(CPULoongArchState *env, arg_vsrai_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vrotr_b(CPULoongArchState *env, arg_vrotr_b *a) {__NOT_IMPLEMENTED__}
static bool trans_vrotr_h(CPULoongArchState *env, arg_vrotr_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vrotr_w(CPULoongArchState *env, arg_vrotr_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vrotr_d(CPULoongArchState *env, arg_vrotr_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vrotri_b(CPULoongArchState *env, arg_vrotri_b *a) {__NOT_IMPLEMENTED__}
static bool trans_vrotri_h(CPULoongArchState *env, arg_vrotri_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vrotri_w(CPULoongArchState *env, arg_vrotri_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vrotri_d(CPULoongArchState *env, arg_vrotri_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vsllwil_h_b(CPULoongArchState *env, arg_vsllwil_h_b *a) {__NOT_IMPLEMENTED__}
static bool trans_vsllwil_w_h(CPULoongArchState *env, arg_vsllwil_w_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vsllwil_d_w(CPULoongArchState *env, arg_vsllwil_d_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vextl_q_d(CPULoongArchState *env, arg_vextl_q_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vsllwil_hu_bu(CPULoongArchState *env, arg_vsllwil_hu_bu *a) {__NOT_IMPLEMENTED__}
static bool trans_vsllwil_wu_hu(CPULoongArchState *env, arg_vsllwil_wu_hu *a) {__NOT_IMPLEMENTED__}
static bool trans_vsllwil_du_wu(CPULoongArchState *env, arg_vsllwil_du_wu *a) {__NOT_IMPLEMENTED__}
static bool trans_vextl_qu_du(CPULoongArchState *env, arg_vextl_qu_du *a) {__NOT_IMPLEMENTED__}
static bool trans_vsrlr_b(CPULoongArchState *env, arg_vsrlr_b *a) {__NOT_IMPLEMENTED__}
static bool trans_vsrlr_h(CPULoongArchState *env, arg_vsrlr_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vsrlr_w(CPULoongArchState *env, arg_vsrlr_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vsrlr_d(CPULoongArchState *env, arg_vsrlr_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vsrlri_b(CPULoongArchState *env, arg_vsrlri_b *a) {__NOT_IMPLEMENTED__}
static bool trans_vsrlri_h(CPULoongArchState *env, arg_vsrlri_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vsrlri_w(CPULoongArchState *env, arg_vsrlri_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vsrlri_d(CPULoongArchState *env, arg_vsrlri_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vsrar_b(CPULoongArchState *env, arg_vsrar_b *a) {__NOT_IMPLEMENTED__}
static bool trans_vsrar_h(CPULoongArchState *env, arg_vsrar_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vsrar_w(CPULoongArchState *env, arg_vsrar_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vsrar_d(CPULoongArchState *env, arg_vsrar_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vsrari_b(CPULoongArchState *env, arg_vsrari_b *a) {__NOT_IMPLEMENTED__}
static bool trans_vsrari_h(CPULoongArchState *env, arg_vsrari_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vsrari_w(CPULoongArchState *env, arg_vsrari_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vsrari_d(CPULoongArchState *env, arg_vsrari_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vsrln_b_h(CPULoongArchState *env, arg_vsrln_b_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vsrln_h_w(CPULoongArchState *env, arg_vsrln_h_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vsrln_w_d(CPULoongArchState *env, arg_vsrln_w_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vsran_b_h(CPULoongArchState *env, arg_vsran_b_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vsran_h_w(CPULoongArchState *env, arg_vsran_h_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vsran_w_d(CPULoongArchState *env, arg_vsran_w_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vsrlni_b_h(CPULoongArchState *env, arg_vsrlni_b_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vsrlni_h_w(CPULoongArchState *env, arg_vsrlni_h_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vsrlni_w_d(CPULoongArchState *env, arg_vsrlni_w_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vsrlni_d_q(CPULoongArchState *env, arg_vsrlni_d_q *a) {__NOT_IMPLEMENTED__}
static bool trans_vsrani_b_h(CPULoongArchState *env, arg_vsrani_b_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vsrani_h_w(CPULoongArchState *env, arg_vsrani_h_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vsrani_w_d(CPULoongArchState *env, arg_vsrani_w_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vsrani_d_q(CPULoongArchState *env, arg_vsrani_d_q *a) {__NOT_IMPLEMENTED__}
static bool trans_vsrlrn_b_h(CPULoongArchState *env, arg_vsrlrn_b_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vsrlrn_h_w(CPULoongArchState *env, arg_vsrlrn_h_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vsrlrn_w_d(CPULoongArchState *env, arg_vsrlrn_w_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vsrarn_b_h(CPULoongArchState *env, arg_vsrarn_b_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vsrarn_h_w(CPULoongArchState *env, arg_vsrarn_h_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vsrarn_w_d(CPULoongArchState *env, arg_vsrarn_w_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vsrlrni_b_h(CPULoongArchState *env, arg_vsrlrni_b_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vsrlrni_h_w(CPULoongArchState *env, arg_vsrlrni_h_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vsrlrni_w_d(CPULoongArchState *env, arg_vsrlrni_w_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vsrlrni_d_q(CPULoongArchState *env, arg_vsrlrni_d_q *a) {__NOT_IMPLEMENTED__}
static bool trans_vsrarni_b_h(CPULoongArchState *env, arg_vsrarni_b_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vsrarni_h_w(CPULoongArchState *env, arg_vsrarni_h_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vsrarni_w_d(CPULoongArchState *env, arg_vsrarni_w_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vsrarni_d_q(CPULoongArchState *env, arg_vsrarni_d_q *a) {__NOT_IMPLEMENTED__}
static bool trans_vssrln_b_h(CPULoongArchState *env, arg_vssrln_b_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vssrln_h_w(CPULoongArchState *env, arg_vssrln_h_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vssrln_w_d(CPULoongArchState *env, arg_vssrln_w_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vssran_b_h(CPULoongArchState *env, arg_vssran_b_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vssran_h_w(CPULoongArchState *env, arg_vssran_h_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vssran_w_d(CPULoongArchState *env, arg_vssran_w_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vssrln_bu_h(CPULoongArchState *env, arg_vssrln_bu_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vssrln_hu_w(CPULoongArchState *env, arg_vssrln_hu_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vssrln_wu_d(CPULoongArchState *env, arg_vssrln_wu_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vssran_bu_h(CPULoongArchState *env, arg_vssran_bu_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vssran_hu_w(CPULoongArchState *env, arg_vssran_hu_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vssran_wu_d(CPULoongArchState *env, arg_vssran_wu_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vssrlni_b_h(CPULoongArchState *env, arg_vssrlni_b_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vssrlni_h_w(CPULoongArchState *env, arg_vssrlni_h_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vssrlni_w_d(CPULoongArchState *env, arg_vssrlni_w_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vssrlni_d_q(CPULoongArchState *env, arg_vssrlni_d_q *a) {__NOT_IMPLEMENTED__}
static bool trans_vssrani_b_h(CPULoongArchState *env, arg_vssrani_b_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vssrani_h_w(CPULoongArchState *env, arg_vssrani_h_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vssrani_w_d(CPULoongArchState *env, arg_vssrani_w_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vssrani_d_q(CPULoongArchState *env, arg_vssrani_d_q *a) {__NOT_IMPLEMENTED__}
static bool trans_vssrlni_bu_h(CPULoongArchState *env, arg_vssrlni_bu_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vssrlni_hu_w(CPULoongArchState *env, arg_vssrlni_hu_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vssrlni_wu_d(CPULoongArchState *env, arg_vssrlni_wu_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vssrlni_du_q(CPULoongArchState *env, arg_vssrlni_du_q *a) {__NOT_IMPLEMENTED__}
static bool trans_vssrani_bu_h(CPULoongArchState *env, arg_vssrani_bu_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vssrani_hu_w(CPULoongArchState *env, arg_vssrani_hu_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vssrani_wu_d(CPULoongArchState *env, arg_vssrani_wu_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vssrani_du_q(CPULoongArchState *env, arg_vssrani_du_q *a) {__NOT_IMPLEMENTED__}
static bool trans_vssrlrn_b_h(CPULoongArchState *env, arg_vssrlrn_b_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vssrlrn_h_w(CPULoongArchState *env, arg_vssrlrn_h_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vssrlrn_w_d(CPULoongArchState *env, arg_vssrlrn_w_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vssrarn_b_h(CPULoongArchState *env, arg_vssrarn_b_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vssrarn_h_w(CPULoongArchState *env, arg_vssrarn_h_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vssrarn_w_d(CPULoongArchState *env, arg_vssrarn_w_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vssrlrn_bu_h(CPULoongArchState *env, arg_vssrlrn_bu_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vssrlrn_hu_w(CPULoongArchState *env, arg_vssrlrn_hu_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vssrlrn_wu_d(CPULoongArchState *env, arg_vssrlrn_wu_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vssrarn_bu_h(CPULoongArchState *env, arg_vssrarn_bu_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vssrarn_hu_w(CPULoongArchState *env, arg_vssrarn_hu_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vssrarn_wu_d(CPULoongArchState *env, arg_vssrarn_wu_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vssrlrni_b_h(CPULoongArchState *env, arg_vssrlrni_b_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vssrlrni_h_w(CPULoongArchState *env, arg_vssrlrni_h_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vssrlrni_w_d(CPULoongArchState *env, arg_vssrlrni_w_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vssrlrni_d_q(CPULoongArchState *env, arg_vssrlrni_d_q *a) {__NOT_IMPLEMENTED__}
static bool trans_vssrarni_b_h(CPULoongArchState *env, arg_vssrarni_b_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vssrarni_h_w(CPULoongArchState *env, arg_vssrarni_h_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vssrarni_w_d(CPULoongArchState *env, arg_vssrarni_w_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vssrarni_d_q(CPULoongArchState *env, arg_vssrarni_d_q *a) {__NOT_IMPLEMENTED__}
static bool trans_vssrlrni_bu_h(CPULoongArchState *env, arg_vssrlrni_bu_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vssrlrni_hu_w(CPULoongArchState *env, arg_vssrlrni_hu_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vssrlrni_wu_d(CPULoongArchState *env, arg_vssrlrni_wu_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vssrlrni_du_q(CPULoongArchState *env, arg_vssrlrni_du_q *a) {__NOT_IMPLEMENTED__}
static bool trans_vssrarni_bu_h(CPULoongArchState *env, arg_vssrarni_bu_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vssrarni_hu_w(CPULoongArchState *env, arg_vssrarni_hu_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vssrarni_wu_d(CPULoongArchState *env, arg_vssrarni_wu_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vssrarni_du_q(CPULoongArchState *env, arg_vssrarni_du_q *a) {__NOT_IMPLEMENTED__}
static bool trans_vclo_b(CPULoongArchState *env, arg_vclo_b *a) {__NOT_IMPLEMENTED__}
static bool trans_vclo_h(CPULoongArchState *env, arg_vclo_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vclo_w(CPULoongArchState *env, arg_vclo_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vclo_d(CPULoongArchState *env, arg_vclo_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vclz_b(CPULoongArchState *env, arg_vclz_b *a) {__NOT_IMPLEMENTED__}
static bool trans_vclz_h(CPULoongArchState *env, arg_vclz_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vclz_w(CPULoongArchState *env, arg_vclz_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vclz_d(CPULoongArchState *env, arg_vclz_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vpcnt_b(CPULoongArchState *env, arg_vpcnt_b *a) {__NOT_IMPLEMENTED__}
static bool trans_vpcnt_h(CPULoongArchState *env, arg_vpcnt_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vpcnt_w(CPULoongArchState *env, arg_vpcnt_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vpcnt_d(CPULoongArchState *env, arg_vpcnt_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vbitclr_b(CPULoongArchState *env, arg_vbitclr_b *a) {__NOT_IMPLEMENTED__}
static bool trans_vbitclr_h(CPULoongArchState *env, arg_vbitclr_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vbitclr_w(CPULoongArchState *env, arg_vbitclr_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vbitclr_d(CPULoongArchState *env, arg_vbitclr_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vbitclri_b(CPULoongArchState *env, arg_vbitclri_b *a) {__NOT_IMPLEMENTED__}
static bool trans_vbitclri_h(CPULoongArchState *env, arg_vbitclri_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vbitclri_w(CPULoongArchState *env, arg_vbitclri_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vbitclri_d(CPULoongArchState *env, arg_vbitclri_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vbitset_b(CPULoongArchState *env, arg_vbitset_b *a) {__NOT_IMPLEMENTED__}
static bool trans_vbitset_h(CPULoongArchState *env, arg_vbitset_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vbitset_w(CPULoongArchState *env, arg_vbitset_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vbitset_d(CPULoongArchState *env, arg_vbitset_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vbitseti_b(CPULoongArchState *env, arg_vbitseti_b *a) {__NOT_IMPLEMENTED__}
static bool trans_vbitseti_h(CPULoongArchState *env, arg_vbitseti_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vbitseti_w(CPULoongArchState *env, arg_vbitseti_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vbitseti_d(CPULoongArchState *env, arg_vbitseti_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vbitrev_b(CPULoongArchState *env, arg_vbitrev_b *a) {__NOT_IMPLEMENTED__}
static bool trans_vbitrev_h(CPULoongArchState *env, arg_vbitrev_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vbitrev_w(CPULoongArchState *env, arg_vbitrev_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vbitrev_d(CPULoongArchState *env, arg_vbitrev_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vbitrevi_b(CPULoongArchState *env, arg_vbitrevi_b *a) {__NOT_IMPLEMENTED__}
static bool trans_vbitrevi_h(CPULoongArchState *env, arg_vbitrevi_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vbitrevi_w(CPULoongArchState *env, arg_vbitrevi_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vbitrevi_d(CPULoongArchState *env, arg_vbitrevi_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vfrstp_b(CPULoongArchState *env, arg_vfrstp_b *a) {__NOT_IMPLEMENTED__}
static bool trans_vfrstp_h(CPULoongArchState *env, arg_vfrstp_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vfrstpi_b(CPULoongArchState *env, arg_vfrstpi_b *a) {__NOT_IMPLEMENTED__}
static bool trans_vfrstpi_h(CPULoongArchState *env, arg_vfrstpi_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vfadd_s(CPULoongArchState *env, arg_vfadd_s *a) {__NOT_IMPLEMENTED__}
static bool trans_vfadd_d(CPULoongArchState *env, arg_vfadd_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vfsub_s(CPULoongArchState *env, arg_vfsub_s *a) {__NOT_IMPLEMENTED__}
static bool trans_vfsub_d(CPULoongArchState *env, arg_vfsub_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vfmul_s(CPULoongArchState *env, arg_vfmul_s *a) {__NOT_IMPLEMENTED__}
static bool trans_vfmul_d(CPULoongArchState *env, arg_vfmul_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vfdiv_s(CPULoongArchState *env, arg_vfdiv_s *a) {__NOT_IMPLEMENTED__}
static bool trans_vfdiv_d(CPULoongArchState *env, arg_vfdiv_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vfmadd_s(CPULoongArchState *env, arg_vfmadd_s *a) {__NOT_IMPLEMENTED__}
static bool trans_vfmadd_d(CPULoongArchState *env, arg_vfmadd_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vfmsub_s(CPULoongArchState *env, arg_vfmsub_s *a) {__NOT_IMPLEMENTED__}
static bool trans_vfmsub_d(CPULoongArchState *env, arg_vfmsub_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vfnmadd_s(CPULoongArchState *env, arg_vfnmadd_s *a) {__NOT_IMPLEMENTED__}
static bool trans_vfnmadd_d(CPULoongArchState *env, arg_vfnmadd_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vfnmsub_s(CPULoongArchState *env, arg_vfnmsub_s *a) {__NOT_IMPLEMENTED__}
static bool trans_vfnmsub_d(CPULoongArchState *env, arg_vfnmsub_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vfmax_s(CPULoongArchState *env, arg_vfmax_s *a) {__NOT_IMPLEMENTED__}
static bool trans_vfmax_d(CPULoongArchState *env, arg_vfmax_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vfmin_s(CPULoongArchState *env, arg_vfmin_s *a) {__NOT_IMPLEMENTED__}
static bool trans_vfmin_d(CPULoongArchState *env, arg_vfmin_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vfmaxa_s(CPULoongArchState *env, arg_vfmaxa_s *a) {__NOT_IMPLEMENTED__}
static bool trans_vfmaxa_d(CPULoongArchState *env, arg_vfmaxa_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vfmina_s(CPULoongArchState *env, arg_vfmina_s *a) {__NOT_IMPLEMENTED__}
static bool trans_vfmina_d(CPULoongArchState *env, arg_vfmina_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vflogb_s(CPULoongArchState *env, arg_vflogb_s *a) {__NOT_IMPLEMENTED__}
static bool trans_vflogb_d(CPULoongArchState *env, arg_vflogb_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vfclass_s(CPULoongArchState *env, arg_vfclass_s *a) {__NOT_IMPLEMENTED__}
static bool trans_vfclass_d(CPULoongArchState *env, arg_vfclass_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vfsqrt_s(CPULoongArchState *env, arg_vfsqrt_s *a) {__NOT_IMPLEMENTED__}
static bool trans_vfsqrt_d(CPULoongArchState *env, arg_vfsqrt_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vfrecip_s(CPULoongArchState *env, arg_vfrecip_s *a) {__NOT_IMPLEMENTED__}
static bool trans_vfrecip_d(CPULoongArchState *env, arg_vfrecip_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vfrsqrt_s(CPULoongArchState *env, arg_vfrsqrt_s *a) {__NOT_IMPLEMENTED__}
static bool trans_vfrsqrt_d(CPULoongArchState *env, arg_vfrsqrt_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vfcvtl_s_h(CPULoongArchState *env, arg_vfcvtl_s_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vfcvth_s_h(CPULoongArchState *env, arg_vfcvth_s_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vfcvtl_d_s(CPULoongArchState *env, arg_vfcvtl_d_s *a) {__NOT_IMPLEMENTED__}
static bool trans_vfcvth_d_s(CPULoongArchState *env, arg_vfcvth_d_s *a) {__NOT_IMPLEMENTED__}
static bool trans_vfcvt_h_s(CPULoongArchState *env, arg_vfcvt_h_s *a) {__NOT_IMPLEMENTED__}
static bool trans_vfcvt_s_d(CPULoongArchState *env, arg_vfcvt_s_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vfrint_s(CPULoongArchState *env, arg_vfrint_s *a) {__NOT_IMPLEMENTED__}
static bool trans_vfrint_d(CPULoongArchState *env, arg_vfrint_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vfrintrm_s(CPULoongArchState *env, arg_vfrintrm_s *a) {__NOT_IMPLEMENTED__}
static bool trans_vfrintrm_d(CPULoongArchState *env, arg_vfrintrm_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vfrintrp_s(CPULoongArchState *env, arg_vfrintrp_s *a) {__NOT_IMPLEMENTED__}
static bool trans_vfrintrp_d(CPULoongArchState *env, arg_vfrintrp_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vfrintrz_s(CPULoongArchState *env, arg_vfrintrz_s *a) {__NOT_IMPLEMENTED__}
static bool trans_vfrintrz_d(CPULoongArchState *env, arg_vfrintrz_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vfrintrne_s(CPULoongArchState *env, arg_vfrintrne_s *a) {__NOT_IMPLEMENTED__}
static bool trans_vfrintrne_d(CPULoongArchState *env, arg_vfrintrne_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vftint_w_s(CPULoongArchState *env, arg_vftint_w_s *a) {__NOT_IMPLEMENTED__}
static bool trans_vftint_l_d(CPULoongArchState *env, arg_vftint_l_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vftintrm_w_s(CPULoongArchState *env, arg_vftintrm_w_s *a) {__NOT_IMPLEMENTED__}
static bool trans_vftintrm_l_d(CPULoongArchState *env, arg_vftintrm_l_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vftintrp_w_s(CPULoongArchState *env, arg_vftintrp_w_s *a) {__NOT_IMPLEMENTED__}
static bool trans_vftintrp_l_d(CPULoongArchState *env, arg_vftintrp_l_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vftintrz_w_s(CPULoongArchState *env, arg_vftintrz_w_s *a) {__NOT_IMPLEMENTED__}
static bool trans_vftintrz_l_d(CPULoongArchState *env, arg_vftintrz_l_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vftintrne_w_s(CPULoongArchState *env, arg_vftintrne_w_s *a) {__NOT_IMPLEMENTED__}
static bool trans_vftintrne_l_d(CPULoongArchState *env, arg_vftintrne_l_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vftint_wu_s(CPULoongArchState *env, arg_vftint_wu_s *a) {__NOT_IMPLEMENTED__}
static bool trans_vftint_lu_d(CPULoongArchState *env, arg_vftint_lu_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vftintrz_wu_s(CPULoongArchState *env, arg_vftintrz_wu_s *a) {__NOT_IMPLEMENTED__}
static bool trans_vftintrz_lu_d(CPULoongArchState *env, arg_vftintrz_lu_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vftint_w_d(CPULoongArchState *env, arg_vftint_w_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vftintrm_w_d(CPULoongArchState *env, arg_vftintrm_w_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vftintrp_w_d(CPULoongArchState *env, arg_vftintrp_w_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vftintrz_w_d(CPULoongArchState *env, arg_vftintrz_w_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vftintrne_w_d(CPULoongArchState *env, arg_vftintrne_w_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vftintl_l_s(CPULoongArchState *env, arg_vftintl_l_s *a) {__NOT_IMPLEMENTED__}
static bool trans_vftinth_l_s(CPULoongArchState *env, arg_vftinth_l_s *a) {__NOT_IMPLEMENTED__}
static bool trans_vftintrml_l_s(CPULoongArchState *env, arg_vftintrml_l_s *a) {__NOT_IMPLEMENTED__}
static bool trans_vftintrmh_l_s(CPULoongArchState *env, arg_vftintrmh_l_s *a) {__NOT_IMPLEMENTED__}
static bool trans_vftintrpl_l_s(CPULoongArchState *env, arg_vftintrpl_l_s *a) {__NOT_IMPLEMENTED__}
static bool trans_vftintrph_l_s(CPULoongArchState *env, arg_vftintrph_l_s *a) {__NOT_IMPLEMENTED__}
static bool trans_vftintrzl_l_s(CPULoongArchState *env, arg_vftintrzl_l_s *a) {__NOT_IMPLEMENTED__}
static bool trans_vftintrzh_l_s(CPULoongArchState *env, arg_vftintrzh_l_s *a) {__NOT_IMPLEMENTED__}
static bool trans_vftintrnel_l_s(CPULoongArchState *env, arg_vftintrnel_l_s *a) {__NOT_IMPLEMENTED__}
static bool trans_vftintrneh_l_s(CPULoongArchState *env, arg_vftintrneh_l_s *a) {__NOT_IMPLEMENTED__}
static bool trans_vffint_s_w(CPULoongArchState *env, arg_vffint_s_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vffint_s_wu(CPULoongArchState *env, arg_vffint_s_wu *a) {__NOT_IMPLEMENTED__}
static bool trans_vffint_d_l(CPULoongArchState *env, arg_vffint_d_l *a) {__NOT_IMPLEMENTED__}
static bool trans_vffint_d_lu(CPULoongArchState *env, arg_vffint_d_lu *a) {__NOT_IMPLEMENTED__}
static bool trans_vffintl_d_w(CPULoongArchState *env, arg_vffintl_d_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vffinth_d_w(CPULoongArchState *env, arg_vffinth_d_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vffint_s_l(CPULoongArchState *env, arg_vffint_s_l *a) {__NOT_IMPLEMENTED__}
static bool trans_vseq_b(CPULoongArchState *env, arg_vseq_b *a) {__NOT_IMPLEMENTED__}
static bool trans_vseq_h(CPULoongArchState *env, arg_vseq_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vseq_w(CPULoongArchState *env, arg_vseq_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vseq_d(CPULoongArchState *env, arg_vseq_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vseqi_b(CPULoongArchState *env, arg_vseqi_b *a) {__NOT_IMPLEMENTED__}
static bool trans_vseqi_h(CPULoongArchState *env, arg_vseqi_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vseqi_w(CPULoongArchState *env, arg_vseqi_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vseqi_d(CPULoongArchState *env, arg_vseqi_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vsle_b(CPULoongArchState *env, arg_vsle_b *a) {__NOT_IMPLEMENTED__}
static bool trans_vsle_h(CPULoongArchState *env, arg_vsle_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vsle_w(CPULoongArchState *env, arg_vsle_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vsle_d(CPULoongArchState *env, arg_vsle_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vslei_b(CPULoongArchState *env, arg_vslei_b *a) {__NOT_IMPLEMENTED__}
static bool trans_vslei_h(CPULoongArchState *env, arg_vslei_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vslei_w(CPULoongArchState *env, arg_vslei_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vslei_d(CPULoongArchState *env, arg_vslei_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vsle_bu(CPULoongArchState *env, arg_vsle_bu *a) {__NOT_IMPLEMENTED__}
static bool trans_vsle_hu(CPULoongArchState *env, arg_vsle_hu *a) {__NOT_IMPLEMENTED__}
static bool trans_vsle_wu(CPULoongArchState *env, arg_vsle_wu *a) {__NOT_IMPLEMENTED__}
static bool trans_vsle_du(CPULoongArchState *env, arg_vsle_du *a) {__NOT_IMPLEMENTED__}
static bool trans_vslei_bu(CPULoongArchState *env, arg_vslei_bu *a) {__NOT_IMPLEMENTED__}
static bool trans_vslei_hu(CPULoongArchState *env, arg_vslei_hu *a) {__NOT_IMPLEMENTED__}
static bool trans_vslei_wu(CPULoongArchState *env, arg_vslei_wu *a) {__NOT_IMPLEMENTED__}
static bool trans_vslei_du(CPULoongArchState *env, arg_vslei_du *a) {__NOT_IMPLEMENTED__}
static bool trans_vslt_b(CPULoongArchState *env, arg_vslt_b *a) {__NOT_IMPLEMENTED__}
static bool trans_vslt_h(CPULoongArchState *env, arg_vslt_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vslt_w(CPULoongArchState *env, arg_vslt_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vslt_d(CPULoongArchState *env, arg_vslt_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vslti_b(CPULoongArchState *env, arg_vslti_b *a) {__NOT_IMPLEMENTED__}
static bool trans_vslti_h(CPULoongArchState *env, arg_vslti_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vslti_w(CPULoongArchState *env, arg_vslti_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vslti_d(CPULoongArchState *env, arg_vslti_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vslt_bu(CPULoongArchState *env, arg_vslt_bu *a) {__NOT_IMPLEMENTED__}
static bool trans_vslt_hu(CPULoongArchState *env, arg_vslt_hu *a) {__NOT_IMPLEMENTED__}
static bool trans_vslt_wu(CPULoongArchState *env, arg_vslt_wu *a) {__NOT_IMPLEMENTED__}
static bool trans_vslt_du(CPULoongArchState *env, arg_vslt_du *a) {__NOT_IMPLEMENTED__}
static bool trans_vslti_bu(CPULoongArchState *env, arg_vslti_bu *a) {__NOT_IMPLEMENTED__}
static bool trans_vslti_hu(CPULoongArchState *env, arg_vslti_hu *a) {__NOT_IMPLEMENTED__}
static bool trans_vslti_wu(CPULoongArchState *env, arg_vslti_wu *a) {__NOT_IMPLEMENTED__}
static bool trans_vslti_du(CPULoongArchState *env, arg_vslti_du *a) {__NOT_IMPLEMENTED__}
static bool trans_vfcmp_cond_s(CPULoongArchState *env, arg_vfcmp_cond_s *a) {__NOT_IMPLEMENTED__}
static bool trans_vfcmp_cond_d(CPULoongArchState *env, arg_vfcmp_cond_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vbitsel_v(CPULoongArchState *env, arg_vbitsel_v *a) {__NOT_IMPLEMENTED__}
static bool trans_vbitseli_b(CPULoongArchState *env, arg_vbitseli_b *a) {__NOT_IMPLEMENTED__}
static bool trans_vseteqz_v(CPULoongArchState *env, arg_vseteqz_v *a) {__NOT_IMPLEMENTED__}
static bool trans_vsetnez_v(CPULoongArchState *env, arg_vsetnez_v *a) {__NOT_IMPLEMENTED__}
static bool trans_vsetanyeqz_b(CPULoongArchState *env, arg_vsetanyeqz_b *a) {__NOT_IMPLEMENTED__}
static bool trans_vsetanyeqz_h(CPULoongArchState *env, arg_vsetanyeqz_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vsetanyeqz_w(CPULoongArchState *env, arg_vsetanyeqz_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vsetanyeqz_d(CPULoongArchState *env, arg_vsetanyeqz_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vsetallnez_b(CPULoongArchState *env, arg_vsetallnez_b *a) {__NOT_IMPLEMENTED__}
static bool trans_vsetallnez_h(CPULoongArchState *env, arg_vsetallnez_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vsetallnez_w(CPULoongArchState *env, arg_vsetallnez_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vsetallnez_d(CPULoongArchState *env, arg_vsetallnez_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vinsgr2vr_b(CPULoongArchState *env, arg_vinsgr2vr_b *a) {__NOT_IMPLEMENTED__}
static bool trans_vinsgr2vr_h(CPULoongArchState *env, arg_vinsgr2vr_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vinsgr2vr_w(CPULoongArchState *env, arg_vinsgr2vr_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vinsgr2vr_d(CPULoongArchState *env, arg_vinsgr2vr_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vpickve2gr_b(CPULoongArchState *env, arg_vpickve2gr_b *a) {__NOT_IMPLEMENTED__}
static bool trans_vpickve2gr_h(CPULoongArchState *env, arg_vpickve2gr_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vpickve2gr_w(CPULoongArchState *env, arg_vpickve2gr_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vpickve2gr_d(CPULoongArchState *env, arg_vpickve2gr_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vpickve2gr_bu(CPULoongArchState *env, arg_vpickve2gr_bu *a) {__NOT_IMPLEMENTED__}
static bool trans_vpickve2gr_hu(CPULoongArchState *env, arg_vpickve2gr_hu *a) {__NOT_IMPLEMENTED__}
static bool trans_vpickve2gr_wu(CPULoongArchState *env, arg_vpickve2gr_wu *a) {__NOT_IMPLEMENTED__}
static bool trans_vpickve2gr_du(CPULoongArchState *env, arg_vpickve2gr_du *a) {__NOT_IMPLEMENTED__}
static bool trans_vreplgr2vr_b(CPULoongArchState *env, arg_vreplgr2vr_b *a) {__NOT_IMPLEMENTED__}
static bool trans_vreplgr2vr_h(CPULoongArchState *env, arg_vreplgr2vr_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vreplgr2vr_w(CPULoongArchState *env, arg_vreplgr2vr_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vreplgr2vr_d(CPULoongArchState *env, arg_vreplgr2vr_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vreplve_b(CPULoongArchState *env, arg_vreplve_b *a) {__NOT_IMPLEMENTED__}
static bool trans_vreplve_h(CPULoongArchState *env, arg_vreplve_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vreplve_w(CPULoongArchState *env, arg_vreplve_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vreplve_d(CPULoongArchState *env, arg_vreplve_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vreplvei_b(CPULoongArchState *env, arg_vreplvei_b *a) {__NOT_IMPLEMENTED__}
static bool trans_vreplvei_h(CPULoongArchState *env, arg_vreplvei_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vreplvei_w(CPULoongArchState *env, arg_vreplvei_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vreplvei_d(CPULoongArchState *env, arg_vreplvei_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vbsll_v(CPULoongArchState *env, arg_vbsll_v *a) {__NOT_IMPLEMENTED__}
static bool trans_vbsrl_v(CPULoongArchState *env, arg_vbsrl_v *a) {__NOT_IMPLEMENTED__}
static bool trans_vpackev_b(CPULoongArchState *env, arg_vpackev_b *a) {__NOT_IMPLEMENTED__}
static bool trans_vpackev_h(CPULoongArchState *env, arg_vpackev_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vpackev_w(CPULoongArchState *env, arg_vpackev_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vpackev_d(CPULoongArchState *env, arg_vpackev_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vpackod_b(CPULoongArchState *env, arg_vpackod_b *a) {__NOT_IMPLEMENTED__}
static bool trans_vpackod_h(CPULoongArchState *env, arg_vpackod_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vpackod_w(CPULoongArchState *env, arg_vpackod_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vpackod_d(CPULoongArchState *env, arg_vpackod_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vpickev_b(CPULoongArchState *env, arg_vpickev_b *a) {__NOT_IMPLEMENTED__}
static bool trans_vpickev_h(CPULoongArchState *env, arg_vpickev_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vpickev_w(CPULoongArchState *env, arg_vpickev_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vpickev_d(CPULoongArchState *env, arg_vpickev_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vpickod_b(CPULoongArchState *env, arg_vpickod_b *a) {__NOT_IMPLEMENTED__}
static bool trans_vpickod_h(CPULoongArchState *env, arg_vpickod_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vpickod_w(CPULoongArchState *env, arg_vpickod_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vpickod_d(CPULoongArchState *env, arg_vpickod_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vilvl_b(CPULoongArchState *env, arg_vilvl_b *a) {__NOT_IMPLEMENTED__}
static bool trans_vilvl_h(CPULoongArchState *env, arg_vilvl_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vilvl_w(CPULoongArchState *env, arg_vilvl_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vilvl_d(CPULoongArchState *env, arg_vilvl_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vilvh_b(CPULoongArchState *env, arg_vilvh_b *a) {__NOT_IMPLEMENTED__}
static bool trans_vilvh_h(CPULoongArchState *env, arg_vilvh_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vilvh_w(CPULoongArchState *env, arg_vilvh_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vilvh_d(CPULoongArchState *env, arg_vilvh_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vshuf_b(CPULoongArchState *env, arg_vshuf_b *a) {__NOT_IMPLEMENTED__}
static bool trans_vshuf_h(CPULoongArchState *env, arg_vshuf_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vshuf_w(CPULoongArchState *env, arg_vshuf_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vshuf_d(CPULoongArchState *env, arg_vshuf_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vshuf4i_b(CPULoongArchState *env, arg_vshuf4i_b *a) {__NOT_IMPLEMENTED__}
static bool trans_vshuf4i_h(CPULoongArchState *env, arg_vshuf4i_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vshuf4i_w(CPULoongArchState *env, arg_vshuf4i_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vshuf4i_d(CPULoongArchState *env, arg_vshuf4i_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vpermi_w(CPULoongArchState *env, arg_vpermi_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vextrins_d(CPULoongArchState *env, arg_vextrins_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vextrins_w(CPULoongArchState *env, arg_vextrins_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vextrins_h(CPULoongArchState *env, arg_vextrins_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vextrins_b(CPULoongArchState *env, arg_vextrins_b *a) {__NOT_IMPLEMENTED__}
static bool trans_vld(CPULoongArchState *env, arg_vld *a) {__NOT_IMPLEMENTED__}
static bool trans_vst(CPULoongArchState *env, arg_vst *a) {__NOT_IMPLEMENTED__}
static bool trans_vldx(CPULoongArchState *env, arg_vldx *a) {__NOT_IMPLEMENTED__}
static bool trans_vstx(CPULoongArchState *env, arg_vstx *a) {__NOT_IMPLEMENTED__}
static bool trans_vldrepl_d(CPULoongArchState *env, arg_vldrepl_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vldrepl_w(CPULoongArchState *env, arg_vldrepl_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vldrepl_h(CPULoongArchState *env, arg_vldrepl_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vldrepl_b(CPULoongArchState *env, arg_vldrepl_b *a) {__NOT_IMPLEMENTED__}
static bool trans_vstelm_d(CPULoongArchState *env, arg_vstelm_d *a) {__NOT_IMPLEMENTED__}
static bool trans_vstelm_w(CPULoongArchState *env, arg_vstelm_w *a) {__NOT_IMPLEMENTED__}
static bool trans_vstelm_h(CPULoongArchState *env, arg_vstelm_h *a) {__NOT_IMPLEMENTED__}
static bool trans_vstelm_b(CPULoongArchState *env, arg_vstelm_b *a) {__NOT_IMPLEMENTED__}

bool interpreter(CPULoongArchState *env, uint32_t insn) {
    if (env->pc == 0) {
        fprintf(stderr, "**************PC:%lx\n", env->pc);
        for (int i = 0; i < 32; i++) {
            fprintf(stderr, "r%02d:%lx\n", i, env->gpr[i]);
        }
    }
    if (decode(env, insn)) {
        env->gpr[0] = 0;


        return true;
    } else {
        return false;
    }
}