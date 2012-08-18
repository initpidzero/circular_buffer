#include <stdio.h>
int main (void)
{ 
   int c, i;
   int others = 0, array[26];

   for(i = 'a'; i <= 'z'; i++)
       array[i -'a']  = 0;
   while((c = getchar()) != EOF)
       if(c >= 'a' || c <= 'z')
          ++array[c -'a'];
       else 
          others++;
      
    printf("others%d\n", others);
    for(i = 'a'; i <= 'z'; i++)
    printf("%c = %d\n", i , array[i - 'a']);  
    return 0; 
}
