#include "task.h"

#define TASK_NUM   100
#define STACK_SIZE 100
uint8_t user_task_stack[TASK_NUM][STACK_SIZE];

void task_create(void){
    

	lib_puts("HelloOS\n");
	user_task.ra = (uint32_t)mytask;
	user_task.sp = (uint32_t)&user_task_stack[STACK_SIZE-1];

}

void task_go(uint8_t i){

}