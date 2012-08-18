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
        
        switch(oper) {
        case '+' :
           result += num;
           break;
        case '-' :
           result -= num;
           break;
        case '*' :
           result *= num;
           break;
        case '/' :
           if(num==0)
             printf("cannot divide by zero");   
           else
             result /= num;
           break;
        default:
          printf("unknown operator");
          break;
        } 
    } 
    
    return 0;
}
