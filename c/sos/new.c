#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

char *stripspace(const char *src)
{
   int i = 0, j = 0;
   char *dest;
   printf("%s\n",src);
   dest = malloc(strlen(src)*sizeof(char));
   while(src[i])  {
       if(!isspace(src[i]))  {
           dest[j] = src[i];
           j++;
       }  
       i++;
   }
   dest[j] = '\0';
   printf("%s\n", dest);
   return dest; 
}

int main(void)
{
  char *name, *command, *path, *s1;
  
  s1 = "user name is me";
  name = stripspace(s1);
  printf("%s\n", name);
  path = malloc(50 * sizeof(char));
  strcpy(path, "/bin/");
  command = "ls";
  strcat(path, command);
  printf("%s\n", path);
  
  exit(0);
}
