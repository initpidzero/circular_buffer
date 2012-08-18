#include <stdlib.h>
#include <stdio.h>

#include <mysql/mysql.h> /* mysql API */

int main( int argc, char *argv[])
{
   MYSQL my_connection;
   
   mysql_init(&my_connection);
  
   if(mysql_real_connect(&my_connection, "localhost", NULL, NULL, "foo", 
                                  0, NULL, 0))  {
       printf("Connection successful\n");
       mysql_close(&my_connection);
   }
   else  {
       fprintf(stderr,"Connection failed\n");
       if(mysql_errno(&my_connection)) 
           fprintf(stderr, "Connection error %d: %s\n", 
           mysql_errno(&my_connection), mysql_error(&my_connection));
   }     
   
   return EXIT_SUCCESS;
}

