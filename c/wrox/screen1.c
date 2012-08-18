/**************************************************************************/
/*use curses library*******************************************************/
/**************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <curses.h>

int main(void)
{
   initscr();
   move(5,15);
   printw("%s", "hello world");
   refresh();
   sleep(2);
   endwin();
  
   exit(EXIT_SUCCESS);
}
