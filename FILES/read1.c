#include <unistd.h>

int main(){

    char buf[20];

    int n = read(STDIN_FILENO,buf,20);

    write(STDOUT_FILENO,buf,n);
    write(STDOUT_FILENO,"Hello, World!\n",14);
    
    return 0;
}