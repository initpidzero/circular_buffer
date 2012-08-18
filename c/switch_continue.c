#include <stdio.h>

int num;
char type;
char line[200];

int main(void)
{
  while(1)  {
    printf("type the type and number");
    
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%c", &type);
    
    if((type == 'q') || (type == 'Q'))
       break;
        
    switch(type)  {
       case 'o' :
       case 'O' :
         sscanf(line, "%c %o", &type, &num);
         break;
        
       case 'x' :
       case 'X' :
         sscanf(line, "%c %x", &type, &num);
         break;
            
       case 'd' :
       case 'D' :
         sscanf(line, "%c %d", &type, &num);
         break;
                    
       case '?' :
       case 'h' :
         printf("Letter Conversion\n");
         printf("o O    octal\n");
         printf("x X    hexadecimal\n");
         printf("q Q    quit\n");
         printf("d D    decimal\n");
         continue;
      
       default :
         printf("Type ? for help\n");
         continue; 
    }
    
    printf("%d", num);  
  } 

  return (0);
}
      
     
      
