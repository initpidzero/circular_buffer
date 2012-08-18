#include <signal.h>
#include <stdio.h>

void handler(int s)
{
   if (s == SIGBUS) printf("bus error\n");
   if (s == SIGSEGV) printf("segmentation fault\n");
   if (s == SIGILL) printf("illegal instruction\n");
   exit(1);
 
}

main ()
{
   int *p  = NULL;
   signal(SIGBUS, handler);
   signal(SIGSEGV, handler);
   signal(SIGILL, handler);
   *p = 0;
}
