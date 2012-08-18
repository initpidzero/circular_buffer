/**************************************************************************/
/* **** this will demonstrate the use of exec family functions         ** */
/**************************************************************************/

#include <stdio.h>
#include <unistd.h>

int main(void)
{
   char **environ;
   printf("Running ps with execle\n");
   execle("/bin/ps", "ps", "-ax", 0, environ);
   printf("Done\n");
     
   exit(0);
}
