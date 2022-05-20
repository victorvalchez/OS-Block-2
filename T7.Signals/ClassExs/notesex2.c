#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

int main(){
    int fd;
    int dupfd;
    fd = open("salida.txt", O_RDWR|O_CREAT, 0666);
    close(1);
    dupfd = dup(fd);
    close(fd);

    printf("Prueba");
}