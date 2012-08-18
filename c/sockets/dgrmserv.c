/*********************************************************
****Example of  datagram server*********************
********************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <errno.h>
#include <string.h>
#include <time.h>

static void bail( const char *onwhat)
{
   fputs(strerror(errno), stderr);
   fputs(":",stderr);
   fputs(onwhat, stderr);
   fputs("\n", stderr);
   exit(1);
}

   
int main(int argc, char *argv[])
{
   int z, s, len_inet;
   char *srvr_addr = NULL;
   struct sockaddr_in adr_inet, adr_clnt;
   char dgram[512], dtfmt[512];
   time_t td;
   struct tm tm;
   
   if(argc >= 2){
       srvr_addr = argv[1];
   } 
   else
       srvr_addr = "127.0.0.23";
    
   s = socket(AF_INET, SOCK_DGRAM, 0);
   if(s == -1)
       bail("socket()");
  
   memset(&adr_inet, 0, sizeof adr_inet);
   adr_inet.sin_family = AF_INET;
   adr_inet.sin_port = htons(9000);
   adr_inet.sin_addr.s_addr = inet_addr(srvr_addr);
   
   if(adr_inet.sin_addr.s_addr == INADDR_NONE)
       bail("bad address");
   len_inet = sizeof adr_inet; 
   z = bind(s, (struct sock_addr *)&adr_inet, len_inet);
   if(z == -1)
       bail("bind()");

   for(;;) { 
       len_inet = sizeof adr_clnt;
       z = recvfrom(s, dgram, sizeof dgram, 0, (struct sockaddr *)&adr_clnt,
         &len_inet); 
       printf("server z= \n%d\n", z);
       if ( z < 0)
           bail("recvfrom(2)");
         
       dgram[z] = 0;
       if( !strcasecmp(dgram,"QUIT") )
           break;
       time(&td);
       tm = *localtime(&td);
    
       strftime(dtfmt, sizeof dtfmt, dgram, &tm);
       
       z = sendto(s, dtfmt, strlen(dtfmt), 0, (struct sockaddr *)&adr_clnt,
         len_inet); 
       printf(" server z= \n%d\n", z);
       if(z < 0)
           bail("sendto(2)");
       
   }
   close(s);
   return 0;
}

   
