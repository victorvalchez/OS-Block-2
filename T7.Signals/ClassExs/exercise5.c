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
- Implement a program that implements an infinite loop that does the following: 
	Set a 3 second alarm.
	Pause the process. 

-It should capture the alarm signal and display a message with the signal number. 

- The process should continue until CTRL-C is pressed on the keyboard.
*/
void catch_alarm(int signo)
{
    printf("Alarma %d \n", signo);
}

int main()
{
  for(;;){
    if (signal(SIGALRM, catch_alarm) == SIG_ERR)
        exit(1);
    alarm(1);           /* start the timer */
    pause();            /* next caught signal wakes us up */
   }
}
