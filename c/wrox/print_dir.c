/*This is a program equivalant to ls -R*/

#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>

void print_dir(char *dir, int depth)
{
   DIR *dp; /*this is a type defined in dirent.h*/
   /* stucture defined in dirent.h contains char and ino_t*/
   struct dirent *entry;
   struct stat statbuf; /*stucture is defined in stat.h*/
   
  if((dp = opendir(dir)) == NULL)  {
      fprintf(stderr,"cannot open dir %s\n", dir);
      return;
  }
  
  chdir(dir);
  /*readdir is defined under dirent.h and is a structure type*/ 
  while((entry = readdir(dp)) != NULL)  {
     lstat(entry->d_name, &statbuf);/*returns value to structure*/
     
        /*S_ISDIR is a macro defining if it is a directory or not, but need 
          mode as argument*/
     /* determines whether the entry is directory as statbuf.st_mode is mode*/
     if(S_ISDIR(statbuf.st_mode)) {
     /* found a directory but ignore */
        if(strcmp(".", entry->d_name) == 0 || strcmp("..", entry->d_name) == 0)
            continue;
        /*d_name is a char type to hold dirname under dirent stucture*/
        printf("%*s%s/\n", depth, "",entry->d_name);
        /* Recurse at a new indent level */
        print_dir(entry->d_name, depth + 4);
     } 
     
     else
        printf("%*s%s\n", depth, "", entry->d_name);
  }
  
  chdir("..");
  
  closedir(dp); 
}

int main(int argc, char *argv[])
{
   char *topdir = ".";
   
   if(argc >= 2)
      topdir = argv[1];
   printf("dir scan of %s:\n",topdir);
   print_dir(topdir,0);
   printf("done. \n");
  
   exit(0);
}
