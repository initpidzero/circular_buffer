/* +--------------------------------------------------------------------+ */
/* |    This program will create display and search a sequential list   | */
/* |                         ----X-----                                 | */
/* +--------------------------------------------------------------------+ */

#include <stdio.h>
#include <stdlib.h>
/* notes::
  1. Need to initailize an array to store the data
  2. Need to display a list of function
     a. create -- c
     b. display left to right -- l
     c. display right to left -- r
     d. search the list -- s
     e. quit -- q
  3. use a do while loop to call this display unit.
  4. use enum to call function .
  5. make 4 function create, search, left_2_right, right_2_left.
  6. pass the array of no. to create use fgets() and sscanf() to create array
  7. for display pass array and no. of element 
  8. for search pass the no. and array ptr.
*/

char line[100];

int create (int array[]);
void search(int array[], int n);
void left2right(int array[], int n);
void right2left(int array[], int n);
  
int main(void)
{
   int list[100];
   char choice;
   int number, temp;
   //enum { c, l, r, s, q} choice;
   do {
       printf("\n\tThis program create list of number or displays it\n\n");
       printf("1. Enter \"c\" to create a new list\n");
       printf("2. Enter \"l\" to display the list from left to right\n");
       printf("3. Enter \"r\" to display the list from right to lest\n");
       printf("4. Enter \"s\" to search the list\n");   
       printf("5. Enter \"q\" to quit the list\n");
 
       fgets(line, sizeof(line), stdin); 
       sscanf(line, "%c", &choice);
       switch(choice) {
           case 'c':
               number = create(list);
               printf("the number of element is %d", number);
               break;
           case 'l':
               left2right(list, number);
               break;
           case 'r':
               right2left(list, number);
               break;
           case 's':
               search(list, number); 
               break;
           case 'q':
               break;
           default: 
               printf("Improper choice choose only from the menu\n");     
               break;
       }        
   }while(choice != 'q');
   
   exit(EXIT_SUCCESS);
   
} /* end main */

/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
/* this function will create and tell the total no. of elements */ 
/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */

int create (int array[])
{ 
   int i = 0;
   char compare;
   for(; i < 100; i++) {
       printf("Enter the %dth element else Press q to quit\n" ,i + 1);
       fgets(line, sizeof(line), stdin); 
       sscanf(line, "%c", &compare);      
       if(compare == 'q')  
           break;       
       else 
           sscanf(line, "%d", &array[i]);
          
   }
   return i - 1;
}/* end create */

void search(int array[], int number)
{  
   int element;
   int i = 0;

   printf("Enter the number you want to search\n");
   fgets(line, sizeof(line), stdin); 
   sscanf(line, "%d", &element);
   
   while(i <= number){
       if( element == array[i]) { 
           printf("No. found\n");
           printf("The number is on %dth position\n", i + 1);
           break;
       }
       else
           i++; 
   }
}/* end search */

/* Display functions */
void left2right(int array[], int n)
{
  int i;
  for(i = 0; i <= n; ++i)
  printf("The number on %d position is %d\n", i + 1, array[i]);
    
}/* end left to right */

void right2left(int array[], int n)
{
  int i;
  for(i = n; i >= 0; --i)
  printf("The number on %d position is %d\n", i + 1, array[i]);
}/* end right to left */
