#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

char *message = "Message from parent";

int main(){
    char buf[1024];
    int fd[2];
    pipe(fd);
    if (fork() != 0){ //means its the parent
        write(fd[1], message, strlen(message) +1);
    }
    else{
        read(fd[0], buf, 1024);
        printf("Child recieved the message: \n -----> %s\n", buf);
    }
}