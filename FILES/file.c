#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(){
    int fd;

    char buffer[1024];
    mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH; // 0666 permissions
    ssize_t bytesRead;

    fd = open("text.txt", O_RDONLY);

    if (fd == -1) {
        perror("Error opening/creating file");
        return 1;
    }

    while ((bytesRead = read(fd,buffer, 1024)) > 0)
    {
        if (write(STDOUT_FILENO,buffer,bytesRead) == -1)
        {
            perror("Error writing to stdout");
            close(fd);
            return 1;
        }
        
    }
    close(fd);
    
}