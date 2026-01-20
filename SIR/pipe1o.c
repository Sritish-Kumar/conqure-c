#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include<sys/wait.h>

#define BUFSIZE 10

int main(void) {
char bufin[BUFSIZE] = "empty";
pid_t childpid;

int fd[2];//creating a pipe
pipe(fd);

childpid = fork(); //two process

if (childpid) /* parent code */
	{wait(NULL);
	read(fd[0], bufin, 5); //read from pipe
	}
else /* child code */
	write(fd[1], "Sent by Child", 5); //write to pipe
	

fprintf(stderr, "Message is %s",bufin);
return 0;
}
