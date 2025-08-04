#ifndef _SYS_H_
#define _SYS_H_

extern void sys_switch(struct context* ctx_old, struct context* ctx_new);
extern void sys_timer(reg_t mmepc, reg_t mmcause);

#endif
