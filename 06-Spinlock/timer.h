#ifndef _TIME_H_
#define _TIME_H_
#include <stdint.h>
#include "lib.h"
#include "riscv.h"
#include "sys.h"



extern void timer_init(void);
extern void timer_handler(void);

#endif