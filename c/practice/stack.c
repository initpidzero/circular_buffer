#ifndef __ANUZ__
#define __ANUZ__
#endif

/*****
   I am trying to simulate a stack . Ain't that fukin good.
*****/

#include <stdio.h>

#define MAXSTACK 10
 
typedef char StackEntry; /* type of data stack contains; such things induce
                         portability */
typedef unsigned char Boolean;

typedef struct stack {
   int top;
   StackEntry entry[MAXSTACK];

} Stack;

void  CreateStack(Stack *s);
Boolean StackEmpty(Stack *s);
Boolean StackFull(Stack *s);
void Push(StackEntry item, Stack *s);
void Pop(StackEntry *item, Stack *s);

int main(void)
{
   Stack *s;
   int i;
   char line[100], item;


   CreateStack(s);

   for(i = 0; i < MAXSTACK; i++)  {
       fgets(line, sizeof line, stdin);
       sscanf(line, "%c", &item);
       Push(item, s);    
   }

   for(i = 0; i < MAXSTACK; i++)  {
       Pop(&item, s);  
      printf("\n%c\n", item);  
   }
   return 0;
}

void Push(StackEntry item, Stack *s)
{
   if(StackFull(s))  {
       fprintf(stderr, "stack is full\n");
       exit(1);
   }
   else
       s->entry[s->top++] = item;
       
}

void Pop(StackEntry *item, Stack *s)
{
   if(StackEmpty(s))  {
       fprintf(stderr, "stack is Empty\n");
       exit(1);
   }
   else
       *item = s->entry[--s->top];
}

Boolean  StackFull(Stack *s)
{
   return s->top >= MAXSTACK;
}     

Boolean StackEmpty(Stack *s)
{
   return s->top <= 0;
}

void CreateStack(Stack *s)
{
   s->top = 0;
}
