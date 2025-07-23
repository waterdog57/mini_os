OUTPUT_ARCH( "riscv" )

ENTRY(_start)

MEMORY{
	ram (rwx) : ORIGIN = 0x80000000, LENGTH = 128M
}


PHDRS
{
  text PT_LOAD;
  data PT_LOAD;
  bss PT_LOAD;
}

SECTIONS{
	.text : ALIGN(4)
	{
		PROVIDE(_text_start = .);
		*(.text.init) *(.text .text.*)
		PROVIDE(_text_end = .);
	} >ram AT>ram :text

	.rodata : ALIGN(4)
	{
		PROVIDE(_rodatat=.);
		*(.rodata .rodata.*);
		PROVIDE(_rodata_end=.);
	}>ram AT>ram :text

	.data : ALGN(4)
	{
		PROVIDE(_data_start=.);
		*(.sdata .sdata.*) *(.data .data.*);
		PROVIDE(_data_end=.);
	}>ram AT>ram :data

	.bss : ALIGN(4)
	{
		PROVIDE(_bss_start=.);
		*(.sbss .sbss.*) *(.bss .bss.*);
		PROVIDE(_bss_end=.);
	}>ram AT>ram :data
	
	PROVIDE(_memory_start = ORIGIN(ram));
	PROVIDE(_memory_end = ORIGIN(ram)+LENGTH(ram));
}
