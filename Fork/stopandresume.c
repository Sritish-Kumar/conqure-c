#define _POSIX_C_SOURCE 200809L
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<signal.h>

int main(){
    pid_t child = fork();
    int status;

    if(child==0){
        printf("Child Working\n");
        while(1);

    }

    //stop child
    printf("Stopped\n");
    kill(child,SIGSTOP);
    waitpid(child,&status,WUNTRACED);
    printf("%d %d\n", WIFSTOPPED(status),WSTOPSIG(status));


    sleep(5);
    // Resume
    printf("Resumed\n");
    kill(child,SIGCONT);
    waitpid(child,&status,WCONTINUED);
    printf("%d %d\n", WIFCONTINUED(status),WSTOPSIG(status));

    return 0;

}
