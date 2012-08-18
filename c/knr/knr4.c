#include <stdio.h>
#include <stdlib.h>

int bin_search(int a[], int n, int x);

int main(void)
{
   int array[10] = {1, 25, 26, 36, 48, 59, 61, 73, 89, 90};
   int number = 10;
   int search_num = 1;
   int position;
  
   position = bin_search(array, number, search_num);
   if(position != -1)
       printf("The number is in %d position\n", position + 1);
   else
       printf("number not found\n");
   
   exit(EXIT_SUCCESS);

}

int bin_search(int a[], int n, int x)
{
   int mid, index, low, high;

   low = 0;
   high = n - 1;
   while(low <= high)
   {
       mid = (low + high) / 2;
       if( x > a[mid])
           low = mid + 1;
       else if(x < a[mid])
           high = mid - 1;
       else
            return mid;
   }
 return -1;
}
