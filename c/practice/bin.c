#include <stdio.h>
#include <limits.h>
void bin(int );
unsigned getbits(unsigned,int,int);

int main (void)
{
   int i, num;
   unsigned j;
   char line[100];
   int v = -4;
   num = ~0 + 1; 
  /*  fgets( line, sizeof (line), stdin);
   sscanf(line, "%d", &num); */
   bin(v);
   bin(num);
   printf("%d\n", num);
   /*i = num & ~077;
   bin(i);
   printf("%d\n", ~077);
   i = ~077;
   bin(i);
   j = getbits((unsigned)num, 5, 4);
   bin(j); 

  if(num & 0x10000000) puts("negative");
   else puts("positive");     
  puts("\n");    */          

   return 0;
}

void bin(int num) 
{ 
   int i;   
   for(i = 0x10000000; i > 0; i >>= 1 )
       if (i & num) printf("1");
       else printf("0");
   printf("\n");
}

unsigned getbits(unsigned x,int p,int n)
{  int o,q;
   o = x>>(p+1-n);
   bin(o);
   q = ~(~0<<n);
   bin(q);
   return (x >> (p + 1 - n)) & ~( ~0 << n);
}
