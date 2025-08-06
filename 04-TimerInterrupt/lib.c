#include "lib.h"

static char out_buf[1000]; // buffer for lib_vprintf()

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
	uint32_t pos = 0,i = 0;
	uint8_t format = 0;
	int32_t format_data = 0;
	uint8_t digitals = 0;
	for(;*s;s++){
		if(format){
			switch(*s){
				case 'd':
					format_data = va_arg(vl, int32_t);
					if(format_data > 0){
						digitals = 0;
						for(;format_data/(10*digitals);digitals++);
						for(;digitals--;){
							out_buf[i++]='0'+format_data%10;
							format_data /= 10;
						}
					}else{

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
	lib_puts(out_buf);
}

void myprintf(void* ptr,...){
	va_list va;
	va_start(va, ptr);
	_myprintf( ptr, va);
	va_end(va);
}