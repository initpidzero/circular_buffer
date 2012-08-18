/* ********************************************************************** */
/* ***** this program uses keypad and founds appropriate key ************ */
/* ********************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <curses.h>
#include <stdlib.h>

#define LOCAL_ESCAPE_KEY 27

int main(void)
{ 
   int key;

   initscr();
   crmode();
   keypad(stdscr, TRUE);/* swithch on the key buffering */
   noecho();/* switch off echoing */
   clear(); /* clear the screen */
   mvprintw(5, 5, "%s", "Key pad demo press 'q' to quit");
   refresh();
   key = getch();

   while(key != ERR && key != 'q')  {
       move(7, 5);
       clrtoeol(); /* deletes current line till end of line */
       if((key >= 'A' && key <= 'Z') || (key >= 'a' && key <= 'z'))
           printw("Key was %c", (char )key);
       else  
           switch(key)  {
               case LOCAL_ESCAPE_KEY: printw("%s", "escape key"); break;
               case KEY_END: printw("%s", "END KEY"); break;
               case KEY_BEG: printw("%s", "HOME key"); break;
               case KEY_RIGHT: printw("%s", "RIGHT key"); break;
               case KEY_LEFT: printw("%s", "LEFT key"); break;
               case KEY_UP: printw("%s", "UP key"); break;
               case KEY_DOWN: printw("%s", "DOWN key"); break;
               default: printw("UNMATCHED key %d", key); break; 
           }
           
       refresh(); 
       key = getch();
   }
  
   endwin();
     
   exit(EXIT_SUCCESS);
}
