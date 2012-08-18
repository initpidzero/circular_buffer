#include  <stdio.h>

int main (void) 
{	
	struct bullshit {
		long what;
		short what1;
		char int1;
		int something;	
		
	} s[2];	
printf("size by difference, %d\n", (char *)&s[1] - (char *)&s[0]);
printf("size by operator %d\n", sizeof(s[1]));
	return 0;
}
