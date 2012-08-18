/**************************************************************************/
/* how to use terminal capabilities****************************************/
/**************************************************************************/

#include <stdio.h>
#include <term.h>
//#include <ncurses.h>
#include <curses.h>
int main(void)
{
    
   setupterm("unlisted", fileno(stdout), (int *)0);
   printf("DONE\n") ;
   exit(0);
}
