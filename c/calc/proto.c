/**************************************************************************/
/*****To scan a number*****************************************************/
/**************************************************************************/

#include <stdio.h>

int main(void)
{
    char str[20],oper;
    int num,result;
    
    
    result = 0;
    while(1) {
        printf("result=%d",result);
        printf("Enter a operator and number");
        fgets(str,sizeof(str),stdin);
        sscanf(str,"%c %d",&oper,&num);
    
        if ((oper=='q') || (oper=='Q'))
        break;
        if(oper=='+')  
          result+=num;
        else if(oper=='-')  
          result-=num;
        else if(oper=='*')  
          result*=num;
        else if(oper=='/') {
          if(num==0)
           printf("cannot divide by zero");   
          else
           result/=num;
        }
        else
          printf("unknown operator");
    } 
     
    return 0;
}
