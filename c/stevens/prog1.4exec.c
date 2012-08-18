/* Author offcourse it's me anuz, the great */
#ifndef __ANUZ__
#define __ANUZ__
#endif

/* this program does nothing useful */

#include "ourheader.h"

int main(void)
{
   int status;
   char buf[MAXLINE];
   pid_t pid;
   
   printf("%%"); /* this is our fukin  prompt */
   while(fgets(buf, MAXLINE, stdin) != NULL) {
       buf[strlen(buf) - 1] = 0;
       if( (pid = fork()) < 0)
           err_sys("fork error"); 
       
       else if (pid == 0) {
           execlp(buf, buf, (char *) 0);
           err_ret("couldn't execute: %s", buf);
           exit(127);
       }
   
       if((pid = waitpid(pid, &status, 0)) < 0)
           err_sys("waitpid error");
       printf("%%");
   }
   exit (0);
}
