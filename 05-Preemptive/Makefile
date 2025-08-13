CC :=riscv64-unknown-elf-gcc
CFLAGS = -nostdlib -fno-builtin -mcmodel=medany -march=rv32ima_zicsr -mabi=ilp32 -g -Og

QEMU = qemu-system-riscv32
QFLAGS = -nographic -smp 4 -machine virt -bios none

OBJDUMP =riscv64-unknown-elf-objdump

OBJ = start.s sys.s lib.c riscv.c task.c timer.c trap.c os.c

all:os.elf

os.elf: $(OBJ)
	$(CC) $(CFLAGS) -T os.ld -o os.elf $^

clean:
	rm -f *.elf

qemu: $(TARGET)
	@qemu-system-riscv32 -M ? | grep virt > /dev/null || exit
	@echo "Press Ctrl-A and then X to exit QEMU"
	$(QEMU) $(QFLAGS) -kernel os.elf
