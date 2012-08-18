/*********************************************************
****Example of socketpair() function*********************
********************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int arcg, char *argv[])
{
   int z; /*return status of socket*/
   int s[2]; /*pair of sockets*/
   
   /* create a pair of local sockets*/
   z = socketpair(AF_LOCAL, SOCK_STREAM, 0, s);
   if(z == -1)  {
      fprintf(stderr, "%s: socket pair(AF_LOCAL, SOCK_STREAM,O,s)", 
                       strerror(errno));
      return 1;
   }
   
   /* report the socket file descriptor returned */
   printf("s[0]=%d\n", s[0]);
   printf("s[1]=%d\n", s[1]);

   system("netstat --unix -p");
   return 0;
}

   
