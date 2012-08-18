/* ********************************************************************** */
/* *****              This program does some bit stuff              ***** */
/* ********************************************************************** */

#include <stdio.h>

#define X_SIZE 40
#define Y_SIZE 40

char graphics[X_SIZE/8][Y_SIZE];
/* this function sets bit corresponing to x */
# define SET_BIT(x, y) graphics[(x)/8][y] |= (0x80 >> ((x) % 8))
void print_graphics(void);

int main(void)
{
   int loc;
   print_graphics();
  
   for(loc = 0; loc < X_SIZE; loc++)
       SET_BIT(loc, loc);/* set the bits for diagonal element */
   
   print_graphics();    
   return 0;
}

void print_graphics(void)
{
   int x, y;
   unsigned int bit;
  
   for(y = 0; y < Y_SIZE; ++y)  {
       for(x = 0; x < X_SIZE / 8; ++x)
           for(bit = 0x80; bit > 0; bit >>= 1)
               if((graphics[x][y] & bit) != 0)/* check for diagonal element */
                   printf("X");
               else
                   printf(".");
       printf("\n");
   }
}

