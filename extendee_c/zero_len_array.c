#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct zero_len {
	int one;
	char two;
	unsigned int length;
	char empty[];
};

int main (void)
{
	struct zero_len *new_zero;
	struct zero_len *old_zero;

	new_zero = (struct zero_len *)malloc(sizeof (struct zero_len));
	old_zero = malloc(sizeof(struct zero_len) + strlen("the new string") + 1);
	printf("%d %d %d %d\n", sizeof(*new_zero), sizeof(new_zero->one), sizeof(new_zero->two), 
			 sizeof(new_zero->length));
	strcpy(old_zero->empty , "the new string");
	puts(old_zero->empty);
	printf("%d %d %d %d\n", sizeof(*old_zero), sizeof(old_zero->one), sizeof(old_zero->two), 
			 sizeof(old_zero->length));
	return 0;
}
