#include "riscv.h"

#define PLIC_BASE             ( 0xc000000 )
#define PLIC_PRIORITY(id)     (PLIC_BASE + (id)*4)
#define PLIC_PENDING(id)      (PLIC_BASE + 0x1000 + ((id) / 32))
#define PLIC_MENABLE(hart)    (PLIC_BASE + 0x2000 + (hart)*0x80)
#define PLIC_MTHRESHOLD(hart) (PLIC_BASE + 0x200000 + (hart)*0x1000)
#define PLIC_MCLAIM(hart)     (PLIC_BASE + 0x200004 + (hart)*0x1000)
#define PLIC_MCOMPLETE(hart)  (PLIC_BASE + 0x200004 + (hart)*0x1000)

void plic_init(void){
    int hart = r_tp();
    // QEMU Virt machine support 7 priority (1 - 7),
    // The "0" is reserved, and the lowest priority is "1".
    REG32( PLIC_PRIORITY(UART_IRQ) ) = 1;
    REG32( PLIC_MENABLE(hart) ) = 1 << UART_IRQ;
    REG32( PLIC_MTHRESHOLD( hart ) ) = 0;
    w_mie(r_mie() | ( MIE_MSIE ));
    w_mstatus( r_mstatus() | MSTATUS_MIE );
}

int plic_claim(void){
  int hart = r_tp();
  int irq = REG32( PLIC_MCLAIM(hart) );
  return irq;
}

void plic_complete(int irq){
  int hart = r_tp();
  REG32( PLIC_MCOMPLETE(hart) )= irq;
}