/* ********************************************************************** */
/* **********   To use command line argument    ************************* */
/* ********************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int verbose = 0; /* verbose mode */
char *out_file = "print_out"; /* file name */
char *program_name;
int line_max = 66;

void do_file(char *name)
{
   printf("Verbose %d, line %d, input %s output %s\n", verbose, line_max, name,
          out_file);
}


void usage(void)
{
   fprintf(stderr, "Usage is %s [options] [Filelist]\n", program_name);
   fprintf(stderr, "-v == verbose\n");
   fprintf(stderr, "-l(number) == number of lines\n");
   fprintf(stderr, "-o<name> == set output filename\n");
   exit(8);
}


int main(int argc, char *argv[])
{
   char c;
   program_name = argv[0];
   while( --argc >= 1  && **++argv == '-') {
       c = *(++*argv);
       while(1){
           if(c == 'v') {
                   verbose = 1;
                    break;
           }
           else if(c == 'o') {
                  out_file = ++*argv;
                   break;
           }
           else if(c == 'l') {
                  line_max = atoi(++*argv);
                   break;
           }
           else {
                   fprintf(stderr, "bad option %s\n", *argv);
                   usage();
           }
       }
   }
   if(argc == 0)
       do_file("print.in");       
   else 
       usage();
            
   return 0;
}
