/* 
   This is a good example of exit() funtions
*/

#include "ourheader.h"

static void my_exit1(void), my_exit2(void);

int main(void)
{
   if(atexit(my_exit1) != 0)
       err_sys("cant register the first exit\n");

   if(atexit(my_exit2) != 0)
       err_sys("cant register the second exit\n");

   if(atexit(my_exit2) != 0)
       err_sys("cant register the second exit\n");
   
   return 0;
}

static void my_exit1(void)
{
   printf("registering first exit\n");
}

static void my_exit2(void)
{
   printf("registering second exit\n");
}

