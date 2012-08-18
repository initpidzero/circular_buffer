#include "ourheader.h"
#include <fcntl.h>
#include <sys/stat.h>

char buf1[]  = "abcdefghij" ;
char buf2[] = "ABCDEFGHIJK" ;

int main(void)
{  
   int fd;

   if((fd = creat("holefile", FILE_MODE)) == -1)
       err_sys("file creation error");  

   if(write(fd, buf1, 10) != 10)
       err_sys("buf1 writing error"); 

   if(lseek(fd, 40, SEEK_SET) == -1)
       err_sys("lseek error");

  if(write(fd, buf2, 10) != 10)
       err_sys("buf2 writing error");
 
   close(fd);

   return 0;
} 
