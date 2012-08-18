/* ********************************************************************** */
/* ***To read a file*************************************************** */
/* ********************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
   FILE *in_file;
   int count;
 
   in_file = fopen(argv[1], "r");
   if(in_file == NULL){
       fprintf(stderr, "file opening error");
       exit(EXIT_FAILURE);
   }
   
   while(fgetc(in_file) != EOF)
       count ++;
   
   printf("this is %d number\n", count);
            
   fclose(in_file);
   return 0;
}
