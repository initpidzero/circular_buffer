/* ---------------------------------------------------------------------- */
/*  This program shows how the process compete for same file lock         */
/* ********************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

const char *test_file = "/tmp/lock_test";
#define SIZE_TO_TRY 

int main(void)
{
   int file_desc, res;
   struct flock region_to_lock;
      
   file_desc = open(test_file, O_RDWR | O_CREAT, 0666);
   if(!file_desc)  {
       fprintf(stderr, "unable to open test file %s", test_file);
       exit(EXIT_FAILURE);
   }
       
   region_to_lock.l_type = F_RDLCK;
   region_to_lock.l_whence = SEEK_SET;
   region_to_lock.l_start = 10;
   region_to_lock.l_len = 5; 
             
   printf("process %d trying F_RDLCK on region from %d to %d\n", getpid(),
       (int)region_to_lock.l_start, (int)(region_to_lock.l_start + 
         region_to_lock.l_len));

   res = fcntl(file_desc, F_SETLK, &region_to_lock); 
               /* set lock to the region*/
   if(res == -1)
       printf("process %d - failed to lock region\n", getpid());
   else
       printf("process %d - obtained lock on region\n", getpid());
       
   region_to_lock.l_type = F_UNLCK;
   region_to_lock.l_whence = SEEK_SET;
   region_to_lock.l_start = 10;
   region_to_lock.l_len = 5; 
       
   printf("process %d trying  F_UNLCK on region from %d to %d\n",getpid(),          (int)region_to_lock.l_start, (int)(region_to_lock.l_start + 
         region_to_lock.l_len));
    
   res = fcntl(file_desc, F_SETLK, &region_to_lock); 
               /* set lock to the region*/
   if(res == -1)
       printf("process %d - failed to unlock region\n", getpid());
   else
       printf("process %d - obtained lock on region\n", getpid());
       
   region_to_lock.l_type = F_UNLCK;
   region_to_lock.l_whence = SEEK_SET;
   region_to_lock.l_start = 0;
   region_to_lock.l_len = 50; 
      
   printf("process %d trying  F_UNLCK on region from %d to %d\n",getpid(),          (int)region_to_lock.l_start, (int)(region_to_lock.l_start + 
         region_to_lock.l_len));

   res = fcntl(file_desc, F_SETLK, &region_to_lock); 
               /* set lock to the region*/
   if(res == -1)
       printf("process %d - failed to unlock region\n", getpid());
   else
       printf("process %d - unlocked region\n", getpid());
       
   region_to_lock.l_type = F_WRLCK;
   region_to_lock.l_whence = SEEK_SET;
   region_to_lock.l_start = 16;
   region_to_lock.l_len = 5; 
      
   printf("process %d trying  F_WRLCK on region from %d to %d\n",getpid(),          (int)region_to_lock.l_start, (int)(region_to_lock.l_start + 
         region_to_lock.l_len));

   res = fcntl(file_desc, F_SETLK, &region_to_lock); 
               /* set lock to the region*/
   if(res == -1)
       printf("process %d - failed to lock region\n", getpid());
   else
       printf("process %d - obtained lock on region\n", getpid());
       
   region_to_lock.l_type = F_RDLCK;
   region_to_lock.l_whence = SEEK_SET;
   region_to_lock.l_start = 40;
   region_to_lock.l_len = 10; 
      
   printf("process %d trying  F_RDLCK on region from %d to %d\n",getpid(),          (int)region_to_lock.l_start, (int)(region_to_lock.l_start + 
         region_to_lock.l_len));

   res = fcntl(file_desc, F_SETLK, &region_to_lock); 
               /* set lock to the region*/
   if(res == -1)
       printf("process %d - failed to lock region\n", getpid());
   else
       printf("process %d - obtained lock on region\n", getpid());
       
   region_to_lock.l_type = F_WRLCK;
   region_to_lock.l_whence = SEEK_SET;
   region_to_lock.l_start = 16;
   region_to_lock.l_len = 5; 
       
   printf("process %d trying  F_WRLCK on region from %d to %d\n",getpid(),          (int)region_to_lock.l_start, (int)(region_to_lock.l_start + 
         region_to_lock.l_len));

   res = fcntl(file_desc, F_SETLKW, &region_to_lock); 
               /* set lock to the region*/
   if(res == -1)
       printf("process %d - failed to lock region\n", getpid());
   else
       printf("process %d - obtained locked on region\n", getpid());
   printf("process %d ending\n", getpid());
   close(file_desc);
   exit(EXIT_SUCCESS);
}
