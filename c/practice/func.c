#include <stdio.h>

struct name{
int i;
};

int name;
extern int name (void);
int main (void)
{  
   int i;
   i = name();
   printf("%d", i);
   return 0;
}
int name (void)
{
  struct name name;
  name.i = 1;
  return name.i;
}
