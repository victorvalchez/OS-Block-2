#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(){
    int fd;
    fd = open("file.txt", O_WRONLY | O_TRUNC);
    if (fd == -1) perror("Error");
}