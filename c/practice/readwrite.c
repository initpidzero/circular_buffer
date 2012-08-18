#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>

int main (void)
{
   int s,z, w;
   char buf[2624];

   s = open("/etc/passwd", O_RDONLY);
   if(-1 == z){
       printf("open err");
       exit(1);
   }
 
   z = read(s, buf, sizeof(buf));
   if(-1 == z){
       printf("read err");
       exit(1);
   }
 
   w = open("passwd1", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR );
   if(-1 == z){
       printf("read err");
       exit(1);
   } 
   if(write(w, buf, z) != z){
       printf("write err");
       exit(1);
   }
   close (s);
   close(w);
   return 0;    
}
