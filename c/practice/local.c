#include <stdio.h>
#include <string.h>

int main(void)
{
   char *tmp ;
   char *str = "ABCDEG";
   tmp = (char *)malloc(sizeof(char) * 5);
   strcpy(tmp, str);
   printf("%d\t %s\n", strlen(),tmp);
}
