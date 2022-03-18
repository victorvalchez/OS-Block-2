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
int main(int argc, char *argv[])
{
 int i,pid;
 if (argc < 2){
   printf("Usage: exec-comando <comando>\n");
   return(-1);
 }
 pid=fork();
 if(pid==0){ //crear hijo
        printf ("Hijo creado, va a ejecutar el comando\n");
       // Ejecución comando
        execvp (argv[1], &argv[1]);
        printf ("ERROR, aqui solo se llega si ha fallado el exec\n");
  }
  wait (NULL);
  printf ("FIN  del padre\n");
 } //cierre del main
