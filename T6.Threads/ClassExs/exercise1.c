#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <pthread.h>

/* Write a program that creates 1 thread that prints a message 3 times: 
"Thread says hi!", sleeps 1 second between each message and then indicates that it ends. 

The parent thread program must wait until the child thread terminates. */

void thread_function(void *arg) {
  int i;
  for ( i=0 ; i <= 2 ; i++ ) {
    printf("Thread says hi!\n");
    sleep(1);
  }
}
 
int main(int argc, char * argv[]) {
  pthread_t mythread;
	printf("Launching new thread . . .\n");  
  if ( pthread_create( &mythread, NULL, (void *)thread_function, NULL) ) {      /*primero tu thread, luego si no quieres ninguna constante
  va con NULL, luego la funcion que quieres ejecutar, yluego el argumento que es NULL en este caso*/
    printf("error creating thread.");
    abort();
  }
  printf("Waiting on join\n");
  if ( pthread_join ( mythread, NULL ) ) {
    printf("error joining thread.\n");
    abort();
  }

  exit(0);
}
