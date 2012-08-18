#define _XOPEN_SOURCE_

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pwd.h>
#include <shadow.h>
#include <sys/types.h>
#include <crypt.h>
#include <string.h>
#define EXIT_NOUSER 2

int uflag;
int pflag;
int cflag;
int eflag;

char *progname;
char *username;
char *givenpass;
char *command;
char *path;

struct passwd *pwent; /* this structure is found in pwd.h */
struct spwd *shent;/* this stucture is found in shadow.h */ 
char *autopass;

/**
* print out usage
**/

void usage(void)
{
   printf("%s -u -c [ -p ]\n", progname);
}

/**
* Strip spaces
**/

char *stripspace(char *ret, const char *s2, int len)
{
   register char *s1 = ret;
   int i = 0;
   s1 = malloc(sizeof(s2));
   for(i = 0; i < len; i++)  {
       if(!isspace(s2[i])) /* included in ctype.h returns zero if there is no space */
       *s1++ = s2[i];
   }
   return ret;
}

/**
*Main Routine
**/

int main(int argc, char *argv[])
{
   int opt = 0;
   /* this stores environ variabel in form of NAME=VALUE */
   extern char **environ; /* ???shouldn't this be **environ???? */
   extern char *optarg;/* this extern string recieves argument from getopt() */
   extern int optind; /* this will store the index from getopt() */
   char *pwuser;
  
   progname = malloc(sizeof(argv[0]));
   strcpy(progname, argv[0]);/* first argument is program name */
   
   while((opt = getopt(argc, argv, "u:p:c:")) != EOF)  {
       switch(opt)  {
           case 'u' : /* username */
               if(uflag) /* not for the first time */
                   eflag++; /* this is where eflag is used */
               else  {
                   username = malloc(sizeof(optarg));
                   strcpy(username, optarg);
                   uflag++; /* uflag is incremented */
               }
               break;
           
           case 'p' : /* password */
               if(pflag)
                    eflag++;
               else  {
                   autopass = malloc(sizeof(optarg)); /* allocating space for string */
                   strcpy(autopass, optarg);/* the argument is apropriately copied */              
                   pflag++; /* ???????????? */
               }    
               break;
         
           case 'c' : /* command */
               if(cflag)
                   eflag++;
               else  {
                   command = malloc(sizeof(optarg));
                   strcpy(command, optarg); 
                   cflag++;
               }
               break;
           
           default:
               eflag++;
       }
   }  
   
   if(eflag || !uflag || !cflag){ /* if none of the command is parsed */
       usage();
       exit(EXIT_FAILURE);
   }
   
   /*this will remove spaces from the username */
   stripspace(pwuser, username, 32); /* how is pwuser used before declaration */
   pwent = getpwnam(pwuser); /* get a structure containing user info */
   shent = getspnam(pwuser); /* get a structure containig encrypted password info */
   
   /* Check if password is supplied or if we are interactive */
   if(pflag)
       /* this function passes user type passwd and key and returns an encrypted value*/
       givenpass = crypt(autopass, shent->sp_pwdp); /* sp_pwdp is encrypted password */
   else
       /* getpass() is obsolete but it opens tty prints prompt and ask passwd */
       givenpass = crypt(getpass("Password:"), shent->sp_pwdp);
   
   /* compare our passwd with shadow */
   if(strcmp(givenpass, shent->sp_pwdp) != 0)  {
       fprintf(stderr, "SORRY. \n");
       exit(EXIT_FAILURE);
   }
   path = malloc(50);
   strcpy(path, command);
   path = strcat("/bin/", path); 
   setuid(pwent->pw_uid);/* setuid as per pw_uid from struct pwent */
   execle(path, command, NULL, environ);
   /* run's command with path command and also environ */
   
   return EXIT_SUCCESS;
 }
