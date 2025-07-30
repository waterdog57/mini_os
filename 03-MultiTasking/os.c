#include <stdint.h>
#include "riscv.h"
#include "sys.h"

#define REG8(reg) *((uint8_t*) reg)

#define UART_BA 0x10000000
#define THR (UART_BA + 0x0)
#define LSR (UART_BA + 0x5)
#define TE_MSK (1<<6)

#define STACK_SIZE 100

extern void sys_switch();


void __puts(char* s){
		while(( REG8(LSR) & TE_MSK) == 0 );
		REG8(THR) = *s;
	
}

void lib_puts(char* s){
	while( *s != '\0'){
		__puts(s++);
	}
}

void mytask(void){
	lib_puts("mytask!!!\n");
	while(1);
}


int os_main(void){
	struct context os_task, user_task;
	uint8_t user_task_stack[STACK_SIZE];

	lib_puts("HelloOS\n");
	user_task.ra = (uint32_t)mytask;
	user_task.sp = (uint32_t)&user_task_stack[STACK_SIZE-1];

	sys_switch(&os_task, &user_task);
	lib_puts("end os main\n");
	return 0;
}
