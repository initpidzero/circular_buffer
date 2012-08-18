#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <limits.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define SERVER_FIFO_NAME "/tmp/serv_fifo"

/* NOTICE WE HAVE USED %D FOR FILE NAME */
#define CLIENT_FIFO_NAME "/tmp/cli_%d_fifo" 

#define BUFFER_SIZE 20

struct data_to_pass_st {
   pid_t client_pid;
   char some_data[BUFFER_SIZE - 1];
};
