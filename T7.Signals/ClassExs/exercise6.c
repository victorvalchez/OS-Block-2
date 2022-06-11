#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>
/*
Write a program in C that implements the command:
 “ls | wc”. 
*/
int main(void){
   int fd[2];
   pid_t pid;

   if (pipe(fd) < 0)  {
      perror("pipe");
      exit(-1);
  }
  pid = fork();
  switch(pid)  {
      case -1:   /* error */
         perror("fork");
         exit(-1);
      case 0:    /* proceso hijo  ls */
          close(fd[0]); 
          close(STDOUT_FILENO); 
          dup(fd[1]);
          close(fd[1]);
          execlp("ls","ls", NULL);
          perror("execlp");
          exit(-1);
          break;
      default:  
/* proceso padre ejecuta ``wc'' */
          close(fd[1]); 
          close(STDIN_FILENO); 
          dup(fd[0]);
          close(fd[0]);
          execlp("wc","wc",NULL);
          perror("execlp");
        }
}

/*El hijo hace ls y se lo comunica al padre a traves del pipe entonces luego el padre hace wc de eso*/