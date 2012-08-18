/**************************************************************************/
/*to use tmpnam and tmpfile functions**************************************/
/**************************************************************************/

#include <stdio.h>

int main(void)
{
   char tmpname[L_tmpnam];
   char *filename;
   FILE *tmpfp;
    
   filename = tmpnam(tmpname);
   printf("Temporary file name is %s\n", filename);
   
   tmpfp = tmpfile();
   if(tmpfp)
       printf("opened a temporary file file ok\n");
   else
       perror("tmpfile");     
    exit(0);
}
