#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include<signal.h>

int main(){
    pid_t  p = fork();
    int status;

    if (p==0)
    {
        printf("Child Process: %d\n",getpid());
        while(1);
    }
   
    //kill the child;
    sleep(5);               // will get terminated if code segmentation fault occurs -> Core File
                            // or SIGSEGV/SIGKILL signal is sent to the process
    kill(p,SIGSEGV);
    wait(&status);


    if (WIFSIGNALED(status))
    {
        printf("Child Exted Abnormal  %d\n",WTERMSIG(status));
    }

    return 0;
    
    
}