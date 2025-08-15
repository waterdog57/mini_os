#include "task.h"

extern void sys_switch();

#define TASK_NUM   100
#define STACK_SIZE 100
uint8_t user_task_stack[TASK_NUM][STACK_SIZE];
struct context ctx_os;
struct context ctx[TASK_NUM];
struct context* ctx_now;
uint8_t task_top = 0;

uint8_t task_create(void (*task)(void)){
    uint8_t i = task_top++;
	ctx[i].ra = (uint32_t)task;
	ctx[i].sp = (uint32_t)&user_task_stack[i][STACK_SIZE-1];
    return i;
}

// switch to task
void task_go(uint8_t i){
    ctx_now = &ctx[i];
    sys_switch(&ctx_os, ctx_now);
}

// switch to os
void task_os(void){
    struct context *ctx = ctx_now;
    ctx_now = &ctx_os;
    sys_switch(&ctx, &ctx_os);
}