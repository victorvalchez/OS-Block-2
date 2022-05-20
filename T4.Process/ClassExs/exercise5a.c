#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
/*
#ENUNCIADO:
A) Write a C program that creates a child program that executes a command received as an argument. 
The father ends up without doing more. 

B) Modify the program so that the child writes the command output to a file instead of to the screen.

#SOLUTION:
*/
// A)
int main(int argc, char **argv) {
 int i,pid, pidd;
 //No argument received
 if (argc < 2){  // 1 el nombre del programa, 2 el comando
   printf("Usage: ./exercise5a <comando>\n");
   return(-1);
 }
 pid=fork();
 if(pid==0){ //crear hijo
        printf ("Hijo creado, va a ejecutar el comando\n");
       // Ejecución comando
        execvp (argv[1], &argv[1]);
        perror ("ERROR, aqui solo se llega si ha fallado el exec\n");
  }
  pidd = wait(NULL); // Bloquea el parent process hasta que alguno de sus hijos haya finalizado, returnea el id del child que ha acabado
  printf("childs process id is %i\n", pidd);
  printf ("FIN  del padre, %i\n", getpid());
 } //cierre del main
