/* Author offcourse it's me anuz, the great */
#ifndef __ANUZ__
#define __ANUZ__
#endif

/* this program does nothing useful */

#include "ourheader.h"

int main(int argc, char *argv[])
{
   printf("uid = %d, gid = %d, process id = %d\n", getuid(), getgid(), 
                                                                      getpid());
}
