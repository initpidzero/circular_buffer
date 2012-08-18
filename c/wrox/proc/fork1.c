/* ********************************************************************** */
/*        ***** this will demonstrate the use of fork() call *****        */
/* ********************************************************************** */

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
   pid_t pid;
   char *message;
   int n;
   
   printf("fork program starting\n");
   pid = fork();
   
   switch(pid)  {
       case -1:
            perror("fork failed\n");
            exit(1);
       case 0:
           message = "This is the child" ;
           n = 5;
           break;
       default :
           message = "This is the parent";
           n = 3;
   }
   
   for(; n > 0; n--)  {
       puts(message);
       sleep(1);
   }
   
   exit(0);
}