#include "lib.h"

static char out_buf[1000]; // buffer for lib_vprintf()

void uart_init(void){
	/* disable interrupts */
    REG8(IER) = 0;

    /* Baud rate setting */
    uint8_t lcr = REG8(LCR);
    REG8( LCR ) = lcr | (1 << 7);
	REG8(DLL) = 0x3;
	REG8(DLM) = 0;

    lcr = 0;
    REG8( LCR ) = lcr | (3 << 0);

    uint8_t ier = REG8(IER);
    REG8( IER ) = ier | (1 << 0);
}

void lib_isr(void){
	myprintf("uart isr.\n");
}

void delay(volatile uint32_t i){
    i *= 5000;
    while(i--);
}


static void __puts(char* s){
		while(( REG8(LSR) & TE_MSK) == 0 );
		REG8(THR) = *s;
}

void lib_puts(char* s){
	while( *s ){
		__puts(s++);
	}
}
void _myprintf( const uint8_t* s, va_list vl ){
	int8_t i = 0;
	uint32_t pos = 0;
	uint8_t format = 0;
	uint8_t digitals = 0;
	for(;*s;s++){
		if(format){
			switch(*s){
				case 'd':
					int32_t format_data = va_arg(vl, int32_t);
					int32_t temp;
					digitals = 0;
					if(format_data >= 0){
						temp = format_data;
					}else{
						temp = -format_data;
						format_data = -format_data;
						out_buf[pos++]='-';
					}
					do{
						temp /= 10;
						digitals++;
					}while(temp);
					for(i=digitals-1;i>=0;i--){
						out_buf[pos+i]='0'+format_data%10;
						format_data /= 10;
					}
					pos += (digitals);	
					break;
				case 's':
					const char* str = va_arg(vl,const char*);
					while(*str){
						out_buf[pos++]= *str++;
					}
					break;
				case 'x':

					break;
			}
			format = 0;
		}else{
			switch(*s){
				case '%':
					format = 1;
					break;
				default:
					out_buf[pos++] = *s;
				break;
			}
		}
	}
	out_buf[pos++] = '\0';
	lib_puts(out_buf);
}

void myprintf(void* ptr,...){
	va_list va;
	va_start(va, ptr);
	_myprintf( ptr, va);
	va_end(va);
}