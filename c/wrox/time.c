/**************************************************************************/
/******to see how time works***********************************************/
/**************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <time.h>

int main(void)
{
   time_t the_time;
   int i;
    
   for(i = 1; i <= 10; i++)  {
       the_time = time ((time_t *) 0);
       printf("The time is %ld\n", the_time);
       sleep(2);
   }
   exit(0);
}
