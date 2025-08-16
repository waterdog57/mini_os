#include "riscv.h"
#include "os.h"

extern int atomic_swap( lock_t *lock );

int lock_init( lock_t *lock){
    lock->locked = 0;
}

void lock_acquire(lock_t *lock){
    while(atomic_swap(lock)){
        ;
    }
}

void lock_free(lock_t *lock){
    lock->locked = 0;
}