#ifndef __LIB_H__
#define __LIB_H__

#include <stdint.h>

#define REG8(reg) *((volatile uint8_t*) reg)
#define REG16(reg) *((volatile uint16_t*) reg)
#define REG32(reg) *((volatile uint32_t*) reg)
#define REG64(reg) *((volatile uint64_t*) reg)

#define UART_BA 0x10000000
#define THR (UART_BA + 0x0)
#define LSR (UART_BA + 0x5)
#define TE_MSK (1<<6)

extern void lib_puts(char* s);
extern void delay(volatile uint32_t i);

#endif
