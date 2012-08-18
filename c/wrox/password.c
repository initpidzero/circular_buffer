/**************************************************************************/
/* this program will demonstrate the use of termios structure tcsetattr****/
/* and tcsgetattr function calls*******************************************/
/**************************************************************************/

#include <termios.h>
#include <stdio.h>

#define PASSWD_LEN 8

int main(void)
{
   struct termios initialrsettings, newrsettings;
   char passwd[PASSWD_LEN + 1];
   
   tcgetattr(fileno(stdin), &initialrsettings);
   newrsettings = initialrsettings;
   newrsettings.c_lflag &= ~ECHO; /* the echo is made one's complement so that no echo*/
   
   printf("Enter the password\n");
  
   if(tcsetattr(fileno(stdin), TCSAFLUSH, &newrsettings) != 0)
    /*TCSAFLUSH flush old values when o/p is complete*/
        fprintf(stderr,"could not set attributes\n");
 
   else  {
       fgets(passwd, PASSWD_LEN, stdin);
       tcsetattr(fileno(stdin), TCSANOW, &initialrsettings);/*rechange to initial setting */
       /*TCSANOW is changes value immediately*/
       fprintf(stdout, "\n You entered %s\n", passwd);
   }    
   
   exit(0);
}
