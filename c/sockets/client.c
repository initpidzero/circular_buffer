/* 
  **********************************************************
  **** Example of connect() function and daytime server ****
  **********************************************************
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

void bail(const char *on_what)
{

    fprintf(stderr ,"%s : %s\n", strerror(errno), on_what);
    exit(1);
}   

int main(int argc, char *argv[])
{
   int z,s; /*return status of socket*/
   int len_sock;
   struct sockaddr_in serv_struct;
   char data_buf[128];
   char  *serv_addr = NULL;
   int serv_port = 9900;
   
   if(argc >= 2)
       serv_addr = argv[1];
   else 
       serv_addr = "127.0.0.1";

   if(argc >= 3)
       serv_port = htons(atoi(argv[2]));
   else 
       serv_port = htons(serv_port);

   memset(&serv_struct, 0, sizeof serv_struct);
   serv_struct.sin_family = AF_INET;
   serv_struct.sin_port = serv_port;
   serv_struct.sin_addr.s_addr = inet_addr(serv_addr);
   
   if(serv_struct.sin_addr.s_addr == INADDR_NONE)
       bail("sock addr");

   len_sock = sizeof serv_struct;

   s = socket(PF_INET, SOCK_STREAM, 0);
   if(-1 == s)  
         bail("socket");
   z = connect(s,(struct sockaddr *) &serv_struct, len_sock);
   if(-1 == z)
       bail("connect");
   
   printf("connected\n");
   z = read(s, &data_buf, sizeof data_buf - 1);
   if(-1 == z)
       bail("read");

   data_buf[z] = '\0';
   printf("%s\n", data_buf);
   
   close(s);
   return 0;
}

   
