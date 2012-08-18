/**** see how syslog function logs and logging activity is controlled**********/

#include <stdio.h>
#include <syslog.h>

int main(void)
{
   FILE *f;
   
   f= fopen("not_here", "r");
   if(!f)
       syslog(LOG_ERR|LOG_USER, "oops --- %m\n");
   
   exit(0);
}
