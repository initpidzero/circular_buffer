/* Author - anuz
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct tree {
	int count;
	char *data;
	struct tree *left;
	struct tree *right;
} tree;

print_tree(struct tree *root)
{
	if(root == NULL)
		return ;
	else if(root->left == NULL && root->right == NULL){
		printf("%d\n", root->count);
	}else if(root->left == NULL) {
		printf("%d\n", root->count);
		print_tree(root->right);
	}else if(root->right == NULL) {
		printf("%d\n", root->count);
		print_tree(root->left);
	}else {
		printf("%d\n", root->count);
		print_tree(root->left);
	}   
}

void create_node(struct tree **new_tree, int count)
{
	*new_tree = (struct tree *)malloc(sizeof(struct tree));
	printf("%d\n", count);
	(*new_tree)->count = count;
	(*new_tree)->left = NULL;
	(*new_tree)->right = NULL;
}

void locate_and_add(struct tree **new_tree, int count)
{
	if(*new_tree == NULL) {
		create_node(new_tree, count);
	} else {   
		if((*new_tree)->count > count)
			locate_and_add(&(*new_tree)->left, count);
		else
			locate_and_add(&(*new_tree)->right, count);
	}
}


int main (void)
{
	struct tree *new_tree = NULL;
	struct tree *root = NULL;
	int i = 0;
	int data_array[] = {23, 45, 56, 89, 90, 101, 4, 891, 98, 56, 75, 899, 14, 30, 17, 28, 67, 200, 7, 300};

	create_node(&new_tree, data_array[0]);
	root = new_tree;

	printf("%d\n",sizeof(data_array)/sizeof(int));
	for( i = 1; i < sizeof(data_array)/sizeof(int); i++) {
		locate_and_add(&new_tree, data_array[i]);       
	}

	print_tree(root);
	return 0;
}

