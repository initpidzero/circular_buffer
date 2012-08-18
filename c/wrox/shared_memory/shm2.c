/* +--------------------------------------------------------------------+ */
/* |                          Producer Program                          | */
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
   char buffer[BUFSIZ];

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
   
   while(running)  {
       while(shared_stuff->written_by_you == 1) {
           sleep(1);
           printf("Waiting for client...\n");
       }
       printf("Enter some text: ");
       fgets(buffer, BUFSIZ, stdin);
      
       strncpy(shared_stuff->some_text, buffer, TEXT_SIZ);
       shared_stuff->written_by_you = 1;
      
       if(strncmp(buffer, "end", 3) == 0)
           running = 0;
   }
 
   if(shmdt(shared_memory) == -1) {
       fprintf(stderr," shmdt failed\n");
       exit(EXIT_FAILURE);
   }

   exit(EXIT_SUCCESS);
   
} /* end main */

