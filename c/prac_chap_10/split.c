/* ********************************************************************** */
/*   **** This program will split the string to find the character ****   */
/* ********************************************************************** */

#include <stdio.h>

char line[80];

char *my_strchr(char *str, char find)
{
   while(*str != find)
   {
       if(*str == '\0')
           return(NULL);
       ++str;   
   }
   return str;
}

int main(void)
{
   char *first, *last;
 
   printf("enter the last/first name\n");
   fgets(line, sizeof(line), stdin);
   line[strlen(line) - 1] = '\0';
  
   last = line;
   first = my_strchr(line, '/');

   if(first == NULL)  {
       fprintf(stderr, "error\n");
       exit(1);
   }
   
   *first = '\0';
   ++first;
   printf("FIRST %s: LAST %s\n", first, last);           
     
   return 0;
}
