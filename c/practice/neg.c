#include <stdio.h>
#include <limits.h>

int main(void)
{
   int v  = -1;
   int sign;
   sign = +1 | (v >> (sizeof(char) * CHAR_BIT - 1));
   printf("%d\n", sign);
   return 0;
}
