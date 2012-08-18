#include "ourheader.h"

int main (void)
{
   if(lseek(STDIN_FILENO, 0, SEEK_CUR) == -1)
       printf("error\n");
   else 
       printf("OK");
 
  return 0;
}
