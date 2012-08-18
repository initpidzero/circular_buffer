/**************************************************************************/
/* how to use terminal capabilities****************************************/
/**************************************************************************/

#include <stdio.h>
#include <term.h>
#include <ncurses.h>

int main(void)
{
   int nrows, ncols; 
   setupterm(NULL, fileno(stdout), (int *)0);
   nrows = tigetnum("lines");
   ncols = tigetnum("cols");
   printf("This terminal has %d columns and %d rows\n", ncols, nrows);
   exit(0);
}
