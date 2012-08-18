/* +--------------------------------------------------------------------+ */
/* |                    This program will convert transpose             | */
/* +--------------------------------------------------------------------+ */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
   int s2[3][3] = { 1, 1, 1,
                    1, 1, 1,
                    1, 1, 1
                  }; 
   int s1[3][3] = { 1, 1, 1,
                    1, 1, 1,
                    1, 1, 1};
   int s3[3][3];   
   int i, j, k;
   for (i = 0; i < 3; i++)
       for(j = 0; j < 3; j++) {
           s3[i][j] = 0;
           for(k = 0; k < 3; k++)
               s3[i][j] = s3[i][j] + s1[i][k] * s2[k][j];
       }

   
   for (i = 0; i < 3; i++) {
       for(j = 0; j < 3; j++)
           printf("%d\t", s3[i][j]);
       printf("\n");
   }

   exit(EXIT_SUCCESS);
   
} /* end main */
 
