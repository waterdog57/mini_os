#include "riscv.h"
#include "task.h"
#include "timer.h"

extern void trap_vector();

void trap_init(void){
    w_mtvec((reg_t)trap_vector);
    w_mstatus( r_mstatus() | MSTATUS_MIE );
}

reg_t trap_handler(reg_t epc, reg_t cause){
    uint32_t id = (uint32_t)r_mhartid();
    reg_t return_pc = epc;

    reg_t cause_code = cause & 0xfff;

    if(cause & (1<<31)){
        switch(cause_code){
            case 3:
                myprintf("soft interrupt\n");
                break;
            case 7:
                myprintf("timer interrupt\n");
                w_mie(r_mie() & ~(MIE_MTIE));
                timer_handler();
                return_pc = (reg_t)&task_os;
                w_mie(r_mie() | (MIE_MTIE));
                break;
            case 11:
                myprintf("external interrupt\n");
                break;
        }
    
       
    }
    return return_pc;
}