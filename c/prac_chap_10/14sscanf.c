/* ********************************************************************** */
/* ***To use return value from sscanf******************************* */
/* ********************************************************************** */

#include <stdio.h>

int main(void)
{
   int scount,count,total;
   char line[100];
 
   fgets(line, sizeof(line), stdin);
   scount = sscanf(line, "%d %d", &count, &total);
   switch(scount){
       case 0:
       case EOF:
           printf("NO character found\n");
           break;
       case 1:
           printf("one character found count = %d\n",count);
           break;
       case 2:
           printf("both of them found count = %d , total = %d\n", count, total);
           break;
       default:
           printf("not a possible case\n");
 
   
   }
       
   return 0;
}
