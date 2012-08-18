/* 
Example of socketpair() function
*/

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
   char *cp;/* work pointer */
   char buf[80]; /* work buffer */


   /* create a pair of local sockets*/
   z = socketpair(AF_LOCAL, SOCK_STREAM, 0, s);

   if(z == -1)  {
      fprintf(stderr, "%s: socket pair(AF_LOCAL, SOCK_STREAM,O,s)", 
                       strerror(errno));
      return 1;
   }
   
   /* write a message to socket */
   z = write(s[1], cp="hello?", 6);
   if(z < 0) {
       fprintf(stderr,"%s::write(%d, %s %d)\n",
       strerror(errno),s[1],cp,strlen(cp));
       return 2;
   }
   
   printf("Wrote message on '%s'on s[1]\n", cp);

    /* read socket from file*/
   z = (s[0], buf, sizeof(buf));
   if(z < 0) {
       fprintf(stderr,"%s::read(%d, buf %d)\n",
       strerror(errno),s[0],sizeof(buf));
       return 3;
   }
   buf[z+1] = '\0';
   printf("read message from %s from socket s[0]\n", buf);

   close(s[0]);
   close(s[1]);

   return 0;
}

   
