/* ********************************************************************** */
/* ***To scan using sscanf  ********************************************* */
/* ********************************************************************** */

#include <stdio.h>

int main(void)
{
    int scan_count, total, count;
    char line[100];
    fgets(line, sizeof(line), stdin);
    scan_count = sscanf(line, "%d %d", &total, &count);
    switch(scan_count){
       case EOF:
           printf("error");
           break;
       case 0:
           printf("no argument"); 
           break;
       case 1:
           printf("one argument");
           break;
       case 2:
           printf("two argument");
           break;
       default:
           printf("hi ");
           break;
    }  

    return 0;
}
