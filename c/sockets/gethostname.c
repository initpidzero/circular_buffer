#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main(void)
{
  int z;
  char name[256];
   z = gethostname(name , sizeof(name)); 
   if(-1 == z) {
       fprintf(stderr, "%s\n,: uname", strerror(errno));
       exit(1);
   }
   printf("hostname = %s\n", name);

   z = getdomainname(name , sizeof(name)); 
   if(-1 == z) {
       fprintf(stderr, "%s\n,: uname", strerror(errno));
       exit(1);
   }
   printf("doaminname = %s\n", name);
  
  return 0;
}  
  
