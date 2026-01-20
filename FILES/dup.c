#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
    int fd, dup_fd;
    
    fd = open("text.txt", O_RDONLY);
    printf("Original fd: %d\n", fd);
    
    close(2);  // Close stderr
    
    dup_fd = dup(fd);  // Will get lowest available fd (2)
    printf("Duplicated fd: %d\n", dup_fd);
    
    close(fd);
    close(dup_fd);
    
    return 0;
}