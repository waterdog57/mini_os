#include <stdint.h>

#define REG8(reg) *((uint8_t*) reg)

#define UART_BA 0x10000000
#define THR (UART_BA + 0x0)
#define LSR (UART_BA + 0x5)
#define TE_MSK (1<<6)

void mytask(void){
	lib_puts("mytask\n");
	while(1);
}

void __puts(char* s){
		while(( REG8(LSR) & TE_MSK) == 0 );
		REG8(THR) = *s;
	
}

void lib_puts(char* s){
	while( *s != '\0'){
		__puts(s++);
	}
}



int os_main(void){
		lib_puts("HelloOS\n");

		contextswitch();
		lib_puts("end os main\n");
		return 0;
}
