/* este programa espera 3 seg a que el usuario pulse un n�mero y si no lo hace deja de esperar */
// Jos� Manuel P�rez Lobato 
#include <stdio.h>
#include <signal.h>
int finTiempo=0;
void llegoAlarma (int s){
  printf ("Ha llegado la se�al de alarma: %d\n",s);
  finTiempo=1;
}
main (){
int i,faltan,n=33;
struct sigaction sa;

	sa.sa_handler= llegoAlarma;
	sa.sa_flags=0;
	sigemptyset (&(sa.sa_mask));
	sigaction (SIGALRM, &sa, NULL);
	alarm(3);
		printf ("Dar un n�mero (tiene 3 segundos) \n" );
		scanf ("%d",&n);
		if (finTiempo)
		  printf ("Se acabo el tiempo el n�mero  sera el %d\n",n );
		else 
		printf ("n�mero le�do %d\n",n );
}
