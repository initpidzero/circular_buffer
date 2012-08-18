/* Author offcourse it's me anuz, the great */
#ifndef __ANUZ__
#define __ANUZ__
#endif

/* this program does nothing useful */

#include "ourheader.h"
#define BUFFSIZE 8129

int main(void)
{
   int c;
    
   while( (c = getc(stdin)) != EOF)
       if(putc(c, stdout) == EOF)
           err_sys("ourput error");
   if(ferror(stdin))
           err_sys("input error");
    
   exit (0);
}
