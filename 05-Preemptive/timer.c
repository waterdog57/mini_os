#include "riscv.h"
#include "timer.h"

#define interval 10000000 // cycles; about 1 second in qemu.

reg_t cpu_scratch[NCPU][32] = {0};

static inline void timecmp_set(int hartid, uint32_t _interval) {
    REG32(CLINT_MTIMECMP(hartid)) = REG32(CLINT_MTIME) + _interval;
}

void timer_init(void){
    int id = r_mhartid();
    timecmp_set(id, interval);
    w_mscratch((reg_t)&cpu_scratch[id][0]);
    w_mie(r_mie() | (MIE_MTIE));
}

void timer_handler(void){
    uint32_t id = (uint32_t)r_mhartid();
    myprintf("timer interrupt %d\n", id);
    timecmp_set(id, interval);
}

