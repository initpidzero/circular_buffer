/* +--------------------------------------------------------------------+ */
/* |                          Consumer Program                          | */
/* +--------------------------------------------------------------------+ */


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#include "shm_com.h"

int main(void)
{
   int running = 1;
   void *shared_memory = (void *)0;
   struct shared_use_st *shared_stuff;
   int shmid;

   srand((unsigned int)getpid()); /* seed for random no. */
   shmid = shmget((key_t)1234, sizeof(struct shared_use_st), 0666 | IPC_CREAT);
   /* create an identifier for the memory */
   if(shmid == -1)  {
       fprintf(stderr, "shmid failed \n");
       exit(EXIT_FAILURE);
   }
   
   shared_memory = shmat(shmid, (void *)0, 0); /* assign shared memory */
   if(shared_memory == (void *) -1){
       fprintf(stderr, "shmat failed \n");
       exit(EXIT_FAILURE);
   }

   printf("memory attached at %X\n", (int)shared_memory);

   shared_stuff = (struct shared_use_st *)shared_memory;
   shared_stuff->written_by_you = 0;

   while(running)  {
       if(shared_stuff->written_by_you) {
           printf("you wrote %s", shared_stuff->some_text);
           sleep(rand() % 4); /* make process wait */
           shared_stuff->written_by_you = 0;
           if(strncmp(shared_stuff->some_text, "end", 3) == 0)
               running = 0;
       }
   }
 
   if(shmdt(shared_memory) == -1) {
       fprintf(stderr," shmdt failed\n");
       exit(EXIT_FAILURE);
   }

   if(shmctl(shmid, IPC_RMID, 0) == -1) {
       fprintf(stderr," shmctl(IPC_RMID) failed\n");
       exit(EXIT_FAILURE);
   }
   
   exit(EXIT_SUCCESS);
   
} /* end main */
 
