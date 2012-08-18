#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void str_rev(char *string)
{
	int len = 0;
	char *temp = NULL;
	int i = 0;
	len = strlen(string);
	temp = (char *)malloc(len + 1);
	for(; len; len--) {
		temp[i++] = *(string + len - 1);
		
	}
	temp[i] = '\0';
	strcpy(string,temp);
	free(temp);
 

}
int main (void)
{
	char string[] = "something";
	str_rev(string);
	printf("%s\n",string);

	return 0;
}
