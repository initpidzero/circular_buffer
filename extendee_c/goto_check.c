#include<stdio.h>

int main (void)
{
	int i = 0;
	scanf("%d", &i);	
	if(i == 1)
	goto shit;
	if(i == 2)
	goto new;
	if(i == -1)
	goto wo;

	shit:
	puts("shit");
	new:
	puts("new");
	wo:
	puts("wo");
	
	return 0;
}
