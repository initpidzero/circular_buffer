/* link list */

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int info;
    struct node *next;
} Node;

Node *getnode(int info)
{
    Node *nodeptr;
    nodeptr = (Node *) malloc(sizeof(Node));
    if (nodeptr == NULL) {
	fprintf(stderr, "memory exhausted");
	exit(EXIT_FAILURE);
    }
    nodeptr->info = info;
    nodeptr->next = NULL;

    return nodeptr;
}

int main(void)
{
    int i;
    Node *first, *list, *current, *display;

    for (i = 0; i < 10; ++i) {
	current = getnode(i);
	if (i == 0) {
	    first = current;
	    list = first;
	} else {
	    list->next = current;
	    list = current;

	}
    }

    for (display = first; display != NULL; display = display->next)
	printf("%d\n", display->info);

    exit(EXIT_SUCCESS);
}
