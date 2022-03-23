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
- Implement a program that waits 3 seconds for the user to press a key. 

- If the 3 seconds pass without pressing anything, the program ends.
*/
int finTiempo=0;
void llegoAlarma (int s){
  printf ("Ha llegado la señal de alarma: %d\n",s);
  finTiempo=1;
}
int main (){
	int i,faltan,n=33;
	struct sigaction sa;

	sa.sa_handler= llegoAlarma;
	sa.sa_flags=0;
	sigemptyset (&(sa.sa_mask));
	sigaction (SIGALRM, &sa, NULL);
	alarm(3);
	printf ("Dar un número (tiene 3 segundos) \n" );
	scanf ("%d",&n);

	if (finTiempo){
    	printf ("Se acabo el tiempo el número  sera el %d\n",n );
	}
	else {
		printf ("número leído %d\n",n );
	}
}
