#include <stdio.h>
void test(char a[]);
void other(char *p);
char ga[10] = "ABCDEFG";
int main(void)
{
   char array[10] = "hello";
   //test(array);
   //other(array);
   printf("in the main %p %p %p\n", &ga, &ga[0], &ga[1]);
   test(ga);
   other(ga);
   return 0;
}

void test(char ca[])
{

 printf("%p %p %p %p\n", &ca, ca, &ca[0], &ca[1]);
}

void other(char *pa)
{
  printf("%p %p %p %p %p\n", &pa, pa, &pa[0], &pa[1], ++pa);
}
