   #include <fcntl.h>
    #include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
int main(int argc, char *argv[])
{
    int pipefd[2];
    pid_t cpid;
    char buf;
    if (argc != 2) {
        fprintf(stderr, "Использование: %s <string>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }
    cpid = fork();
     switch(cpid) {
    case -1:
        perror("fork");
        exit(EXIT_FAILURE);
    case 0:   
        close(pipefd[1]);          
        while (read(pipefd[0], &buf, 1) > 0){
        char ss=toupper(buf);
            write(STDOUT_FILENO, &buf, 1);
            }
        write(STDOUT_FILENO, "\n", 1);
        close(pipefd[0]);
        _exit(EXIT_SUCCESS);
     default:          
        close(pipefd[0]);        
        write(pipefd[1], argv[1], strlen(argv[1]));
        close(pipefd[1]);         
        wait(NULL);                
        exit(EXIT_SUCCESS);
    }
}

   
   
    

    
    
