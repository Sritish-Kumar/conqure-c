#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
int main()
{
int fd,n;
char buf[20];
mkfifo("temp.txt",0600);
fd=open("temp.txt",O_RDONLY);
while(buf!=NULL){
n = read(fd,buf,12);
buf[n] = '\0';
write(1,buf,n);
}
close(fd);
unlink("temp.txt");
return 0;
}
