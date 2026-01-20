#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){
    pid_t p = fork();
    int status;

    if (p==0)
    {
        printf("Child %d, Exiting\n ",getpid());
        sleep(5);
        exit(25);
    }
    else{
        //parent 
        printf("Parent %d, \n",getpid());
        wait(&status);

        if (WIFEXITED(status))
        {
            printf("Child Process Success fully terminated %d \n",WEXITSTATUS(status));
        }
        
    }
    
}