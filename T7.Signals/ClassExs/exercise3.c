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
- Implement a program in which the parent process creates a child. 

- The parent must capture the SIGUSR1 signal and the SIGCHLD signal. A different treatment must be done for each signal. 

- The son falls asleep for 2 seconds, sends the SIGUSR1 signal to the parent, and falls asleep for 3 seconds before finishing
*/
void capturaSenal1 (int s){
  printf ("Ha llegado la señal: %d\n",s);
  printf ("tiempo:%ld\n", time(NULL));
}

void muerteHijo (int s){
  printf ("Ha terminado el hijo: %d\n",s);
  printf ("tiempo:%ld\n", time(NULL));
}

int main (){
  int i;
  struct sigaction sa1,sa2;

  if (fork() == 0){
      sleep (10);
      kill ( getppid(), SIGUSR1);
      sleep(3);
  }
  else {
    sa1.sa_handler=capturaSenal1;
    sa1.sa_flags=0;
    sigemptyset(&(sa1.sa_mask));
    sigaction (SIGUSR1, &sa1,NULL);

    sa2.sa_handler=muerteHijo;
    sa2.sa_flags=0;
    sigemptyset(&(sa2.sa_mask));
    sigaction (SIGCHLD, &sa2,NULL);

    pause(); 
    pause(); 
  }
}