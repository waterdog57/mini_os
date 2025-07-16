#include <stdint.h>

#define REG8(reg) (uint8_t* reg)

#define UART_BA 0x10000000
#define THR (UART_BA + 0x0)
#define LSR (UART_BA + 0x5)
#define TE_MSK (1<<6)

void __puts(char* s){
		while(REG8(LSR) & TE_MSK ){
			REG8(THR) = *s;
			
		}
}

void lib_puts(char* s){
	while(  )
}

int main(void){
		lib_puts("HelloOS\n");
		return 0;
}
