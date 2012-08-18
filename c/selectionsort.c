/********                  selection sort       **************/

#include <stdio.h>
#include <stdlib.h>

void swap(int a[], int i, int j);

int main(void)
{
   int a[10] = {500, 400, 300, 200, 100, 90, 80, 70, 60, 50};
   int i, j, n = 10;
   for(i= 0; i < n - 1; i++)
       for(j = i + 1; j < n; j++)
           if(a[i] > a[j])
               swap(a, i, j);
   
   for(i= 0; i < n ; i++)
       printf("index = %d num = %d\n", i+1 , a[i]);

   exit(EXIT_SUCCESS);
}

void swap(int a[], int i , int j)
{ 
   int temp;
   
   temp = a[i];
   a[i] = a[j];
   a[j] = temp;
}

