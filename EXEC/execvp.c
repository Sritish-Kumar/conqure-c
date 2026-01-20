#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
    printf("Execvp\n");

    char *args[] = {"ls","-l",NULL};
    
    execvp("ls",args); // replaces the current process, no return

    printf("This will not be printed\n");
    return 0;

}
