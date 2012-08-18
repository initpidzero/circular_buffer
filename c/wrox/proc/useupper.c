/**************************************************************************/
/********** to use the file for redirection                            ****/
/**************************************************************************/

#include <stdio.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
   char *filename;
   if(argc != 2)  {
       fprintf(stderr, "usage: useupper file\n");
       exit(1);
   }
   filename = argv[1];
   if(!freopen(filename ,"r", stdin)) {
       fprintf(stderr, "could not redirect std in from file %s", filename);
       exit(2);
   }
   execl("./upper", "upper", 0);
   perror("could not exec ./upper");
   exit(3);   
}
