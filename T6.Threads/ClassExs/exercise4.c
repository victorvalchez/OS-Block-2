#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <pthread.h>

/*
A) Write a program that 
 -Declares 2 functions, 1 and 2, where the identity of the thread that is executing is indicated. 
        function 1 sleeps 2 seconds and function 2 sleeps 5 seconds. 
 -Next the main program must launch 2 threads, one for each function, write its own identity and terminate.

B) Write a new version where the parent waits for the children to finish before finishing.
*/

pthread_t thread1, thread2, thmain; /* Declaración de los threads */
pthread_attr_t attr; /* atributos de los threads */

/* Definición de las funciones func1 y func2 */
void *func1 ()
{
  pthread_t tid = pthread_self(); /* identificador de thread*/
  printf("Soy el thread 1 y voy a ejecutar func1 \n");
  sleep(2);
  printf("Soy el thread 1 y he terminado de ejecutar la función 1\n");
  pthread_exit(NULL); /* Provoca la terminación del thread*/
}

void *func2 ()
{
  pthread_t tid = pthread_self(); /* identificador de thread, NO SE ESTÁ USANDO AQUÍ*/
  printf("Soy el thread 2 y voy a ejecutar func2 \n");
  sleep(5);
  printf("Soy el thread 2 y he terminado de ejecutar la función 2\n");
  pthread_exit(NULL); /* Provoca la terminación del thread*/
}

/*Función main*/
int main(void)
{
  thmain = pthread_self();
  /*La propia función main es un thread*/

  /*inicializa los parámetros de los threads por defecto*/
  //pthread_attr_init (&attr);
  printf("Soy la función main y voy a lanzar los dos threads \n");
  pthread_create (&thread1, NULL, func1, NULL);
  pthread_create (&thread2, NULL, func2, NULL); //pthread_create (&thread2, &attr, func2, NULL); es lo mismo
  printf("Soy main: he lanzado los dos threads y termino\n");
  pthread_exit (NULL);
}
