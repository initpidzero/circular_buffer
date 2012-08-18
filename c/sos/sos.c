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
int flag;

char *progname;
char *username;
char *givenpass;
char *command;
char *path;

struct passwd *pwent, *entry; 
struct spwd *shent; 
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
char *stripspace(const char *src)
{
   int i = 0, j = 0;
   char *dest;
   /* i have changed stuff here */
   dest = malloc(strlen(src)*sizeof(char));
   while(src[i])  {
       if(!isspace(src[i]))  {
           dest[j] = src[i];
           j++;
       }  
       i++;
   }
   dest[j] = '\0';
   return dest; 
}


/**
*Main Routine
**/

int main(int argc, char *argv[])
{
   int opt = 0;
   extern char **environ; /* ???shouldn't this be **environ???? */
   extern char *optarg;
   extern int optind; 
   char *pwuser;
  
   progname = malloc(sizeof(argv[0])); /* i have allocated memory here */  
   strcpy(progname, argv[0]);/* first argument is program name */
   
   while((opt = getopt(argc, argv, "u:p:c:")) != EOF)  {
       switch(opt)  {
           case 'u' : /* username */
               if(uflag) 
                   eflag++;
               else  {
                   /* i have allocated memory here */
                   username = malloc(sizeof(optarg));
                   strcpy(username, optarg);
                   uflag++;
               }
               break;
           
           case 'p' : /* password */
               if(pflag)
                    eflag++;
               else  {
                   autopass = malloc(sizeof(optarg));
                  /* allocating space for string */
                   strcpy(autopass, optarg);              
                   pflag++; 
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
   
   if(eflag || !uflag || !cflag){ 
       usage();
       exit(EXIT_FAILURE);
   }
   
   /*this will remove spaces from the username */
   pwuser = stripspace(username); 
   
   /* this is to check whether user exists on not */
   while((entry = getpwent()) != NULL) {
       if(strcmp(pwuser, entry->pw_name) == 0)  {
           flag = 1;
           break;
       }
       else  {
           flag = 0;
           continue;
       }
   }
   /* checking is done here */
   if(flag == 0) {
     printf("user does not exist type valid user\n");
     exit(EXIT_NOUSER);
   }
   
   pwent = getpwnam(pwuser); 
   shent = getspnam(pwuser);
   
   if(pflag)
       givenpass = crypt(autopass, shent->sp_pwdp); 
   else
       /* ??? i don't understand why are we using this obsolete function
      getpass() although i don't know alternative to this may be terminal 
       functions could have been used but are they safe???? */
      
     givenpass = crypt(getpass("Password:"), shent->sp_pwdp);
   
  
   if(strcmp(givenpass, shent->sp_pwdp) != 0)  {
       fprintf(stderr, "SORRY. \n");
       exit(EXIT_FAILURE);
   }
   path = malloc(50 * sizeof(char));/* this is use to set path */
   strcpy(path, "/bin/"); 
   /* this is command path; i assume program lies here in /bin/ */
   strcat(path, command);
  
   setuid(pwent->pw_uid);
  /* ?????i don't undestand why u need to set effective uid */
    
   execle(path, command, NULL, environ);
     
   return EXIT_SUCCESS;
 }
