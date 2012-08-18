/**************************************************************************/
/* dummy program to convert code from lower to upper letters           ****/
/**************************************************************************/

#include <stdio.h>
#include <ctype.h>

int main(void)
{
   int ch;
   while((ch = getchar()) != EOF) 
       putchar(toupper(ch));
 
   exit(0);
}
