#include <stdint.h>
#include "lib.h"
#include "riscv.h"
#include "sys.h"



int os_main(void){
	struct context os_task, user_task1, user_task2;

	lib_puts("HelloOS\n");
	

	sys_switch(&os_task, &user_task);
	lib_puts("end os main\n");
	return 0;
}
