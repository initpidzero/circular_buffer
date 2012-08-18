/**************************************************************************/
/*****To scan a number*****************************************************/
/**************************************************************************/

#include <stdio.h>

int main(void)
{
    char str[20];
    int i;
    
    printf("Enter a number");
    fgets(str,sizeof(str),stdin);
    sscanf(str,"%d",&i);
    printf("twice of %d is %d\n",i,2*i);
     
    return 0;
}
