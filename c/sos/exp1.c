#include <stdio.h>

char *stripspace(char *ret, const char *s2, int len)
{
   char *s1;
   int i = 0;
   s1 = malloc(sizeof(s2));
   for( ; i < len && s2[i] != '\0'; i++)    
       if(!isspace(s2[i])) 
  /* included in ctype.h returns zero if there is no space */
           *s1++ = s2[i]; 
   *s1 = '\0';
   printf(s1);
   return s1;
       
}

int main(void)
{
   char *username, *pwuser;
     
   username = "joshi maa chuda le";   
   pwuser = stripspace(pwuser, username, 32);
   printf("%s",pwuser); 
   return 0; 
}

