/* --------------------------------------------------- */
/*  This program demonstrate bad use of memory         */
/* *************************************************** */

#include <stdlib.h>

#define ONE_K (1024)

int main(void)
{
   char *some_memory, *scan_ptr;
   
   some_memory = (char *)malloc(ONE_K);
   if(some_memory == NULL) exit(EXIT_FAILURE); 
   
   scan_ptr = some_memory;
   while(1)  {
       *scan_ptr = '\0';
       scan_ptr++;
   }
   exit(EXIT_SUCCESS);
}
