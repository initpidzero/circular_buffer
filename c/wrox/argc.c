/*this program demonstartes how the options are read by commands*/

#include <stdio.h>

int  main(int argc, char *argv[])
{
  int arg;
  
  for(arg = 0; arg < argc; arg++)  {
     if(argv[arg][0] == '-')
         printf("options : %s\n",argv[arg]+1);
     else 
         printf("arg %d = %s\n", arg, argv[arg]);
  }
  
  exit(0);
}
