/* ---------------------------------------------------------------------- */
/*  This program demonstrate how to lock the file for the use by the lock */
/* ********************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

int main(void)
{
   int file_desc;
   int save_error;
   
   file_desc = open("/tmp/LCK.test", O_RDWR | O_CREAT | O_EXCL, 0444);
   if(file_desc == -1)  {
       save_error = errno;
       printf("open failed with error %d", save_error);
   }
   else 
       printf("Open successful\n");
   exit(EXIT_SUCCESS);
}
