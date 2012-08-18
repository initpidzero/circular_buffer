/**************************************************************************/
/*****To copy a file  *****************************************************/
/**************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *in, *out;
    int c;
    
    in = fopen("file.in", "r");
    out = fopen("file.out", "w");
    while((c= fgetc(in)) != EOF );
    fputc(c,out);
     
    exit(0);
}
