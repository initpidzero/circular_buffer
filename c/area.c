/**************************************************************************/
/*****To calculate a area of triangle**************************************/
/**************************************************************************/

#include <stdio.h>

int main(void)
{
    char str[20];
    int length,width,area;
    
    printf("Enter the lenght and width");
    fgets(str,sizeof(str),stdin);
    sscanf(str,"%d %d",&length,&width);
    area=length*width;
    printf("area %d\n",area);
     
    return 0;
}
