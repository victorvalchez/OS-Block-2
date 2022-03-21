#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <pthread.h>

/*Make a program that:
    declares a global variable "myglobal”
    creates 1 thread ”imprimir_puntos". 
    The program then makes a for up to 20 in the increments myglobal by 1. Then it ends up printing the value of myglobal.
    The function " imprimir_puntos " executes a loop 20 where in each turn the value of myglobal is assigned to an auxiliary 
        variable that is incremented. A "." Is printed. per lap. When finished, it sleeps 1sec and saves the auxiliary 
        value in myglobal.

Request:
a) Implement the program */
int myglobal=0;

void * imprimir_puntos(void *arg) {
  int i,j;
  for ( i=0; i<20; i++ ) {
    j=myglobal;
    j=j+1;
    printf(".");
    fflush(stdout);  //limpiar buffer NO NECESARIO
    sleep(1);
    myglobal=j;
  }
  return NULL;
}

int main(void) {
  pthread_t mythread;
  int i;

  if ( pthread_create( &mythread, NULL, imprimir_puntos, NULL) ) {
    printf("error creating thread.");
    abort();
  }
  //la thread y el loop se ejecutan a la vez 
  for ( i=0; i<20; i++) {
    myglobal=myglobal+1;
    printf("o"); fflush(stdout);
    sleep(1);
  }
  if ( pthread_join ( mythread, NULL ) ) {
    printf("error joining thread.");
    abort();
  }
  printf("\nmyglobal equals %d\n",myglobal);
  exit(0);
}

/*
b) Run the program and see what happens to the value of myglobal. Is it the same if it is run multiple times? 
Al modificar una variable global de forma concurrente por padre y thread hijo, no podemos saber cual será el valor final.  
En casa caso puede salir distinto, tanto en orden de impresión como en número.  
Debajo se muestran 2 ejemplos de ejecución:
    jesus$ ./a.out
    o.o.o..o.o.o.o.o.o.oo..oo.o..o.oo..oo.o.
    myglobal equals 21
    jesus$ ./a.out
    o.o..o.o.oo..oo..o.oo.o..o.o.o.o.oo.o..o
    myglobal equals 23
*/

