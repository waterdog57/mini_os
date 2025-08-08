#include "riscv.h"



uint32_t r_mhartid(void){
    reg_t x;
    asm volatile( "csrr %0, mhartid" : "=r" (x) );
    return x;
}

reg_t r_mstatus(void){
    reg_t x;
    asm volatile( "csrr %0, mstatus" : "=r" (x) );
    return x;
}

void w_mstatus(reg_t x){
    asm volatile("csrw mstatus, %0" : : "r" (x));
}

reg_t r_mepc(void){
    reg_t x;
    asm volatile( "csrr %0, mepc" : "=r" (x) );
    return x;
}

void w_mepc(reg_t x){
    asm volatile("csrw mepc, %0" : : "r" (x));
}

void w_mtvec(reg_t x){
    asm volatile("csrw mtvec, %0" : : "r" (x));
}

void w_mie(reg_t x){
    asm volatile("csrw mie, %0" : : "r" (x));
}

reg_t r_mie(void){
    reg_t x;
    asm volatile( "csrr %0, mie" : "=r" (x) );
    return x;
}

