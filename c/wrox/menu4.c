/**************************************************************************/
/* This is a menu based utility using terminals****************************/
/**************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include <term.h>
#include <curses.h>

static FILE *output_stream = (FILE *)0;
char *menu[] = {
   "a - add new record",
   "d - delete record",
   "q - quit",
   NULL,
};   

int getchoice(char *greet, char *choices[], FILE *in, FILE *out);
int char_to_terminal(int char_to_write);

int main(void)
{
   int choice = 0;
   FILE *input;
   FILE *output;
   struct termios initial_settings, new_settings;
   
   if(!isatty(fileno(stdout)))  {
   /* see how isatty and fileno functions are used*/
       fprintf(stderr, "you are not terminal:\n");
       exit(1);
   }
   
   input = fopen("/dev/tty", "r");
   output = fopen("/dev/tty", "w");
   /*checking the availability of terminal*/
   if(!input || !output)  {
       fprintf(stderr, "Unable to open /dev/tty\n");
       exit(1);
   }
   
   tcgetattr(fileno(input), &initial_settings);
   new_settings = initial_settings;
   new_settings.c_lflag &= ~ICANON;
   new_settings.c_lflag &= ~ECHO;
   new_settings.c_cc[VMIN] = 1;
   new_settings.c_cc[VTIME] = 0;
   new_settings.c_lflag &= ~ISIG;
   
  if(tcsetattr(fileno(input), TCSANOW, &new_settings) != 0)  
       fprintf(stderr, "could not set attributes\n");
    
   do  {
       choice = getchoice("Please select an action\n", menu, input, output);
       printf("you have chosen %c\n", choice);
       sleep(1);
   } while(choice != 'q');  
   
   tcsetattr(fileno(input), TCSANOW, &initial_settings);
    
   exit(0);
}

int getchoice(char *greet, char *choices[], FILE *in, FILE *out)
{
   int chosen  = 0;
   int selected;
   char **option;
   int screenrow, screencol = 10;
   char *cursor, *clear;

   output_stream = out;

   setupterm(NULL, fileno(out), (int *)0);/*set up current terminal to out*/
   cursor = tigetstr("cup");/*get the cup string*/
   clear = tigetstr("clear");
   
   screenrow = 4;
   tputs(clear, 1, (int *)char_to_terminal);
   /* how is tparm's output used*/
   tputs(tparm(cursor, screenrow, screencol), 1, char_to_terminal);
   fprintf(out, "choices: %s", greet);
   screenrow += 2;
   option = choices;
         
   while(*option)  {
       tputs(tparm(cursor, screenrow, screencol), 1, char_to_terminal);
       fprintf(out, "%s\n", *option);
       screenrow++;
       option++;
   }
   do  {
       fflush(out);
       selected = fgetc(in);
       option = choices;/*option is reset*/
       while(*option)  {
           if(selected == *option[0])  {
               printf("DEBUGGING %s\n", *option);
               chosen = 1;
               break;
           }
           option++;
       }
       if(!chosen) {
           tputs(tparm(cursor, screenrow, screencol), 1, char_to_terminal);
           fprintf(out, "incorrect choice select again\n");
       }
   } while(!chosen);
   
   tputs(clear, 1, char_to_terminal);
   return selected;
}

int char_to_terminal(int char_to_write)
{
   if(output_stream) putc(char_to_write, output_stream);
   return 0;
}
