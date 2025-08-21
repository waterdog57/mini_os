#ifndef __LIB_H__
#define __LIB_H__

#include <stdint.h>
#include <stdarg.h>

#define REG8(reg) *((volatile uint8_t*) reg)
#define REG16(reg) *((volatile uint16_t*) reg)
#define REG32(reg) *((volatile uint32_t*) reg)
#define REG64(reg) *((volatile uint64_t*) reg)

#define UART_BA  ( 0x10000000 )
#define THR (UART_BA + 0x0)
#define RHR (UART_BA + 0x0)
#define DLL (UART_BA + 0x0)
#define DLM (UART_BA + 0x1)
#define IER (UART_BA + 0x1)
#define ISR (UART_BA + 0x2) //r
#define FCR (UART_BA + 0x2) //w
#define LCR (UART_BA + 0x3) //r/w
#define LSR (UART_BA + 0x5) //r

#define TE_MSK (1<<6)

extern void uart_init(void);
extern void lib_isr(void);
extern void lib_puts(char* s);
extern void delay(volatile uint32_t i);
extern void myprintf(void* ptr,...);

#endif
