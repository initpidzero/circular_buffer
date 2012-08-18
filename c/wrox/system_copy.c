/**************************************************************************/
/*****To use  copy a file     *********************************************/
/**************************************************************************/

#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
    int in,out;
    char c;

    in = open("file.in",O_RDONLY); /*open file in read only mode*/
    
    /* open file for write only and user permissions are read and write*/
    out = open("file.out",O_WRONLY|O_CREAT, S_IRUSR|S_IWUSR);
    while(read(in, &c, 1) == 1)
          write(out, &c, 1);
   
    exit(0);
}
