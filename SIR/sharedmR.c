
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <string.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;
    int shmid, *shvar;
    key_t key = ftok(".", 45);
    shmid = shmget(key, 20, 0664 | IPC_CREAT);
    printf("Key=%x ........Shmid=%d\n", key, shmid);
    shvar = shmat(shmid, NULL, 0);
    printf("Default initial value of shvar=%d\n", *shvar);
    *shvar = 10;
    pid = fork();
    if (pid == 0)
    {
        *shvar = *shvar + 90;
        printf("child update=%d\n", *shvar);
        exit(0);
    }
    else
    {
        wait(NULL);
        *shvar = *shvar + 110;
        printf("parent updates=%d\n", *shvar);
    }

    // shmdt(shvar);
    // shmctl(shmid,IPC_RMID,NULL);
    return 0;
}
