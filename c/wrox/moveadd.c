/* ********************************************************************** */
/* ******** Use the curses function draw a window and write on it ******* */
/* ********************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <curses.h>

int main(void)
{
   const char witch_one[] = "First Witch";
   const char witch_two[] = "Second Witch";
   const char *scan_ptr;

   initscr();

   move(5,15);
   attron(A_BOLD);
   printw("%s", "Macbeth");/* writes to the window */
   attroff(A_BOLD); /* this macro makes the character bold*/
   refresh();
   sleep(1);
   
   move(8, 15);
   attron(A_STANDOUT);  /* Best highlighting mode of the terminal */
   printw("%s", "Thunder and Lighting");
   attroff(A_STANDOUT);
   refresh();
   sleep(1);

   move(10, 10);
   printw("%s", "When shall we meet again");
   move(11, 23);
   printw("%s", "In the thunder lightining or in the rain");
   move(13, 10);
   printw("%s", "When the hurlyburly's done");
   move(14, 23);
   printw("%s", "When the battle is lost and won");
   refresh();
   sleep(1);
   
   attron(A_DIM); /* half Bright */
   scan_ptr = witch_one + strlen(witch_two) - 1;
   while(scan_ptr != witch_one)  {
       move(10, 10);
       insch(*scan_ptr--); /* moves character further */
   }
   scan_ptr = witch_two + strlen(witch_one) - 1;
   while(scan_ptr != witch_two)  {
       move(13, 10);
       insch(*scan_ptr--);
   }
  
  attroff(A_DIM);
  refresh();
  sleep(1);
        
  move(LINES - 1, COLS - 1);/* macros giving max no. of lines and col */
  refresh();
  sleep(1); 	
  
  endwin();
  
  exit(EXIT_SUCCESS);
}
