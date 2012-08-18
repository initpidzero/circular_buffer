/**************************************************************************/
/*****To copy a filein blocks    ******************************************/
/**************************************************************************/

#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
    int in,out,nread;
    char buf[1024];/* i dont't know why 1024*/ 

    in = open("file.in",O_RDONLY); /*open file in read only mode*/
    
    /* open file for write only and user permissions are read and write*/
    out = open("file.out",O_WRONLY|O_CREAT, S_IRUSR|S_IWUSR);
    /* use buffer to read the file*/
    while((nread=read(in, buf, sizeof(buf))) > 0)
          write(out, buf, nread);
   
    exit(0);
}
