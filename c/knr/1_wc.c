#include <stdio.h>

/* program counting word, characters and lines */
#define IN 1
#define OUT 0

main()
{
   int ch, nl, nw, nc, state;
   state = OUT;
   nl = nw = nc = 0;
   while((ch = getchar()) != EOF) {
       ++nc; 
       if(ch == '\n') 
           ++nl;
       if(ch == ' ' || ch == '\t' || ch == '\n')
           state = OUT;
       else if(state == OUT) {
           state = IN;
           ++nw;
       }      
   }
   printf("no of chars = %d no of words = %d no of line = %d\n", nc, nw, nl);
}
