
.macro context_save save_addr
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

.macro context_load load_addr
	lw ra, 0(\load_addr)
	lw sp, 4(\load_addr)
	lw s0, 8(\load_addr)
	lw s1, 12(\load_addr)
    lw s2, 16(\load_addr)
    lw s3, 20(\load_addr)
    lw s4, 24(\load_addr)
    lw s5, 28(\load_addr)
    lw s6, 32(\load_addr)
    lw s7, 36(\load_addr)
    lw s8, 40(\load_addr)
    lw s9, 44(\load_addr)
    lw s10,48(\load_addr)
    lw s11,52(\load_addr)
.endm

.global sys_switch
.align 4
sys_switch:
	context_save a0
	context_load a1
	ret

.global sys_timer
.align 4
sys_timer:
	csrr a0, mepc
	csrr a1, mcause
	call timer_handler
	# get timer handler return address a0
	csrw mepc, a0
	mret

