#ifndef __OS_H__
#define __OS_H__

#include <stdint.h>
#include "lib.h"
#include "riscv.h"
#include "sys.h"
#include "task.h"
#include "timer.h"

typedef struct lock
{
    volatile int locked;
}lock_t;

extern void plic_init(void);
extern int plic_claim(void);
extern void plic_complete(int irq);


#endif


