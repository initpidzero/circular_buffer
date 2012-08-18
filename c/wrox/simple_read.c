/**************************************************************************/
/*****To use read system call *********************************************/
/**************************************************************************/

#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    int nread;
    char buf[128];

    nread = read(0, buf, 128);
    if(nread == -1)
       write(2, "a read error has occured\n", 26);
		
    if((write(1, buf, nread)) != nread)
         write(2, "A write error has occured\n", 27);
      
    exit(0);
}
