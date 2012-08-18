/**************************************************************************/
/*****To print local time using ctime function*****************************/
/**************************************************************************/

#include <stdio.h>
#include <time.h>

int main(void)
{
    time_t the_time;
    
    (void)time(&the_time);
    
    printf("time is %s\n",ctime(&the_time)); /*see how time is used*/
     
    return 0;
}
