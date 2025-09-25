.set FLAGS, 1<<0|1<<1
.set MAGIC, 0x1BADB002
.set CHECKSUM, -(MAGIC + FLAGS)

.section .multiboot
.long MAGIC
.long FLAGS
.long CHECKSUM

.section .text
.global patate
.type patate, @function
patate:
	mov $patate_stack, %esp
	
	call patate_main

	_stop:
	cli
	hlt
	jmp _stop

.section bss
.space 2*1024*1024


