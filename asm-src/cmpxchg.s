.section .data
data:
	.int 11
.section .text
.globl _start
_start:
	nop
	movl $10, %eax
	movl $5, %ebx
	cmpxchg %ebx, data
	movl $1, %eax
	int $0x80
