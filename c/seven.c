/********************************************************
*********this program finds no. of 3 and 7 in input*****
*******************************************************/

#include <stdio.h>

char line[80];
int seven_count = 0;
int data[5];
int three_count = 0;
int index;

int main(void)
{  
  printf("enter 5 numbers\n");
  fgets(line, sizeof(line), stdin);
  sscanf(line,"%d %d %d %d %d", &data[0], &data[1], &data[2], &data[3], &data[4]);
  
  for(index = 0; index < 5; ++index)  {
     
     if(data[index] == 3)
     ++three_count;
     
     if(data[index] == 7)
     ++seven_count;
   }
   printf(" %d %d", three_count, seven_count);   
} 
