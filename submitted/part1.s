	.section .text
.LC0:
	.string "/bin/sh"		#The command to be executed
	.global _start
_start:
	movl	$0, %edx
	movl	$0, %esi
	movl	$.LC0, %edi
	movl    $59, %eax		#execve system call
	syscall
	movl	$0, %edi
	movl    $60, %eax		#exit(0) system call
	syscall


