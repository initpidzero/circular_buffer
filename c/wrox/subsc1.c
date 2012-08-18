/* ********************************************************************** */
/* *******    Opening  Sub windows and managing them      *************** */
/* ********************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <curses.h>

int main(void)
{
   WINDOW *sub_window_ptr;
  int x_loop, y_loop, counter;
   char a_letter = '1';
   
   initscr();
    
   for(x_loop = 0; x_loop < COLS - 1; x_loop++)  { 
       for(y_loop = 0; y_loop < LINES - 1; y_loop++) { 
           /* move ch and put ch at given postition */
           mvwaddch(stdscr, y_loop, x_loop, a_letter);
           a_letter++;
           if(a_letter > '9') a_letter = '1';
       }
       if(a_letter > 'Z') a_letter = 'A';
   }
   

   sub_window_ptr = subwin(stdscr, 10, 20, 10, 10); /* creates a sub window */
   /* this functin scrolls if line goes out of windows */
   scrollok(sub_window_ptr, 1);

   touchwin(stdscr);/* this is neccessary in case of more windows */
   refresh();
   sleep(1);

   werase(sub_window_ptr);/* copies blank to window */
   mvprintw(sub_window_ptr, 2, 6, "%s", "This window will now scroll");
   wrefresh(sub_window_ptr);
   sleep(1);

   for(counter = 1; counter < 10; counter++)  {
       wprintw(sub_window_ptr, "%s", " This is a test for both wrapping and \
                                scrolling");
       wrefresh(sub_window_ptr);
       sleep(1);
   }
   
   delwin(sub_window_ptr);
   
   touchwin(stdscr);
   refresh();
   sleep(1);

   endwin();
   
   exit(EXIT_SUCCESS);
}
