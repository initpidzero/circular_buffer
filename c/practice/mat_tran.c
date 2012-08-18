/* +--------------------------------------------------------------------+ */
/* |                    This program will convert transpose             | */
/* +--------------------------------------------------------------------+ */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
   int s2[3][3]; 
   int s1[3][3] = { 1, 2, 3,
                    4, 5, 6,
                    7, 8, 9};   
   int i, j, k;
   for (i = 0; i < 3; i++)
       for(j = 0; j < 3; j++)
           s2[i][j] = s1[j][i];
   
   for (i = 0; i < 3; i++) {
       for(j = 0; j < 3; j++)
           printf("%d\t", s2[i][j]);
       printf("\n");
   }

   exit(EXIT_SUCCESS);
   
} /* end main */
 
