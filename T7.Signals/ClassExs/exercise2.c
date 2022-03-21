#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <pthread.h>
#include <signal.h>
/*
- Implement a program that captures the SIGSEGV signal
    ·Print an error message. 
    ·Put the default treatment back. 

- To raise the signal, it must write to position 0 in memory. Use a pointer for this.
*/
void capturar_seneal(int segnal){
    printf("Se ha producido un error por intento de ocupacion indebida de memoria\n");
    signal(SIGSEGV,SIG_DFL);
}

int main(void){
    int *p;
    signal(SIGSEGV,capturar_seneal);
    printf ("Ya he colocado el manejador\n");
    p=0;  // Puntero en posición 0 de memoria osea el puntero aounta a la posicion 0
    printf ("Voy a poner un 5 en la variable\n");
    *p=5; 
}
