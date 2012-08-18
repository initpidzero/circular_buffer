#include "ourheader.h"
#include <setjmp.h>

static void f1(int, int, int);
static void f2(void);

static jmp_buf jmpbuffer;
int main (void)
{
   int count ;
   register int sum;
   volatile int total;
   count = 2; sum = 3; total =4;
  
   if(setjmp(jmpbuffer) != 0)  {
       printf("after longjmp: count = %d sum = %d total = %d\n", 
                                              count, sum, total); 
       exit(0);
   }
   /* after setjmp and before longjmp */
   count = 97; sum = 98; total = 99;
   f1(count, sum, total);
}

static void f1(int i, int j, int k)
{
   printf("in f1() the value of count = %d sum = %d total = %d\n", i, j, k);
   f2();
}

static void f2(void)
{
  longjmp(jmpbuffer, 1);
}

