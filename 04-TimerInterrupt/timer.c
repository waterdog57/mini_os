#include "timer.h"

#define interval 10000000 // cycles; about 1 second in qemu.

void timer_init(void){

}

static inline void timecmp_set(int hartid, uint32_t _interval) {
    REG32(CLINT_MTIMECMP(hartid)) = REG32(CLINT_MTIME) + _interval;
}

reg_t timer_handler(reg_t epc, reg_t cause){
    int id = r_mhartid();
    reg_t return_pc = epc;
    w_mie(r_mie() & ~(MIE_MTIE));
    lib_puts("timer interrupt...\n");
    timecmp_set(id, interval);
    w_mie(r_mie() | (MIE_MTIE));
    return return_pc;
}

