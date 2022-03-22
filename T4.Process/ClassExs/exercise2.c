#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
/*
Write a C program that creates two processes: parent and child. Both will print “Soy el padre” or “Soy el hijo”, 
as the case may be, and at the end they will print Adios and his pid and his father's pid.

Important: the father should get some sleep to give the child  time to finish and see the pid well. 
What happens if it doesn't go to sleep?
*/

int main() {
int x=0, pid;
  pid=fork (); /*Se crea el hijo */
  if (pid == 0){    // El pid devuelve 0 para el hijo, y el ID del hijo para el padre
    printf ("Soy el hijo\n"); /* Escrito por el hijo en pantalla*/
    printf ("Adios hijo; x=%d, pid=%d ppid=%d\n",x,getpid(), getppid());  //PPID es parent process id
  }
  else { 
    wait(NULL);     //padre bloqueado hasta que el hijo termina
    printf ("Soy el padre\n"); /* Escrito por el padre en pantalla*/
    printf ("Adios padre; x=%d, pid=%d ppid=%d\n",x,getpid(), getppid()); 
  }
} 