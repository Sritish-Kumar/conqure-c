#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
    int fd, dup_fd;
    
    fd = open("text.txt", O_RDONLY);
    printf("Original fd: %d\n", fd);
    
    dup_fd = dup2(fd, 2);  // Duplicate fd to fd 2 (stderr)
    printf("Duplicated to fd: %d\n", dup_fd);
    
    close(fd);
    close(dup_fd);
    
    return 0;
}
