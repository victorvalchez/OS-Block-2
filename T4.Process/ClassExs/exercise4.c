#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <pthread.h>

int main() {
  int i,pid;
  for (i=1; i<=2; i++){
    pid = fork();
    if ( pid==0) {
      printf ("Soy el hijo %d\n", i);
      exit(0); 
    }
  }
}