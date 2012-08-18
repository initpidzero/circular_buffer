/* ********************************************************************** */
/* ***To copy a file    ************************************************* */
/* ********************************************************************** */

#include <stdio.h>

int main(void)
{
    FILE *fp;
    char c;
    int count = 0;
    fp = fopen("/etc/passwd", "r");
    if(fp == NULL)
    {
       fprintf(stderr, "fopen fails\n");
       exit(1);
    }
     
    while((c = fgetc(fp)) != EOF)
       ++count;
    
    if(printf("%d\n", count)){}
    
    fclose(fp);    
    return 0;
}
