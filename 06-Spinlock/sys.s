
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

.macro reg_save base
	sw ra, 0(\base)
	sw sp, 4(\base)
	sw gp, 8(\base)
	sw tp, 12(\base)
	sw t0, 16(\base)
	sw t1, 20(\base)
	sw t2, 24(\base)
	sw s0, 28(\base)
	sw s1, 32(\base)
	sw a0, 36(\base)
	sw a1, 40(\base)
	sw a2, 44(\base)
	sw a3, 48(\base)
	sw a4, 52(\base)
	sw a5, 56(\base)
	sw a6, 60(\base)
	sw a7, 64(\base)
	sw s2, 68(\base)
	sw s3, 72(\base)
	sw s4, 76(\base)
	sw s5, 80(\base)
	sw s6, 84(\base)
	sw s7, 88(\base)
	sw s8, 92(\base)
	sw s9, 96(\base)
	sw s10, 100(\base)
	sw s11, 104(\base)
	sw t3, 108(\base)
	sw t4, 112(\base)
	sw t5, 116(\base)
	sw t6, 120(\base)
.endm

.macro reg_load base
	lw ra, 0(\base)
	lw sp, 4(\base)
	lw gp, 8(\base)
	#lw tp, 12(\base)
	lw t0, 16(\base)
	lw t1, 20(\base)
	lw t2, 24(\base)
	lw s0, 28(\base)
	lw s1, 32(\base)
	lw a0, 36(\base)
	lw a1, 40(\base)
	lw a2, 44(\base)
	lw a3, 48(\base)
	lw a4, 52(\base)
	lw a5, 56(\base)
	lw a6, 60(\base)
	lw a7, 64(\base)
	lw s2, 68(\base)
	lw s3, 72(\base)
	lw s4, 76(\base)
	lw s5, 80(\base)
	lw s6, 84(\base)
	lw s7, 88(\base)
	lw s8, 92(\base)
	lw s9, 96(\base)
	lw s10, 100(\base)
	lw s11, 104(\base)
	lw t3, 108(\base)
	lw t4, 112(\base)
	lw t5, 116(\base)
	lw t6, 120(\base)
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
.global trap_vector
.align 4
trap_vector:
	csrrw t6, mscratch, t6 #swap mscratch and t6
	reg_save t6
	csrw mscratch, t6
	csrr a0, mepc
	csrr a1, mcause
	call trap_handler
	# get timer handler return address a0
	csrw mepc, a0
	csrr t6, mscratch
    reg_load t6
	mret
