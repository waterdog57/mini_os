CC :=riscv64-unknown-elf-gcc
CFLAGS = -nostdlib -fno-builtin -mcmodel=medany -march=rv32ima_zicsr -mabi=ilp32 -g -Og

QEMU = qemu-system-riscv32
QFLAGS = -nographic -smp 4 -machine virt -bios none

OBJDUMP =riscv64-unknown-elf-objdump

all:os.elf

os.elf: start.s sys.s lib.c task.c os.c
	$(CC) $(CFLAGS) -T os.ld -o os.elf $^

clean:
	rm -f *.elf

qemu: $(TARGET)
	@qemu-system-riscv32 -M ? | grep virt > /dev/null || exit
	@echo "Press Ctrl-A and then X to exit QEMU"
	$(QEMU) $(QFLAGS) -kernel os.elf -s -S
