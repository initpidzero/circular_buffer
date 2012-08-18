/*********************************************************
****Example of  make address functions*********************
********************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <netinet/in.h>

   
int main(int arcg, char *argv[])
{
   int x;
   struct sockaddr_in adr_inet;
   const char *addr[] = {
       "127.0.0.98",
       "10.98.78.7",
       "67.98.67.9",
       "234.222.222.222" 
   };
   unsigned long net_addr, net, hst;
   
   for(x = 0; x < 4; ++x) {
       memset(&adr_inet, 0, sizeof adr_inet);
       adr_inet.sin_family = AF_INET;
       adr_inet.sin_port = htons(9000);
       if(!inet_aton(addr[x], &adr_inet.sin_addr))
           puts("bad address\n");
        
       hst = inet_lnaof(adr_inet.sin_addr); 
       net = inet_netof(adr_inet.sin_addr);

       printf("%s net= 0x%lX host = 0x%lX ", inet_ntoa(adr_inet.sin_addr), 
               net, hst);
       memset(&adr_inet, 0,sizeof adr_inet); 
       adr_inet.sin_family = AF_INET;
       adr_inet.sin_port = htons(9000);
       
       adr_inet.sin_addr = inet_makeaddr(net, hst);
       printf("%s  = %s\n","inet_addrs", inet_ntoa(adr_inet.sin_addr));
   }
   
   return 0;
}

   
