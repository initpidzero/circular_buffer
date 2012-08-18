/* +--------------------------------------------------------------------+ */
/* |          This program demonstrate the use of pointer on argv       | */
/* |                         ------X-------                             | */
/* +--------------------------------------------------------------------+ */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

float avg(float a[], int n);

int main(int argc, char *argv[])
{
   
   float f[20], *q, average;
   int n = argc - 1;
   argv++;
   q = f;
   while(--argc > 0)  
   *q++ = atof(*argv++);
   average = avg(f, n);    
   printf("%f", average);
   exit(EXIT_SUCCESS);
   
} /* end main */
 
float avg(float f[], int n)
{ 
   int i;
   float avrg= 0.0;
   for(i = 0; i < n; i ++)
       avrg = avrg + f[i];
   avrg = avrg/n;
   return avrg; 
}
