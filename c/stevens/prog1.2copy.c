/* Author offcourse it's me anuz, the great */
#ifndef __ANUZ__
#define __ANUZ__
#endif

/* this program does nothing useful */

#include "ourheader.h"
#define BUFFSIZE 8129

int main(void)
{
   int n;
   char buf[BUFFSIZE];
  
   while((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0)
       if(write(STDOUT_FILENO, buf, n) != n)
           err_sys("write error");

   if(n < 0)
       err_sys("read error");
    
    exit (0);
}
