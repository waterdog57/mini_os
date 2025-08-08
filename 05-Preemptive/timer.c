#include "timer.h"


#define interval 10000000 // cycles; about 1 second in qemu.


static inline void timecmp_set(int hartid, uint32_t _interval) {
    REG32(CLINT_MTIMECMP(hartid)) = REG32(CLINT_MTIME) + _interval;
}

void timer_init(void){
    int id = r_mhartid();
    w_mtvec((uint32_t)sys_timer);
    timecmp_set(id, interval);
    w_mie(r_mie() | (MIE_MTIE));
    w_mstatus( r_mstatus() | MSTATUS_MIE );
}

reg_t timer_handler(reg_t epc, reg_t cause){
    uint32_t id = (uint32_t)r_mhartid();
    reg_t return_pc = epc;
    w_mie(r_mie() & ~(MIE_MTIE));
    myprintf("timer interrupt %d\n", id);
    timecmp_set(id, interval);
    w_mie(r_mie() | (MIE_MTIE));
    return return_pc;
}

