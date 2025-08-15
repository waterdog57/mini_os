#include "riscv.h"
#include "os.h"

int lock_init( lock_t *lock){
    lock->locked = 0;
}

