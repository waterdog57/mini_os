#include "os.h"

extern uint8_t task_top;
extern void trap_init(void);

void mytask1(void){
	lib_puts("mytask1\n");
	while(1){
		lib_puts("mytask1 is running...\n");
		delay(1000);
	}
}
void mytask2(void){
	lib_puts("mytask2\n");
	while(1){
		lib_puts("mytask2 is running...\n");
		delay(1000);
	}
}

int os_main(void){
	uint8_t current_task = 0;
	int32_t k = 0;
	lib_puts("HelloOS\n");
	myprintf("%d %d %d %d %d %d %d %s\n",0,1,12,123,1234,-1 ,-12, "water dog.");
	task_create( &mytask1 );
	task_create( &mytask2 );

	timer_init();
	trap_init();

	while(1){
		task_go( current_task );
		current_task = ( current_task + 1 ) % task_top;
		lib_puts("Back to OS..\n");
		delay(10);
	}
	
	lib_puts("end os main\n");
	return 0;
}
