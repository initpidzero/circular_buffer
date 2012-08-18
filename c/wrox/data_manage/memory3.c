/* --------------------------------------------------- */
/*  This program utilises full memory of the system   */
/* ************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define ONE_K (1024)

int main(void)
{
   char *some_memory;
   size_t size_to_allocate = ONE_K;
   int mega_obtained = 0;
   int ks_obtained;
   
   while(1)  {
       for(ks_obtained = 0; ks_obtained < 1024; ks_obtained++)  {
           some_memory = (char *)malloc(size_to_allocate);
           if(some_memory != NULL)  exit(EXIT_FAILURE);
           sprintf(some_memory, "Hello world\n");
       }   
       mega_obtained++;
       printf("now allocated %d Megabytes\n", mega_obtained);
   }
   exit(EXIT_SUCCESS);
}
