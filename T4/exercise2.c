#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
/*
Write a C program that creates two processes: parent and child. Both will print “Soy el padre” or “Soy el hijo”, 
as the case may be, and at the end they will print Adios and his pid and his father's pid.

Important: the father should get some sleep to give the child  time to finish and see the pid well. 
What happens if it doesn't go to sleep?
*/

int main () {
int x=0,pid;
  pid=fork (); /*Se crea el hijo */
  if (pid == 0){ 
    printf ("Soy el hijo\n"); /* Escrito por el hijo en pantalla*/
    printf ("Adios hijo; x=%d, pid=%d ppid=%d\n",x,getpid(), getppid()); 
  }
  else { 
    sleep(1);
    printf ("Soy el padre\n"); /* Escrito por el padre en pantalla*/
    printf ("Adios padre; x=%d, pid=%d ppid=%d\n",x,getpid(), getppid()); 
  }
} 

/* 
If the sleep () is not put and the parent ends before the child, it shows that the new parent of the child is process 1 (init). 
That is because, when the father dies, init adopts the son so that it does not become a zombie.
*/