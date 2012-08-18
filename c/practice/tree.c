#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct tnode {
   char *word;
   int count;
   struct tnode *left;
   struct tnode *right;  
};

#define MAXWORD 100
struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
int getword(char *, int);

int main (void)
{
   struct tnode *root;
   char word[MAXWORD];
  
   root = NULL;
   while(getword(word, MAXWORD) != EOF)
       if(isalpha(word[0]))
           root = addtree(root, word);
   
   treeprint(root); 
   exit(EXIT_SUCCESS);
}

/* ---------------------------------------------------------------------- */

/* THESE MACRO CORRESPONDS TO getch() AND ungetch() */
#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
   return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
   if(bufp >= BUFSIZE)
       printf("ungetch: too many characters\n");
   else
       buf[bufp++] = c;
}

/* GET THE GODAMN WORD */
int getword(char *word, int lim)
{
   int c;
   char *w = word;

   while(isspace(c = getch()))
       ;
   if(c != EOF)
       *w++ = c;
   if(!isalpha(c)) {
    *w = '\0';
    return c;
   }
  
  for(; --lim > 0; w++)
       if(!isalnum(*w = getch())) {
           ungetch(*w);
           break;
       }
   *w = '\0';
  return word[0];
}

/* ---------------------------------------------------------------------- */

/* THESE FUNCTIONS CORRESPONDS TO TREE NODE ALLOCATION */
struct tnode *talloc(void);
char *strdupl(char *);

struct tnode *addtree(struct tnode *p, char *w)
{
   int cond;
   
   if (p == NULL) {
       p = talloc();
       p->word = strdupl(w);
       p->count = 1;
       p->left = p->right = NULL;
   }
   else if ((cond = strcmp(w, p->word)) == 0)
       p->count++;
   else if(cond < 0)
       p->left = addtree(p->left, w);
   else
      p->right = addtree(p->right, w);

   return p;  
  
}

struct tnode *talloc(void)
{
   return(struct tnode *)malloc(sizeof (struct tnode));
}

char *strdupl(char *s)
{
   char *p;
   p = (char *)malloc(strlen(s) + 1);
   
   if(p != NULL)
       strcpy(p, s); 
   return p;
}

void treeprint(struct tnode *p)
{
   if(p != NULL) {
       treeprint(p->left);
       printf("%4d %s\n", p->count, p->word);
       treeprint(p->right);
   }
}
