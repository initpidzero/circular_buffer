/* +--------------------------------------------------------------------+ */
/* |              This is a client program                              | */
/* +--------------------------------------------------------------------+ */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(void)
{
   int sockfd, len, result;
   char ch = 'A';
   struct sockaddr_in address;
  
   sockfd = socket(AF_INET, SOCK_STREAM, 0);
   address.sin_family = AF_INET;
   address.sin_addr.s_addr = inet_addr("127.0.0.1");
   address.sin_port = htons(9734);
   len = sizeof(address);

   result = connect(sockfd, (struct sockaddr *)&address, len);
   if(result == -1)  {
       perror("oops: client1");
       exit(EXIT_FAILURE);
   }
   
   write(sockfd, &ch, 1);
   read(sockfd, &ch, 1);
   printf("char from server = %c\n", ch);
   close(sockfd);

   exit(EXIT_SUCCESS);
   
} /* end main */
 
