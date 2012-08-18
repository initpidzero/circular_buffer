/**************************************************************************/
/* how to use getuid and getpwuid******************************************/
/**************************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <pwd.h>

int main(void)
{
    uid_t uid;
    gid_t gid;
    struct passwd *pw;    
    
    uid = getuid();
    gid = getgid();
   
    printf("user is %s\n", getlogin());
    printf("user IDs: uid = %d, gid = %d\n", uid, gid);
    
   pw = getpwuid(uid);
   /* see how the member of structure are used*/
   printf("UID passwd entry:\n name = %s, uid  = %d,  gid = %d, home = %s, shell = %s\n",
                             pw->pw_name, pw->pw_uid, pw->pw_gid, pw->pw_dir, pw->pw_shell);
   
   /*see how this function uses "root"string*/
   pw = getpwnam("root");
   printf("root passwd entry:\n");
   printf("name = %s, uid = %d, gid = %d, home = %s, shell = %s\n", 
          pw->pw_name, pw->pw_uid, pw->pw_gid, pw->pw_dir, pw->pw_shell);
   
   exit(0);
}
