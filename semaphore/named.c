#include <stdio.h>
#include <semaphore.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

#define SEM_NAME "/sem123"

int main()
{
    sem_t *sem;

    // open
    sem = sem_open(SEM_NAME, O_CREAT | O_EXCL, 0644, 1);

    if (sem == SEM_FAILED)
    {
        perror("sem_open");
        return 1;
    }

    pid_t p = fork();

    if (p == 0)
    {
        // child;

        sem_wait(sem);

        sleep(3); // working

        sem_post(sem);
        return 0;
    }

    // parent
    sleep(1);
    sem_wait(sem);

    sleep(3); // working

    sem_post(sem);

    wait(NULL);

    sem_close(sem);
    sem_unlink(SEM_NAME);

    return 0;
}