/* THIS IS TO USE /etc/services files TO OBTAIN SERVER ENTRIES */

#include <unistd.h>
#include <errno.h>
#include <netdb.h>
#include <stdio.h>
#include <netinet/in.h>
int main (void)
{

   struct servent *sp;
   int x;
  
   for(;;) {
       errno = 0;

       if(!(sp = getservent()))
           break;

       printf("%s protocol %d portno %s service\n", sp->s_proto, ntohs(sp->s_port), sp->s_name);
      
       for(x = 0; sp->s_aliases[x] ; ++x)
           printf("alias %s", sp->s_aliases[x]);
       putchar('\n');
     
       if(errno != 0 && errno != ENOENT)
          fprintf(stderr, "%d %s\n", errno, strerror(errno));
   } 
   return 0;
}
