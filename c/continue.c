/**************************************************************************/
/*****To use a continue*****************************************************/
/**************************************************************************/

#include <stdio.h>

int main(void)
{
    char str[20];
    int item,total,minus;
    
    minus=0;
    total=0;
   
    while(1)  {
       printf("Enter num to add");
       printf("Enter 0 to quit");
       fgets(str,sizeof(str),stdin);
       sscanf(str,"%d",&item);
       if(item==0)
          break;
       if(item<0) {
          ++minus;
          continue;
       }
       total+=item;
       
    }
   
    printf("the total is %d excluding %d negative number",total,minus); 
    return 0;
}
