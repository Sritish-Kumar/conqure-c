#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
int main()
{
int fd, n;
char buf[20];
mkfifo("temp.txt",0600);
fd=open("temp.txt",O_WRONLY);
while(buf!=NULL){
n = read(0,buf,12);
buf[n] = '\0';
write(fd,buf,n);
}
close(fd);
return 0;
}
