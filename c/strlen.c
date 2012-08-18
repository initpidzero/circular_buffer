/************************************************************************
***** calculate sting length using functions*****************************
************************************************************************/

#include <stdio.h>

int length(char *);
char line[80];

int main(void)
{
   printf("type the string to get its length\n");
   fgets(line, sizeof(line), stdin);
   
   printf("%d\n",length(line));
   return 0;
} 

int length (char *line)
{
   int i;
   for(i = 0; line[i] != '\0'; ++i) 
       continue;  
   return(i);
}
