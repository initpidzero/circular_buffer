/**************************************************************************/
/********** A low level system call system is demonstrated here ***********/
/**************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
   printf("Running ps with system\n");
   system("ps -ax &");
   printf("Done\n");
  
   exit(0);
}
