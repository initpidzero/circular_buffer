#include <stdio.h>

void a(int);

int main(void)
{  
   a(2);
   return 0;

}

void a (int i)
{
   if(i >= 1)
       a(--i);
   else 
      printf("finally");
  
}
