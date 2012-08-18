/* ********************************************************************** */
/* ************* To generate temperory name for file ******************** */
/* ********************************************************************** */

#include <stdio.h>

char *tmp_nam(void)
{
   static int sequence = 0;
   static char array[20];
   strcpy(array,"tmp");
   ++sequence;
   array[3] = sequence + '0';   
   array[4] = '\0';   
   return(array);
}

int main(void)
{   
    tmp_nam();
    printf("%s\n", tmp_nam());
    return 0;
}
