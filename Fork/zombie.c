#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include <sys/wait.h>

int main(){
    pid_t p = fork();

    if (p>0)
    {
        // parent
        printf("parent waiting %d\n",getpid());
        // while(1);
       
        wait(NULL);
    }
    else{
        printf("child %d, %d\n",getpid(),getppid());
        sleep(10);
        exit(0);
    }
}

// Zombie
// A zombie process is a process that has completed execution but still has an entry in the process table.
// This occurs when the parent process has not yet read the exit status of the terminated child process
// using the wait() system call. As a result, the child process remains in the "zombie" state,
// occupying system resources until the parent process retrieves its exit status.
// In the code above, if the parent process does not call wait(), the child process will
// become a zombie after it exits. The parent process should call wait() to clean up the
// zombie process and free up system resources.
