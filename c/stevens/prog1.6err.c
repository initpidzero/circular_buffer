/* Author offcourse it's me anuz, the great */
#ifndef __ANUZ__
#define __ANUZ__
#endif

/* this program does nothing useful */

#include "ourheader.h"
#include <errno.h>

int main(int argc, char *argv[])
{
   fprintf(stderr, "EACCES: %s\n", strerror(EACCES));
   errno = ENOENT;
   perror(argv[0]);
   exit (0);
}
