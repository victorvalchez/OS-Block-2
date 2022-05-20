#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

void thread_function() {
  int i;
  for ( i=0 ; i < 2 ; i++ ) {
    printf("Thread says hi!\n");
    sleep(1);
  }
	printf("Thread exists\n");
  exit(0);
}

int main(int argc, char *argv[]) { // same as ** argv

  pthread_t mythread;
	printf("Launching new thread . . .\n");  
  if ( pthread_create( &mythread, NULL, (void *)thread_function, NULL) ) {
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
