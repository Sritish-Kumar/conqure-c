#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){

    pid_t p1 = fork();
    pid_t p2 = fork();
    int status;

    if (p1==0)
    {
        printf("Child 1");
        sleep(5);
        exit(10);
    }

    if (p2==0)
    {
        printf("Child 1");
        sleep(2);
        exit(20);   
    }

    waitpid(p1,&status,0);

    printf("Exit status %d",WEXITSTATUS(status));

}