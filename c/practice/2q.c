#include <stdio.h>

struct value {
char *value;
int id;
};

void function(struct value **value, int cnt)
{
value[cnt]->value = (char *)malloc(5);
strcpy(value[cnt]->value, "what");
value[cnt]->id = 1;
}

int main (void)
{
	struct value *value;
	value = (struct value *)calloc(1, sizeof(struct value));
	function (&value, 1)
printf("%s  %d \n", value[1].value, value[1].id)
	return 0;
}
