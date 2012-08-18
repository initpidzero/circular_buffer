#include<stdio.h>

int main(void)
{	
	int c, previous;
	int comment_start = 0;
	FILE *fp;
	
	fp = fopen("copy.c", "r");

	while((c = getc(fp)) != EOF){
		if(c == '/') {
			previous = c;
			if((c =  getc(fp)) == '*') {
				comment_start = 1;
				continue;
			}
			putchar(previous);
		}

		if(comment_start){
			if (c == '*' && (c = getc(fp)) == '/')
				comment_start = 0;
			continue;
			
		}
		putchar(c);
		
	}
	fclose(fp);	
	return 0;
}
