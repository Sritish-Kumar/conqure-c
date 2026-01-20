#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
    printf("Execl\n");

    execl("/bin/ls","ls","-l",NULL); // replaces the current process, no return

    printf("This will not be printed\n");
    return 0;

}