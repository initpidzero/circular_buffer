/* ________________________________________________
 this is an example main program
_________________________________________________ */

#include <stdlib.h>
#include "a.h"

extern void function_two();
extern void function_three();

int main(void)
{
   function_two();
   function_three();
   exit(EXIT_SUCCESS);
}
