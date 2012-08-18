#include <stdio.h>

struct value {
char *value;
int id;
};

void function(struct value **value, int cnt)
{
value[cnt]->value = (char *)malloc(5);
strcpy(value[cnt]->value, "what");
value[cnt]->id = 15;
}

int main (void)
{
	struct value *value;
	value = (struct value *)calloc(1, sizeof(struct value));
	function (&value, 0);
printf("%s  %d \n", value[0].value, value[0].id);
	return 0;
}
