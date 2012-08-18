#include <stdio.h>
#include <stdlib.h>

struct tree{
   int info;
   int count;
   struct tree *left;
   struct tree *right;
};

struct tree *addtree(struct tree *, int);
void printtree(struct tree *);
struct tree *talloc(void);

int main(void)
{  
   int i;
   int a[] = {20, 5, 78, 90, 89, 76, 45, 32, 45, 87};
   struct tree *root;

   root = NULL;
   for(i = 0; i < 10; i++)
       root = addtree(root, a[i]);
   
   printtree(root);

   return 0;
}

struct tree *addtree(struct tree *root, int element)
{
   if(root == NULL)
   {
       root = talloc();
       root->info = element;
       root->count = 1;       
       root->left = NULL;
       root->right = NULL;
   }
     
   else if(root->info == element)
       root->count++;
   else if(root->info < element)
       root->right = addtree(root->right, element);
   else
       root->left = addtree(root->left, element);
 
   return root;
}

void printtree(struct tree *root)
{ 
   if(root != NULL) {
       printtree(root->left);
       printtree(root->right);
       printf("%d\n", root->info);
   }
 
}

struct tree *talloc(void)
{
    return (struct tree *)malloc(sizeof (struct tree));
}
