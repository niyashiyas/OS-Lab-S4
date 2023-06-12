//System calls

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
 
#include <sys/types.h>
#include <sys/wait.h>
 
void main() {
    pid_t pid=0;
    int status;
    
    pid=fork();
    if(pid==0){
        printf("Child process\n");
        printf("Current process id of the process : %d\n",getpid());
        execl("/bin/ls", "ls",NULL);
    }
    else if(pid>0){
        printf("Parent process with child process id : %d\n",getpid());
        pid=wait(&status);
        printf("Process completed %d\n",pid);
    }
    else
        perror("Fork failed\n");
    
    exit(0);    
    
}