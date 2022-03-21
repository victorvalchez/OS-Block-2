#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <pthread.h>
#include <signal.h>
/*
- Implement a C program in which a parent process creates a child process. 

- The parent, 10 seconds after the creation of the child, must send the SIGUSR1 signal to the child process, 
and then terminate its execution. 

- The child process, when it receives the signal, should display the following message on the screen: 
"SIGNAL RECEIVED" and the signal number and then terminate its execution.
*/

void capturaSenal1 (int s){
   printf ("SIGNAL RECEIVED: %d\n",s);
}
int main() {
    int i,pid;
    struct sigaction sa1,sa2;

    pid = fork();
    if (pid == 0){
        sleep (10);
        kill (pid, SIGUSR1);
        exit(0);
    }
    else { //hijo
        sa1.sa_handler=capturaSenal1;
        sa1.sa_flags=0;
        sigemptyset(&(sa1.sa_mask));
        sigaction (SIGUSR1, &sa1,NULL);
        pause(); // == sleep(999999)
    }
}
