#include <stdio.h>
#include <stdlib.h>

int main(void)
{
   int bin_num, count, pres_bin;
   char line[100];

   fgets(line, sizeof(line), stdin);
   sscanf(line, "%d", &bin_num);
   pres_bin = bin_num;

   for(count = 0; bin_num != 0; bin_num >>=1)
       if(bin_num & 01)
          ++count;
   printf("%d contain %d 1's\n",pres_bin ,count);

   if(count == 1)
     printf("num is a 2's power\n");
   exit(EXIT_SUCCESS);
}

   
