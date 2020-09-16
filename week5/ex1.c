#include<stdio.h>
#include<pthread.h>
#include <stdlib.h>
#include <unistd.h>

void *threadNumberFunct (void *arg)
{
    int tnum = (int)arg;
    printf("Hello from the thread #%d\n",tnum+1);
}

int main (void)
{

   int n, retVal = 0;
   pthread_t *thread;

   printf("Enter the number of threads: ");
   scanf("%d", &n);

   thread = (pthread_t *) malloc (n*sizeof(pthread_t));

   for (int i = 0; i < n; i++){
       retVal = pthread_create(&thread[i],NULL,threadNumberFunct,(void *)i);
       printf("Thread number %d created.\n", i+1);
       if(retVal != 0){
           printf("pthread_create failed in %d_th pass\n",i);
           exit(EXIT_FAILURE);        
       }
       retVal = pthread_join(thread[i],NULL);
            if(retVal != 0){
               printf("pthread_join failed in %d_th pass\n",i);
               exit(EXIT_FAILURE);        
            }
   }

}
// if we put pthread_join() in another loop then threads will becreated in kinda random order like 0-1-3-2-4 etc

