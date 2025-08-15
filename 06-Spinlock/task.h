#ifndef _TASK_H_
#define _TASK_H_
#include <stdint.h>
#include "lib.h"
#include "riscv.h"

extern uint8_t task_create(void (*task)(void));
extern void task_go(uint8_t i);
extern void task_os(void);
#endif