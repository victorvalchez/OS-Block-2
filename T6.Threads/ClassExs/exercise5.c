#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <pthread.h>

/*
A) Write a program that adds values ​​in concurrency using threads. 
    The program declares a global variable sum_total 
    A “sumar” procedure that increments sum_total by 100 using an intermediate local variable, sleeps for a second, 
      and assigns the internal variable to sum_total.
    The main then creates 10 threads “sumar”, waits for them to finish, prints the computed sum value, and terminates.

**As a variant, eliminate sleep time and indicate what happens

*/

#define NUMTH 10
int suma_total = 0;

void sumar() {
  int i;
  int suma=suma_total;
  suma = suma + 100;
  sleep(1);
  printf("Pthread =%d  despierta \n", (int)pthread_self());
  suma_total=suma;
}

int main() {
  pthread_t th[NUMTH];
  int i;
  for (i=0;i<NUMTH;i++) {
    pthread_create(&th[i], NULL,(void*)sumar, NULL);
  }

  for (i=0;i<NUMTH;i++) {
    pthread_join(th[i], NULL);
  }

  printf("Suma total = %d\n",
    suma_total);
}