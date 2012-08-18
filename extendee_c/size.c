#include <stdio.h>
#include <string.h>

void fn(char tat[]) {
	printf("%d\n",(int)sizeof(tat));
}

int main(void)
{
	char tat[20] = "12345";
	char *tat1 = "whatever";

	printf("%d\n",(int)sizeof(tat));
	printf("%d\n",(int)sizeof(tat1));
	printf("%d\n",strlen(tat));
	printf("%d\n",strlen(tat1));
	fn(tat);
	return 0;
}
