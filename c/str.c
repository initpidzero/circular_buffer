#include <stdio.h>
#include <string.h>

int main(void)
{
  char first[80], last[80]; /* First and last name*/
  
  printf("Enter the first name");
  fgets(first,sizeof(first),stdin);
  printf("Enter the last name");
  fgets(last,sizeof(last),stdin);
  
  first[strlen(first)-1]= '\0';
  last[strlen(last)-1]= '\0';
  strcat(first," ");
  strcat(first,last);
  printf("%s",first);
 
 return 0;

}

