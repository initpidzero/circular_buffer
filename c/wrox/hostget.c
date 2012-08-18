/**************************************************************************/
/* how to use uname and gethostname fuctions*******************************/
/**************************************************************************/

#include <stdio.h>
#include <sys/utsname.h>
#include <unistd.h>


int main(void)
{
   char computer[256];
   struct utsname uts;    
    
   if(gethostname(computer, 256) != 0 || uname(&uts) < 0)  {
       fprintf(stderr,"Could not get host information\n");
   }
   
   printf("computer hostname is %s\n", computer);
   printf("System is %s on  %s hardware\n", uts.sysname, uts.machine);
   printf("Nodename is %s\n",uts.nodename);
   printf("Release is %s and version is %s\n", uts.release, uts.version);
   
   exit(0);
}
