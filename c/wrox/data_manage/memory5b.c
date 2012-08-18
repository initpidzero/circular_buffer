/* --------------------------------------------------- */
/*  This program demonstrate bad use of memory         */
/* *************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(void)
{
   char z = *( const char *)0;
   printf("I read from location zero");
   exit(EXIT_SUCCESS);
}
