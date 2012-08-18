#include <stdio.h>

int main (void)
{
   #ifdef DEBUG
       printf("COMPILED: "__DATE__ " at " __TIME__ "\n");
       printf("This is line %d of file %s\n", __LINE__, __FILE__);
   #endif
   
   printf("hello world\n");
   exit(0);
}
     
