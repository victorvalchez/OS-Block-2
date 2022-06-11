#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
/*
- Write a C program that allows 2 programs (prog_esc and prog_lec), which by default use standard input and output 
to write or read the data they use, to communicate through a pipe created by the parent of both processes. 

- The prog_lec program asks for a string using STDIN and writes it. 

- The prog_esc just writes a string to the STDOUT standard output.
*/
int main () {
        int fd[2];
        pid_t pid_hijo;
        /* Establecemos la tuberia  */
        pipe (fd);
        if ((pid_hijo = fork ())== -1) {
                perror ("fork");   exit (1);
        }
        if (pid_hijo == 0 ) { /* el hijo */
        /*  Cambio la salida estándar por la de la tuberia */
                dup2 (fd[1],1);  //esta funcion copia el fd[1] y lo copia en el standard putput stdout entonces lo que salga por el fd[1] va a salir en el stdout
                close (fd[0]); // cerramos el descriptor no necesario
        /* prog_esc escribe sobre la salida estándar, que sera la tuberia */
                execlp ("./prog_esc", "./prog_esc", NULL);
        }
        else { /* padre*/
        /*  Cambio la entrada estándar por la de la tuberia */
                dup2 ( fd[0],0);
                close (fd[1]);
        /* prog_lec lee de la entrada estándar, que sera la tuberia */
                execlp ("./prog_lec", "./prog_lec", NULL);
        }
}
