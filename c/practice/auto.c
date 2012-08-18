#include <stdio.h>
char *func(void);
int main (void)
{
 char *i;
 i  = func();
 printf("%s", i);
 return 0;
}

char *func(void)
{
   char *prod;
   prod = "coun" ;
   return prod;
}
