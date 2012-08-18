/**************************************************************************/
/*use curses library*******************************************************/
/**************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <string.h>

#define PW_LEN 24
#define NAME_LEN 256

int main(void)
{  
   char name[NAME_LEN];
   char password[PW_LEN];
   char *real_password = "pschye";
   int i = 0;

   initscr();
  
   move(5, 10);
   printw("%s", "Please Login");
   move(7, 10);
   printw("%s", "User Name");
   getstr(name); /* no of calls to getch + '\n' */
   
   move(9, 10);
   printw("%s", "PASSWORD");
   refresh();
   
   cbreak(); /* disables "cook mode" character buffering is disable and
                special character processing is off */  
   noecho();
   
   memset(password, '\0', sizeof(password)); /* set the password with '\0' */
   while(i < PW_LEN)  {
       password[i] = getch();
       move(9, 20+i);
       addch('*'); /* puts ch at the position in window */
       refresh();
       if(password[i] == '\n') break;
       if(strcmp(password, real_password) == 0) break;  
       i++;
   }
   echo();
   nocbreak();
   
   move(11, 10);
   if(strcmp(password, real_password) == 0) printw("%s", "Correct");
   else printw("%s", "Incorrect");
   refresh();

   endwin();
   exit(EXIT_SUCCESS);
}
