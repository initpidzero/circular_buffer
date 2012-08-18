#include <setjmp.h>
#include <stdio.h>
#include <signal.h>

jmp_buf buf;

void handler(int s)
{
   if(s == SIGINT ) printf("now got a sigint\n");
   longjmp(buf , 1);
	
}

main()
{

   signal(SIGINT, handler);
   if(setjmp(buf)){
       printf("back in main \n");
       return 0;
   }
   else printf("first time through\n");
   loop:
   goto loop;
}
