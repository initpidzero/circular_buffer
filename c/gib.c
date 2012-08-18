/**************************************************************************/
/*****To print fibonacci series*******************************************/
/**************************************************************************/

#include <stdio.h>

int main(void)
{
    int curr_num,old_num,next_num;
    
    curr_num=1;
    old_num=0;
    next_num=0;
    while(curr_num<100)  {
       next_num=old_num+curr_num;
       printf("%d\n",curr_num);
       old_num=curr_num;
       curr_num=next_num;
    }
     
    return 0;
}
