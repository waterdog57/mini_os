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
		PROVIDE(_text_start=.)
		*(.text.init)
		*(.text .text.*)
		PROVIDE(_text_end=.)
	}





}
