#include "riscv.h"
#include "task.h"
#include "timer.h"
#include "os.h"

extern void trap_vector();

void trap_init(void){
    w_mtvec((reg_t)trap_vector);
   
}

static void external_handler()
{
    int irq = plic_claim();
    if (irq == UART_IRQ){
        lib_isr();
    }
    else if (irq){
        myprintf("unexpected interrupt irq = %d\n", irq);
    }

    if (irq){
        plic_complete(irq);
    }
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
                timer_handler();
                return_pc = (reg_t)&task_os;
                break;
            case 11:
                myprintf("external interrupt\n");
                external_handler();
                break;
            default:
                myprintf("other\n");
                break;
        }
    
    }else{
        // exception here.
        myprintf("exception\n");
    }
    return return_pc;
}