/******************************************************************
**********this program changes celceius to farenheit****************
*******************************************************************/

#include <stdio.h>

int main(void)
{  
   int celsius;
   for(celsius = 0; celsius <= 100; ++celsius)
   printf("%d  %d\n", celsius, (celsius * 9) / 5 + 32);
   return 0;
}


