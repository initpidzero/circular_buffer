/**************************************************************************/
/*****To see pointers *****************************************************/
/**************************************************************************/

#include <stdio.h>

int array[] = {1, 2, 3, 4, 0, 9};
int *array_ptr;

int main(void)
{
    array_ptr = array;
    
    while(*array_ptr != 0)
       ++array_ptr;
    printf("the pointer is at %d position\n", array_ptr-array);        
     
    return 0;
}
