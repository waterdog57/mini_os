#ifndef _RISCV_H_
#define _RISCV_H_

#include <stdint.h>

struct context {
	uint32_t ra;
	uint32_t sp;
	uint32_t s0;
	uint32_t s1;
	uint32_t s2;
	uint32_t s3;
	uint32_t s4;
	uint32_t s5;
	uint32_t s6;
	uint32_t s7;
	uint32_t s8;
	uint32_t s9;
	uint32_t s10;
	uint32_t s11;
};

#endif