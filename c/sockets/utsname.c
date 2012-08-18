#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/utsname.h>

int main(void)
{
   struct utsname machine;
   int z;
   z = uname(&machine); 
   if(-1 == z) {
       fprintf(stderr, "%s\n,: uname", strerror(errno));
       exit(1);
   }
   printf("sysname = %s\n", machine.sysname);
   printf("nodename = %s\n", machine.nodename);
   printf("release = %s\n", machine.release);
   printf("version  = %s\n", machine.version);
   #ifdef _GNU_SOURCE
       printf("domainname = %s\n", machine.domainname);
   #endif
  return 0;
}  
  
