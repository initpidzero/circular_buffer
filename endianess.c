#include <stdio.h>
#include <stdlib.h>

int main () 
{

	short int x = 1;

	if (*(char *)&x == 1)
		printf("Little-endian, low-order byte containing 1 is at %p and high-order byte is at %p.\n",
		&x,(&x + sizeof(x/2)));
	else
	printf("Big-endian, high-order byte containing 1 is at %p and low-order byte is at %p.\n",&x,
		(&x - sizeof(x/2)));

	exit(0);
}
