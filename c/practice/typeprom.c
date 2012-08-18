#include <stdio.h>

int main(void)
{
   union {
       double d;
       float f;
   }u;
   
   u.d = 10.0;
   printf("put in double pulled out of float %f\n", u.f);

   u.f = 10.0;
   printf("put in float pulled out of double %f\n", u.d);
   
   return 0;
}
