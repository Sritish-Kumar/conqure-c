#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
    
    int fd;
    
    for (size_t i = 0; i < 10; i++)
    {
        fd = open("file.txt", O_RDONLY | O_CREAT, 0666);
        if (fd==-1)
        {
            fprintf(stderr, "Error opening file\n");
            return 1;

        }

        printf("File descriptor %zu: %d\n", i, fd);
        sleep(2);
        // close(fd);
    }
    
    return 0;
}