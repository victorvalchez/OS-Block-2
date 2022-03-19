// fichero ej7-crearthreads.c
//THREADS
// Realizar un programa que declare 2 funciones 1 y 2, donde se indique la identidad del thread que la est� ejecutando. la funci�n 1 se duerme 2 segundos y la 2 se duerme 5 segundos.     A continuaci�n el programa principal debe lanzar 2 threads, uno para cada funci�n, escribir su propiedad identidad y terminar.
Haga una nueva versi�n en la que el padre espere a que los hijos terminen antes de terminar. 
// compilar con  gcc -lpthread ej7-crearthreads.c
//Jes�s Carretero

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>

pthread_t thread1, thread2, thmain; /* Declaraci�n de los threads */
pthread_attr_t attr; /* atributos de los threads */ 

/* Definici�n de las funciones func1 y func2 */
void *func1 () 
{ 
  pthread_t tid = pthread_self(); /* identificador de thread*/ 
  printf("Soy el thread 1 y voy a ejecutar func1 \n"); 
  sleep(2); 
  printf("Soy el thread 1 y he terminado de ejecutar la funci�n 1\n"); 
  pthread_exit(NULL); /* Provoca la terminaci�n del thread*/ 
} 
void *func2 () 
{ 
  pthread_t tid = pthread_self(); /* identificador de thread*/ 
  printf("Soy el thread 2 y voy a ejecutar func2 \n"); 
  sleep(5); 
  printf("Soy el thread 2 y he terminado de ejecutar la funci�n 2\n"); 
  pthread_exit(NULL); /* Provoca la terminaci�n del thread*/ 
}


/*Funci�n main*/ 
int main(void) 
{ 
  thmain = pthread_self(); 
  /*La propia funci�n main es un thread*/ 
  /*inicializa los par�metros de los threads por defecto*/
  pthread_attr_init (&attr); 
  printf("Soy la funci�n main y voy a lanzar los dos threads \n"); 
  pthread_create (&thread1, &attr, func1, NULL); 
  pthread_create (&thread2, &attr, func2, NULL); 
  printf("Soy main: he lanzado los dos threads y termino\n"); 
  pthread_exit (NULL); 
}
