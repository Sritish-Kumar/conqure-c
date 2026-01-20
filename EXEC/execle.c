#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
    printf("Execle\n");

    char *const env[] = {"PATH=/bin",NULL};
    
    execle("/bin/ls","ls","-l",NULL,env); // replaces the current process, no return    

    printf("This will not be printed\n");
    return 0;

}