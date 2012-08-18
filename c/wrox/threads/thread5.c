#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

void *thread_function(void *arg);

char message[] = "Hello World";
int thread_finished = 0;

int main(void)
{
   int res;
   pthread_t a_thread;
   pthread_attr_t thread_attr;
   int max_priority, min_priority;
   struct sched_param scheduling_value;

   res = pthread_attr_init(&thread_attr);
   if(res != 0)  {
       perror("Attribute creation failed");
       exit(EXIT_FAILURE);
   }

   res = pthread_attr_setdetachstate(&thread_attr,PTHREAD_CREATE_DETACHED);
   if(res != 0)  {
       perror("setting detached attribute failed");
       exit(EXIT_FAILURE);
   }

   res = pthread_attr_setschedpolicy(&thread_attr, SCHED_OTHER);
   if(res != 0)  {
       perror("Setting schedule policy failed");
       exit(EXIT_FAILURE);
   }
   
   max_priority = sched_get_priority_max(SCHED_OTHER);
   min_priority = sched_get_priority_min(SCHED_OTHER);

   scheduling_value.sched_priority = min_priority;
   res = pthread_attr_setschedparam(&thread_attr, &scheduling_value);
   if(res != 0) {
       perror("Setting scheduling priority failed\n");
       exit(EXIT_FAILURE);
   }

   res = pthread_create(&a_thread, NULL, thread_function, (void *)message);
   if(res != 0)  {
       perror("Thread creation failed");
       exit(EXIT_FAILURE);
   }
   
   
   res = pthread_attr_destroy(&thread_attr);
   while(!thread_finished)  {
       printf("Waiting for the thread to say it's finished....\n");
       sleep(1);
   }

   printf("other thread finished bye !!\n");

   exit(EXIT_SUCCESS);

}

void *thread_function(void *arg) 
{
   printf("thread_function is running. Argument was %s\n", (char *)arg);
   sleep(4);
   printf("Second thread setting finished flag, and exiting now\n");
   thread_finished = 1;
   pthread_exit(NULL);
} 
