/* Quick  sort */

#include <stdio.h>
#include <stdlib.h>

void swap(int a[], int i, int j);
void quicksort(int a[], int i , int n);
int main(void)
{
   int a[10] = {10, 2, 45, 78, 67, 564, 456, 445, 58, 89};
   int i = 0, n = 10; 
   quicksort(a, i, n - 1);
   
   for( ; i < n ; i++)
       printf("index = %d num = %d\n", i+1 , a[i]);

   exit(EXIT_SUCCESS);
}

void quicksort(int a[], int i, int n)
{ 
   int  pivot, low = i, high = n, j, temp;
   if(high <= low)
       return;
   swap(a, low, (low + high)/2);
   pivot = low;
   for(j = low + 1; j <= high; j++)
       if(a[j] < a[low])
           swap(a, ++pivot, j);
   swap(a, low, pivot);
   quicksort(a, low,  pivot - 1);
   quicksort(a, pivot + 1, high);
}
       

void swap(int a[], int i , int j)
{ 
   int temp;
   
   temp = a[i];
   a[i] = a[j];
   a[j] = temp;
}

