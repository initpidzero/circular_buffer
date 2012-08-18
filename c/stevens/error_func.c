#include <errno.h>
#include <stdarg.h>
#include <syslog.h>
#include "ourheader.h"

static void err_doit(int, const char *, va_list);

char *pname = NULL;

/* Non fatal error related to a system call; print a message and return */
void err_ret(const char *fmt, ...)
{
   va_list ap;
   va_start(ap, fmt);
   err_doit(1, fmt, ap);
   va_end(ap);
   return;
}

/* fatal error relate to system call; print a message and terminate */
void err_sys(const char *fmt, ...)
{
   va_list ap;
   va_start(ap, fmt);
   err_doit(1, fmt, ap);
   va_end(ap);
   exit(1);
}

/* fatal error relate to system call print a message; dump core and terminate */
void err_dump(const char *fmt, ...)
{
   va_list ap;
   va_start(ap, fmt);
   err_doit(1, fmt, ap);
   va_end(ap);
   abort(); /* dump core and terminate */
   exit(1);
}

/* Non-fatal error unrelate to system call; print a message and return */
void err_msg(const char *fmt, ...)
{
   va_list ap;
   va_start(ap, fmt);
   err_doit(0, fmt, ap);
   va_end(ap);
   return;
}

/* fatal error relate to system call; print a message and terminate */
void err_quit(const char *fmt, ...)
{
   va_list ap;
   va_start(ap, fmt);
   err_doit(0, fmt, ap);
   va_end(ap);
   exit(1);
}

static void err_doit(int errnoflag, const char *fmt, va_list ap)
{
   int errno_save;
   char buf[MAXLINE];
   
   errno_save = errno;
   vsprintf(buf, fmt, ap);
   if(errnoflag) 
       /* strerror prints the appropriate message as per the errno */ 
       sprintf(buf+strlen(buf), ":%s", strerror(errno_save));
   strcat(buf , "\n");
   fflush(stdout); /* just in case stderr and stdout are same */
   fputs(buf, stderr);
   fflush(NULL);
   return;
}
