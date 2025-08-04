#ifndef _RISCV_H_
#define _RISCV_H_

#include <stdint.h>
#include "lib.h"

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

typedef uint32_t reg_t;


#define CLINT_BASE     0x02000000
#define CLINT_MTIMECMP(hartid) (CLINT_BASE + 0x4000 + 8 * (hartid))
#define CLINT_MTIME    (CLINT_BASE + 0xBFF8)

#define MIE_MEIE (1 << 11) // external
#define MIE_MTIE (1 << 7)  // timer
#define MIE_MSIE (1 << 3)  // software


uint8_t r_mhartid(void);
void w_mie(reg_t x);
reg_t r_mie(void);

#endif