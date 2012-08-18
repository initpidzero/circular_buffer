#include <stdio.h>

/* program counting digits, characters and spaces */


main()
{
   int ch, nc, nwhite, ndigits[10], index;
   
   nc = nwhite = 0;
   for(index = 0; index < 10; ++index)
        ndigits[index] = 0;
   while((ch = getchar()) != EOF) {
       if(ch >= '0' && ch <= '9')
          ++ndigits[ch - '0'];
       else if(ch == ' ' || ch == '\t' || ch == '\n')
           ++nwhite;
       else 
           ++nc;
             
   }
   for(index = 0; index < 10; ++index)
       printf ("%d appears %d times\n", index, ndigits[index]);
 
   printf("no of chars = %d no of spaces = %d\n", nc, nwhite);
}
