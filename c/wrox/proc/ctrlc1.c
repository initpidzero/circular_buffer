/**************************************************************************/
/* use to demonstarte the signal interface  ****/
/**************************************************************************/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void ouch(int sig)
{
   printf("Ouch!! i caught a signal %d", sig);
   (void)signal(SIGINT, SIG_DFL);
}
int main(void)
{
   (void) signal(SIGINT, ouch);
   
   while(1)
   { 
       printf("hello world\n");
       sleep(1);
   }    
   exit(0);
}
