#include <stdio.h>

int fact(int facto, int num)
{	

	if(num == 0)
		facto  = 1;
	else 
	facto = num * fact(facto, num - 1);
	
	return facto;
}

int main(void)
{
	int num = 10;
	int facto = 1;
	printf("fact = %d", fact(facto, num));
	return 0;
}

