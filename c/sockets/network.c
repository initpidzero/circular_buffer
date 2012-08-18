/*********************************************************
****Example of network functions*********************
********************************************************/

#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <netinet/in.h>

   
int main(int arcg, char *argv[])
{
   int x;
   const char *addr[] = {
       "127.0.0.98",
       "10.98.78.7",
       "67.98.67.9",
       "234.222.222.222" 
   };
   unsigned long net_addr;
   
   for(x = 0; x < 4; ++x) {
       net_addr = inet_network(addr[x]);
       printf("%s = 0x%lX net 0x%lX\n ",addr[x], net_addr, 
             (unsigned long)htonl(net_addr));
   }
   
   return 0;
}

   
