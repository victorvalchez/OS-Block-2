#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main (){
  printf ("Hola\n");
  fork ();
  printf ("Uno\n");
  fork ();
  printf ("Dos pid=%d\n",getpid());
  }