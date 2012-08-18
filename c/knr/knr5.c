#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXNUM 100
#define NUMBER '0'


int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);

int main(void)
{
   int type;
   double op2;
   char s[MAXNUM];
   while( (type = getop(s)) != EOF)
       switch(type)  {
           case NUMBER:
               push(atof(s));
               break;
           case '+':
               push(pop() + pop());
               break;    
           case '-':
               op2 = pop();
               push(pop() - op2);
               break;
           case '*': 
               push(pop() * pop());
                break;
           case '/':
               op2 = pop();
               if(op2 != 0.0)
                   push(pop() / op2);
               else  
                  printf("Illegal operation division by zero\n");
               break;
           case '\n':
               printf("\t%.8g\n", pop());
               break;
           default: 
               printf("UNKNOWN COMMAND\n");
               break;
       }
      
   exit(EXIT_SUCCESS);
}

double value[MAXNUM];
int sp = 0;

void push(double f)    
{
   if(sp < MAXNUM) 
      value[sp++] = f;
   else 
       printf("stack is full cannot push %g\n", f);
  
}             

double pop(void)
{
   if(sp > 0)
       return value[--sp];
   else {
       printf("error : stack empty\n");
       return 0.0; 
   }
}

int getop(char s[])
{  
   int i, c;
   while((c = s[0] = getch()) == ' ' || c == '\t')
       ;
   s[1] = '\0';
   if(!isdigit(c) && c != '.')
       return c;
   i = 0;
   if(isdigit(c))
       while(isdigit(s[++i] = c = getch()))
       ;
   if(c = '.') 
       while(isdigit(s[++i] = c = getch()))
           ;

   s[i] = '\0'; 
   if(c != EOF)
        ungetch(c);
   return NUMBER;
    
}

char buf[MAXNUM];
int bufp = 0;

int getch(void)
{
   return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
   if(bufp >= MAXNUM)
       printf("ungetch: too many characters\n");
   else 
       buf[bufp++] = c;
}

