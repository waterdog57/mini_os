#include <stdint.h>
#include "lib.h"
#include "riscv.h"
#include "sys.h"
#include "task.h"
#include "timer.h"

extern uint8_t task_top;

void mytask1(void){
	lib_puts("mytask1\n");
	while(1){
		lib_puts("mytask1 is running...\n");
		delay(10);
		task_os();
	}
}
void mytask2(void){
	lib_puts("mytask2\n");
	while(1){
		lib_puts("mytask2 is running...\n");
		delay(10);
		task_os();
	}
}

int os_main(void){
	uint8_t current_task = 0;
	lib_puts("HelloOS\n");
	myprintf("myprintf test\n");
	// task_create( &mytask1 );
	// task_create( &mytask2 );
	// while(1){
	// 	task_go( current_task );
	// 	lib_puts("Back to OS..\n");
	// 	delay(10);
	// 	current_task = ( current_task + 1 ) % task_top;
	// }
	timer_init();
	while(1){

	}
	
	lib_puts("end os main\n");
	return 0;
}
