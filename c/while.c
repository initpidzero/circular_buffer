/**************************************************************************/
/*****To use a break*****************************************************/
/**************************************************************************/

#include <stdio.h>

int main(void)
{
    char str[20];
    int item,total;
    
    while(1)  {
    printf("Enter # to print");
    printf("Enter 0 to quit");
    fgets(str,sizeof(str),stdin);
    sscanf(str,"%d",&item);
    if(item==0)
    break;
    printf(str);
    }
     
    return 0;
}
