#include <stdio.h>
#include <unistd.h>

#define BUFFER_SIZE 100

char* msg1 = "Hello, ";

char* msg2 = "this is ";


int main(){
    
    int p[2];
    char buffer[BUFFER_SIZE];

    if (pipe(p) <0)
    {
        return 1;
    }

    // write pipe
    write(p[1],msg1,BUFFER_SIZE);
    write(p[1],msg2,BUFFER_SIZE);

    for (size_t i = 0; i < 2; i++)
    {   
        // read
        read(p[0],buffer,BUFFER_SIZE);
        printf("%s\n",buffer);
    }


    return 0;
}