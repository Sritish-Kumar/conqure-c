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

    for (int i = 0; i < n; i++)
    {
        p = fork();

        if (p == 0)
        {
            // break - > child
            break;
        }

        printf("%d) Child Process: PID = %d, Parent PID = %d\n",i, getpid(), getppid());

    }
    
}

