/* --------------------------------------------------- */
/*  This program demonstrate bad use of memory         */
/* *************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(void)
{
   char *some_memory = (char *)0;
   printf("A read from null %s\n", some_memory);
   sprintf(some_memory, "A write to null");
   exit(EXIT_SUCCESS);
}
