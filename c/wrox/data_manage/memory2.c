/* --------------------------------------------------- */
/*  This program utilises full memory of the system   */
/* ************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define A_MEGABYTE (1024 * 1024)
#define PHY_MEM_MEGS 256 /* this number is physical memory */

int main(void)
{
   char *some_memory;
   size_t size_to_allocate = A_MEGABYTE;
   int mega_obtained = 0;
   
   while(mega_obtained < (PHY_MEM_MEGS * 2))  {
       some_memory = (char *)malloc(size_to_allocate);
       if(some_memory != NULL)  {
           mega_obtained++;
           sprintf(some_memory, "Hello world\n");
           printf("%s - now allocated %d Megabytes\n", 
                   some_memory, mega_obtained);
       }
       else
           exit(EXIT_FAILURE);
   }
   exit(EXIT_SUCCESS);
}
