CC :=riscv64-unknown-elf-gcc
CFLAGS = -nostdlib -fno-builtin -mcmodel=medany -march=rv32ima -mabi=ilp32

QEMU = qemu-system-riscv32
QFLAGS = -nographic -smp 4 -machine virt -bios none

OBJDUMP =riscv64-unknown-elf-objdump

all:os.elf

os.elf:start.s os.c
	$(CC) $(CFLAGS) -T os.ld -o os.elf $^



clean:
	rm -f *.elf
