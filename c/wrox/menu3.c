/**************************************************************************/
/* This is a menu based utility using terminals****************************/
/**************************************************************************/

#include <stdio.h>
#include <unistd.h>

char *menu[] = {
   "a - add new record",
   "d - delete record",
   "q - quit",
   NULL,
};   

int getchoice(char *greet, char *choices[], FILE *in, FILE *out);

int main(void)
{
   int choice = 0;
   FILE *input;
   FILE *output;
   
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
   do  {
       choice = getchoice("Please select an action\n", menu, input, output);
       printf("you have chosen %c\n", choice);
   } while(choice != 'q');  
    
   exit(0);
}

int getchoice(char *greet, char *choices[], FILE *in, FILE *out)
{
   int chosen  = 0;
   int selected;
   char **option;
 
   do  {
       fprintf(out, "choice: %s\n", greet);
       option = choices;
       /* this do while loop is printing the menu*/
       while(*option)  {
           fprintf(out, "%s\n", *option);
           option++;
       }
       do  {
            selected = getchar();
       }while(selected == '\n');
       option = choices;/*option is reset*/
       while(*option)  {
           if(selected == *option[0])  {
               printf("DEBUGGING %s\n", *option);
               chosen = 1;
               break;
           }
           option++;
       }
       if(!chosen)
           fprintf(out, "incorrect choice select again\n");
   } while(!chosen);
   return selected;
}
