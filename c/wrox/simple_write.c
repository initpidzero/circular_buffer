/**************************************************************************/
/*****To use write system call*********************************************/
/**************************************************************************/

#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    if((write(1, "write the data here", 18)) != 0)
         write(2, "A write error has occured on file descriptor 1\n", 48);
      
    exit(0);
}
