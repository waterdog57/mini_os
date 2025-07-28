
.marco context_save save_addr
	sw ra, 0(\save_addr)
	sw sp, 4(\save_addr)
	sw s0, 8(\save_addr)
	sw s1, 12(\save_addr)
	sw s2, 16(\save_addr)
	sw s3, 20(\save_addr)
	sw s4, 24(\save_addr)
	sw s5, 28(\save_addr)
	sw s6, 32(\save_addr)
	sw s7, 36(\save_addr)
	sw s8, 40(\save_addr)
	sw s9, 44(\save_addr)
	sw s10, 48(\save_addr)
	sw s11, 52(\save_addr)
.endm

.marco context_load

.endm

.global sys_switch
.align 4
sys_switch
	context_save a0
	context_load a1
	ret
