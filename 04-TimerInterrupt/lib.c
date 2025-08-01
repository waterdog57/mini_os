#include "lib.h"

void delay(volatile uint32_t i){
    i *= 5000;
    while(i--);
}

static void __puts(char* s){
		while(( REG8(LSR) & TE_MSK) == 0 );
		REG8(THR) = *s;
}

void lib_puts(char* s){
	while( *s != '\0'){
		__puts(s++);
	}
}