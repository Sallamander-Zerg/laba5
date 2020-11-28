#include <fcntl.h>
    #include <sys/stat.h>
    #include <semaphore.h>
    #include <stdio.h>
    #include <string.h> 

    #define SEMAPHORE_NAME "/my_named_semaphore"
    #define NAMEDPIPE_NAME "/tmp/my_named_pipe"
    #define BUFSIZE 50

    int main(int argc, char ** argv) {
    sem_t *sem;
    int  len;
    char buf[BUFSIZE];
      if ( mkfifo(NAMEDPIPE_NAME, 0777) ) {
       perror("mkfifo");
      return 1;
      }
    printf("%s is created\n", NAMEDPIPE_NAME);
    if ( (sem = open(NAMEDPIPE_NAME, O_RDONLY)) <= 0 ) {
    perror("open");
    return 1;
    }
    printf("%s is opened\n", NAMEDPIPE_NAME);

   

   
   
    
}
    
    
