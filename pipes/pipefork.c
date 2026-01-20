#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>


int main(){
    int fd[2];
    pid_t child;
    char buffer[100];
    
    // create pipe
    if (pipe(fd) < 0)
    {
        printf("NO PIPE ERR");
    }

    child=fork();

    if (child==0)
    // writer -> child
    {
        close(fd[0]); //close fd[0] -> cant read
        
        write(fd[1],"TESTING\n",20);
        close(fd[1]);

    }else{
        // parent -> reader
        close(fd[1]);   //close fd[1] -> cant write

        read(fd[0],buffer,20);
        printf("%s ",buffer);

        close(fd[0]);
        wait(NULL);

    }

    return 0;
}