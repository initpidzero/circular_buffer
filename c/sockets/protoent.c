/* THIS IS TO USE /etc/protocol files TO OBTAIN PROTOCOL ENTRIES */

#include <unistd.h>
#include <errno.h>
#include <netdb.h>
#include <stdio.h>
#include <netinet/in.h>

int main (void)
{

   struct protoent *pp;
   int x;
  
   for(;;) {
       errno = 0;

       if(!(pp = getprotoent()))
           break;

       printf("%s protocol  %d number\n", pp->p_name, pp->p_proto);
      
       for(x = 0; pp->p_aliases[x] ; ++x)
           printf("alias %s", pp->p_aliases[x]);
       putchar('\n');
     
       if(errno != 0 && errno != ENOENT)
          fprintf(stderr, "%d %s\n", errno, strerror(errno));
   } 
   return 0;
}
