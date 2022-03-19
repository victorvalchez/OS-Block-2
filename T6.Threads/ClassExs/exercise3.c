#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <pthread.h>

/*
Write a program that creates a variable number of threads, indicated with an argument. 
   - Create a function that prints "Hello from thread" and the thread number and ends.
   - The parent receives the number of threads (integer) as an argument and executes a for loop that creates those threads. Then 
     wait for all threads to finish and finish.
*/
#define MAX_THREAD 10

typedef struct {
        int id;
} parm;

void *hello(void *arg)
{
        parm *p=(parm *)arg;
        printf("Hello from thread %d\n", p->id);
        return (NULL);
}

int main(int argc, char* argv[]) {
        int n,i;
        pthread_t *threads;
        pthread_attr_t pthread_custom_attr;
        parm *p;

        n=atoi(argv[1]);
        if ((n < 1) || (n > MAX_THREAD))
        { printf ("The no of thread should be between 1 and %d.\n",MAX_THREAD); exit(1); }

        threads=(pthread_t *)malloc(n*sizeof(*threads));
        pthread_attr_init(&pthread_custom_attr);
        p=(parm *)malloc(sizeof(parm)*n);
        
       /* Start up thread */
        for (i=0; i<n; i++)
        {
                p[i].id=i;
                pthread_create(&threads[i], &pthread_custom_attr, hello, (void *)(p+i));
        }
        /* Synchronize the completion of each thread. */
        for (i=0; i<n; i++)
                pthread_join(threads[i],NULL);
        free(p);
        return 0;
}
