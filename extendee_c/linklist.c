#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZ 256

int main(void)
{
	struct node {
		int data;
		struct node *next;
	} *node;
	int i = 0;
	char tmp_buf[BUF_SIZ];
	struct node *first = NULL;
	struct node *tmp_node = NULL;

	node = NULL;

	for( ; i < 10; i++) {
		if(!node) {
			node = (struct node *)calloc(1, sizeof(node));	
			node->next = NULL;
			first = node;
		} else {
			node->next =  (struct node *)calloc(1, sizeof(node));
			node = node->next;
			node->next = NULL;
		}
		memset(tmp_buf, 0, sizeof(tmp_buf));
		fgets(tmp_buf, sizeof(tmp_buf), stdin);
		sscanf(tmp_buf, "%d", &(node->data));

	}
	node = first;
	while(node) {
		printf("node = %d\n", node->data);
		tmp_node = node->next;
		free(node);
		node = NULL;
		node = tmp_node;	
	}
	return 0;
}
