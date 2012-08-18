/* 
  **********************************************************
  **** Example of typical TCP server                    ****
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
#include <time.h>

void bail(const char *on_what)
{

    fprintf(stderr ,"%s : %s\n", strerror(errno), on_what);
    exit(1);
}   

int main(int argc, char *argv[])
{
   int z, s, c, n; /* return status of socket */
   int len_sock; /* length of the sock struct (why the fuck do i name variables like this) */
   struct sockaddr_in serv_struct, clnt_struct;
   char data_buf[128];
   char  *serv_addr = NULL;
   time_t td;
   int serv_port = 9900;
   
   if(argc >= 2)
       serv_addr = argv[1];
   else 
       serv_addr = "127.0.0.1";
   if(argc >= 3)
       serv_port = htons(atoi(argv[2]));
   else 
       serv_port = htons(serv_port);
   
   s = socket(PF_INET, SOCK_STREAM, 0);
   if(-1 == s)
       bail("socket");

   memset(&serv_struct, 0, sizeof serv_struct);
   serv_struct.sin_family = AF_INET;
   serv_struct.sin_port = serv_port;
   if(strcmp(serv_addr , "*") != 0) {
       serv_struct.sin_addr.s_addr = inet_addr(serv_addr);
       if(serv_struct.sin_addr.s_addr == INADDR_NONE)
           bail("sock addr");
   }
   else
       serv_struct.sin_addr.s_addr = INADDR_ANY;/* FUCKING WILD ADDRESS */

   len_sock = sizeof serv_struct;

   z = bind(s, (struct sockaddr *)&serv_struct, len_sock);
   if(-1 == z)  
         bail("bind");
 
   z = listen(s, 5);
   if(-1 == z)
       bail("listen");
   for(;;){
       len_sock = sizeof clnt_struct;
       c = accept(s, (struct sockaddr*)&clnt_struct, &len_sock); 
       if(-1 == c)
           bail("accept");
       time(&td);
       n = (int)strftime(data_buf, sizeof data_buf, "%A %b %d %H::%M::%S %Y\n",
                                                                localtime(&td));
       z = write(c, data_buf, n);
       if(-1 == z)
           bail("write");
       close(c);
   }
   return 0;
}

   
