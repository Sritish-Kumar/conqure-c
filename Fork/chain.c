#include  <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int main(int argc, char* argv[]){
    if (argc < 2)
    {
        printf("Invalid arg");
        return 1;
    }

    int n = atoi(argv[1]);
    pid_t p ;

    for (size_t i = 0; i < n; i++)
    {
        p = fork();

        if (p > 0)
        {
            // break - > parent
            break;
        }

        printf("%d ) Child Process: PID = %d, Parent PID = %d\n",i, getpid(), getppid());

    }
    
}

