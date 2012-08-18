#include <stdio.h>

#define fn(v,t) (v<<8|t)

int main (void)
{
   unsigned short  c, d, e;
   char lone[20];

   fgets(lone, sizeof lone, stdin);
   sscanf(lone, "%h %h", &c ,&d);

   e = fn(c,d);
   printf("%h\n", e);
   
   return 0;
}
