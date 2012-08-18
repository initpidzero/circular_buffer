#include <stdio.h>

long long fib(long long num)
{	

	if(num <= 1)
		return 1;
	else 
	return fib(num - 1) + fib(num - 2);
	
}

int main(void)
{
	long long num = 50;
	long long fibo = 1;

	for(; num >= 0; num--) {
		printf("\nfibonacci = %lld", fib(num));
	}
	return 0;
}

