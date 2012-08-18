/* +--------------------------------------------------------------------+ */
/* |       This Program demonstrate how to add two polynomials          | */
/* |                         ------X------                              | */
/* +--------------------------------------------------------------------+ */

#define MAX 100

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct {
   float coeff;
   int expo;
} POLY;

int main(void)
{ 
   POLY polyA[MAX];
   POLY polyB[MAX];
   POLY polyC[MAX];
   int highestA, highestB, i, j, highest;
   char line[100];
   //float;

   printf("Enter the highest exponent for polynomial A\n");
   fgets(line, sizeof(line), stdin);
   sscanf(line, "%d", &highestA);
   printf("Enter the highest exponent for polynomial B\n");
   fgets(line, sizeof(line), stdin);
   sscanf(line, "%d", &highestB);
   
   for (i = highestA; i >= 0; --i) {
       printf("Enter the %d exponent's coefficient for polynomial A\n", i);
       fgets(line, sizeof(line), stdin);
       sscanf(line, "%f", &polyA[i].coeff);
   }

   for (i = highestB; i >= 0; --i) {
       printf("Enter the %d exponent's coefficient for polynomial B\n", i);
       fgets(line, sizeof(line), stdin);
       sscanf(line, "%f", &polyB[i].coeff);
   }
        
   highest = highestA;        
 
   if(highestA > highestB)
       for(i = highestA; i > highestB; i--)
           polyB[i].coeff = 0;
          
   if(highestB > highestA)  {
       highest = highestB;
       for(i = highestB; i > highestA; i--)
           polyA[i].coeff = 0;
   }

   for(i = highest; i >= 0; i--)  
       polyC[i].coeff = polyA[i].coeff + polyB[i].coeff;
   
   printf("The Addition of polynomial is as :::\n");
   for(i = highest; i >= 0; i--)  
       printf("%f x(%d)\t", polyC[i].coeff, i);
   printf("\n");   
   
   exit(EXIT_SUCCESS);
   
} /* end main */
 
