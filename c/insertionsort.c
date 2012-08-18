/********                  insertion sort       **************/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
   int a[10] = {500, 400, 300, 200, 100, 90, 80, 70, 60, 50};
   int temp;

   int i, j, n = 10;
   for(i = 1; i < n; i++)
       temp = a[i];
       for(j = i - 1; j >= 0 && temp < a[j] ; j--) 
           a[j + 1] = a[j];
       a[j + 1] = temp;  
   for(i= 0; i < n ; i++)
       printf("index = %d num = %d\n", i+1 , a[i]);

   exit(EXIT_SUCCESS);
}


