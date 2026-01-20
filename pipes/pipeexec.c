#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
    pid_t pid1, pid2;
    int status1, status2;

    int fd[2];
    if (pipe(fd) < 0)
    {
        perror("Pipe failed");
        return 1;
    }

    pid1 = fork();
    if (pid1==0)
    {
        // ls -l in stdout

        close(fd[0]);

        dup2(fd[1],STDOUT_FILENO);
        close(fd[1]);

        execlp("ls","ls","-l",NULL);
        printf("ERROR");
    }

    pid2 = fork();
    if (pid2==0)
    {
        // wc - w in stdin
        close(fd[1]);

        dup2(fd[0],STDIN_FILENO);
        close(fd[0]);

        execlp("wc","wc","-w",NULL);
        printf("ERROR");
    }


    // parent

    close(fd[0]);
    close(fd[1]);

    wait(NULL);
    wait(NULL);
    

    return 0;
}