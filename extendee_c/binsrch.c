#include <stdio.h>

int bin(int low, int *iota, int myst, int size)
{	
	int mid = ( low + size ) / 2 ;
	

	if(low > size)
		return -1;
	if(iota[mid] == myst) 
		return mid;
	
	if(iota[mid] < myst)
		return bin(mid + 1, iota, myst, size);
	else
		return bin(low, iota, myst, mid - 1);
	 
}

int main(void)
{
	
	int iota[ ] = {1, 3, 5, 7, 9 ,10, 50, 66, 97, 98, 100};
	int myst = 66;
	int size = 0;
	int low = 0;
	int index = 0;
	size = sizeof iota/ sizeof (int) - 1;
	index = bin(low, iota, myst, size);
	printf("\nindex = %d\n", index);

	return 0;
}
