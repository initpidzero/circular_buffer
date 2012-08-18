#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct node {
   char info[100];
   struct node *next;
};

void rev(struct node *);
void addnode(struct node * , const char *);
void delnode(struct node *, const char *);

int main (void)
{
   char line[100];
   char list [][6] = {"one" , "two", "three", "four", "five", ""
   };
   struct node *first_ptr, *current_ptr, *list_ptr;
   int i;
   first_ptr = NULL;

   for(i = 0; i < 5 ;  i++ ) {
       current_ptr = (struct node *)(malloc(sizeof (struct node)));
       strcpy(current_ptr->info, list[i]);
       current_ptr->next = NULL;
       if(0 == i) {
           first_ptr = current_ptr;
           list_ptr =first_ptr;
       }
       list_ptr->next = current_ptr;
       list_ptr = current_ptr;
   }
   addnode(first_ptr, "zero");;
   for(current_ptr = first_ptr; current_ptr != NULL; current_ptr = current_ptr->next)
       printf("%s\n", current_ptr->info);
  
   delnode(first_ptr, "three");;
   for(current_ptr = first_ptr; current_ptr != NULL; current_ptr = current_ptr->next)
       printf("%s\n", current_ptr->info);
   rev(first_ptr);
   return 0;
}

void addnode(struct node * first, const char *value)
{
   struct node *current, *after, *new;
   int temp; 
   current = first;
   after = first->next;
      
   while(after != NULL){
       temp = strcmp(after->info, value);
       if(temp >= 0)
           break;
       current = current->next;
       after = after->next;
   }

   new = (struct node *)(malloc(sizeof (struct node)));
   strcpy(new->info, value);
  
  current->next = new;
  new->next = after;   
}

void rev(struct node *first)
{

   struct node *current, *before, *after;
   before = first;
   current = before->next;
   after = current->next;
   
   before->next = NULL;
   while(after != NULL)  {
       current->next = before;
       before = current;
       current = after; 
       after = after->next;
   }
   current->next = before;
   after = current;

   for(; after != NULL; after = after->next)
       printf("%s\n", after->info);
}


void delnode(struct node *first, const char * value)
{
    
   struct node *current, *after;
    
   current = first;
   after = first->next;
   while(after != NULL) {
       if(!strcmp(after->info, value)) {
           current->next = after->next;
           free(after);
           return;
       }
       else  {
           current = current->next;
           after = after->next;
       }
   }
   printf("element not found\n");
}

