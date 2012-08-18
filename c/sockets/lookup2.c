#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define TRUE  1
#define FALSE 0

extern int h_errno;

int main(int argc, char *argv[])
{

   int x1, x2;
   struct hostent *hp;
   sethostent(FALSE);
   for(x1 = 1; x1 < argc; ++x1)  {
       hp = gethostbyname(argv[x1]);
       if(0 == hp){
           fprintf(stderr, "host %s not found %s\n", argv[x1], hstrerror(h_errno));
           continue;
       }
       printf("host:: %s\n", argv);
       printf("official name \t%s\n", hp->h_name);
       fputs("aliases",stdout);
       for(x2 = 0; hp->h_aliases[x2]; ++x2){
           if(x2)
               fputs(",", stdout);
           fputs(hp->h_aliases[x2], stdout);    	
       }
       printf("\n");
       printf("type \t %s\n", hp->h_addrtype == AF_INET ? "AF_INET":"AF_INET6" );
       if(hp->h_addrtype == AF_INET)
           for(x2 = 0; 	hp->h_addr_list[x2]; ++x2)
               printf("Address \t %s \n", inet_ntoa(*(struct in_addr *)hp->h_addr_list[x2]));
       putchar('\n');
   }
   return 0;
  
}
