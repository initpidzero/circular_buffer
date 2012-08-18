/******************************************************************
*******This program demonstrates the use of mmap function*********
******************************************************************/

#include <stdio.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

typedef struct {
   int integer;
   char string[24];
} RECORD;

#define NRECORDS (100)

int main(void)
{ 
   int i, f;
   RECORD *maped, record;
   FILE *fp;
   
   fp = fopen("data.dat", "w+");
   
   /*simple write the data*/
   for(i = 0; i < NRECORDS; i++)  {
       record.integer = i;
       sprintf(record.string, "RECORD=%d", i);
       fwrite(&record, sizeof(record), 1, fp);
   }
   fclose(fp);
   
   /*data manipulation*/
   fp = fopen("data.dat", "r+");
   fseek(fp, 43*sizeof(record), SEEK_SET);
   fread(&record, sizeof(record), 1, fp );
   
   record.integer = 143;
   sprintf(record.string, "RECORD=%d", record.integer);
   
   fseek(fp, 43*sizeof(record), SEEK_SET);
   fwrite(&record, sizeof(record), 1, fp);
   fclose(fp);
   
   f = open("data.dat", O_RDWR);
   maped = (RECORD *)mmap(0, NRECORDS*sizeof(record), PROT_READ | PROT_WRITE, 
                          MAP_SHARED, f, 0);
   
   maped[43].integer = 243;
   sprintf(maped[43].string, "RECORD = %d", maped[43].integer);

   msync((void *)maped, NRECORDS * sizeof(record), MS_ASYNC);
   munmap((void *)maped, NRECORDS * sizeof(record));
   
   close(f); 
   
   exit(0);
}
  

     

   
