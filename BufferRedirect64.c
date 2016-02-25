#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <malloc.h>
#include <sys/mman.h>
#include <string.h>
#include <errno.h>

long long  *hold;
char shellcode[] ="\x90\x90";

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



	    
	    
	    
	    
	    
	    
	    
	    
	    
	    
	    
	    
	    
	    
	    
	    
	    
	    
	    
	    
