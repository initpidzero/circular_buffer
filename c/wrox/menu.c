/**************************************************************************/
/* This is a simle menu based utility**************************************/
/**************************************************************************/

#include <stdio.h>

char *menu[] = {
   "a - add new record",
   "d - delete record",
   "q - quit",
   NULL,
};   

int getchoice(char *greet, char *choices[]);

int main(void)
{
   int choice = 0;
   do  {
       choice = getchoice("Please select an action\n", menu);
       printf("you have chosen %c\n", choice);
   } while(choice != 'q');  
    
   exit(0);
}

int getchoice(char *greet, char *choices[])
{
   int chosen  = 0;
   int selected;
   char **option;
 
   do  {
       printf("choice: %s\n", greet);
       option = choices;
       /* this do while loop is printing the menu*/
       while(*option)  {
           printf("%s\n", *option);
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
           printf("incorrect choice select again\n");
   } while(!chosen);
   return selected;
}
