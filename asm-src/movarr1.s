#mov array
.section .data
output:
.asciz "The value is %d\n"
values:
	.int 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60
.section .text
.globl _start
_start:
	nop
	movl values, %eax 
	movl $values, %edi 
	movl $100, 4(%edi)
	movl $1, %edi
	movl values( ,%edi, 4), %ebx
	mov $1, %eax
	int $0x80

