#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include <sys/wait.h>

int main(){
    pid_t p = fork();

    if (p>0)
    {
        // parent
        printf("parent Dead %d\n",getpid());
        exit(0);
    }
    else{
        printf("child %d, %d\n",getpid(),getppid());
        sleep(10);
        printf("orphan child %d, %d\n",getpid(),getppid());
        exit(0);
    }
    
}