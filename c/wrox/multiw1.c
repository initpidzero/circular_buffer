/* ********************************************************************** */
/* *******    Opening Multiple window and managing them   *************** */
/* ********************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <curses.h>

int main(void)
{
   WINDOW *new_window_ptr;
   WINDOW *popup_window_ptr;
   int x_loop, y_loop;
   char a_letter = 'a';
   
   initscr();
   move(5, 5);
   printw("%s", "Testing multiple windows");
   refresh();
   
   for(y_loop = 0; y_loop < LINES - 1; y_loop++)  
       for(x_loop = 0; x_loop < COLS - 1; x_loop++) { 
           /* move ch and put ch at given postition */
           mvwaddch(stdscr, y_loop, x_loop, a_letter);
           a_letter++;
           if(a_letter > 'z') a_letter = 'a';
       }
   /* update the screen */
   refresh();
   sleep(2);

   new_window_ptr = newwin(10, 20, 5, 5); /* creates a new window */
   /* this functin moves and prints to the window */
   mvwprintw(new_window_ptr, 2, 2, "%s", "Hello World");
   mvwprintw(new_window_ptr, 2, 2, "%s", 
             "See how the text is wraped inside a window");
   wrefresh(new_window_ptr);
   sleep(2);

   a_letter = '0';
   for(y_loop = 0; y_loop < LINES - 1; y_loop++)  
       for(x_loop = 0; x_loop < COLS - 1; x_loop++) { 
           mvwaddch(stdscr, y_loop, x_loop, a_letter);
           a_letter++;
           if(a_letter > '9') a_letter = '0';
       }
   refresh();
   sleep(2); 
   
   wrefresh(new_window_ptr);
   sleep(2);

   touchwin(new_window_ptr);/* this is neccessary in case of more windows */
   wrefresh(new_window_ptr);
   sleep(2);

   popup_window_ptr = newwin(10, 20, 8, 8);
   box(popup_window_ptr, '|', '-');
   mvprintw(popup_window_ptr, 5, 2, "%s", "Pop Up Window!");
   wrefresh(popup_window_ptr);
   sleep(2);

   touchwin(new_window_ptr);
   wrefresh(new_window_ptr);
   sleep(2);
   wclear(new_window_ptr); /* copies blank to evey screen */
   wrefresh(new_window_ptr);
   sleep(2);
   delwin(new_window_ptr);
   touchwin(popup_window_ptr);
   wrefresh(popup_window_ptr);
   sleep(2);
   delwin(popup_window_ptr);
   touchwin(stdscr);
   refresh();
   sleep(2);
   endwin();
   
   exit(EXIT_SUCCESS);
}
