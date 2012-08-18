#include <stdio.h>

int main (void)
{
	int c;
	int nr = 0, nb = 0, nt = 0;

	while((c = getchar()) != EOF) {
		if(c == '\t')
			putchar('t');
		else if(c == '\b')
			putchar('b');
		else if(c == '\\')	
			putchar('\\');
		else
			putchar(c);	
	
/*		if(c == ' ') {
			++nb;
			if(nb < 2)
				putchar(c);
		} else {
			nb = 0;
			putchar(c);
		}
 
*/
	}
		
/*	printf("%d\n %d\n %d\n",nr, nb, nt);
*/
	return 0;
}
