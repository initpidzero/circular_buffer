/* bubble sort */

#include <stdio.h>
#include <stdlib.h>

void swap(int a[], int i, int j);

int main(void)
{
   int a[10] = {10, 2, 45, 78, 67, 564, 456, 445, 58, 89};
   int i, j, n = 10;
   for(i= 0; i < n ; i++)
       for(j = 1; j < n; j++)
       if(a[j] < a[j - 1])
            swap(a, j, j -1);
   
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

