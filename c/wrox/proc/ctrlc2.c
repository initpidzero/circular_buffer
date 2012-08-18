/**************************************************************************/
/* use to demonstarte the sigaction interface  ****/
/**************************************************************************/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void ouch(int sig)
{
   printf("Ouch!! i caught a signal %d", sig);
   
}
int main(void)
{
   struct sigaction act;
   
   act.sa_handler = ouch;
   sigemptyset(&act.sa_mask);
   act.sa_flags = 0;
   
   sigaction(SIGINT, &act, 0); 
   
   while(1)
   { 
       printf("hello world\n");
       sleep(1);
   }    
   exit(0);
}
