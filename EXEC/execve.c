#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
    printf("Execve\n");

    char *args[] = {"ls","-l",NULL};
    char *const env[] = {"PATH=/bin",NULL};
    
    execve("/bin/ls",args,env); // replaces the current process, no return

    printf("This will not be printed\n");
    return 0;

}
