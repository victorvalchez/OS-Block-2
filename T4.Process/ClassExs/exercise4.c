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
    pid = fork(); //en la segunda iteracion se tienen 2 hijos pero solo imprime el nuevo ya que es el == 0
    if ( pid==0) {
      printf ("Soy el hijo %d\n", i);
      pid = fork(); //creamos un nieto
      printf ("Soy el hijo %d\n", i);
      exit(0); //acaba el nieto
    }
  }
}

/* Cuando hacemos el primer fork, creamos un process, ese process 1 va a imprimir soy el hijo i dos veces (el primer print y el segundo), 
luego al hacer el segundo fork, vamos a crear otro, que va a imprimir soy el hijo i una vez,
En la segunda iteracion del loop, duplicamos los dos processes ya creados, entonces se va a imprimir soy el hijo 2, 2 veces
por cada process.

Si pusiesemos el segundo exit, lo que haría seria acabar los dos proceses que se crean en cada loop entonces solo se imprimiria
soy el hijo i, 3 veces como explico en el apartado anterior.
*/