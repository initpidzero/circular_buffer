/************************************************************************/
/******************* see how openlog LOG_UPTO and LOG_MASK works*********/
/************************************************************************/

#include <stdio.h>
#include <syslog.h>
#include <unistd.h>

int main(void)
{
  int logmask;
   
   openlog("logmask",LOG_PID|LOG_CONS, LOG_USER);
   syslog(LOG_INFO, "infomative message, pid = %d", getpid());
   syslog(LOG_DEBUG, "debug message, should appear");
   logmask = setlogmask(LOG_UPTO(LOG_NOTICE));
   syslog(LOG_DEBUG, "debug message, should appear");
   
   exit(0);
}
