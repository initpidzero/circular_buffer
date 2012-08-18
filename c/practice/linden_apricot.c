#include <stdio.h>

int main(void)
{

   int apricot[2][3][5];
   int (*r)[5] = apricot[0];
   int *t = apricot[0][0];
  
   printf("%p %p %p\n", apricot, r, t);
   printf("%p %p %p\n", apricot + 1, r +1, t + 1);

}
