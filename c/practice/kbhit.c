#include <sys/ioctl.h>
#include <stdio.h>
#include <errno.h>

int kbhit(void)
{
   int i;
   if(ioctl(0,FIONREAD, &i) < 0) {
      fprintf(stderr, "%s", strerror(errno));
       exit(1);
    }
    return i;
}

int main(void)
{
   int i = 0;
   int c = ' ';
   
   system("stty raw -echo");
   printf("enter q to quit\n");
   for(; c != 'q'; i++) {
       if(kbhit()){
           c = getchar();
           printf("%c %d", c , i);
       }
   }
   system("stty cooked echo");
   return 0;
}
