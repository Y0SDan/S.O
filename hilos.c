#include <errno.h>
#include <pthread.h>
#include <signal.h>
#include <stdio.h>                                                             
#include <unistd.h>

void *proceso_1(void *s){  
   printf("soy un proceso delgado mejor conocido como Hilo o Thread\n");
   pthread_exit(NULL);
}

 
void *proceso_2(void *parametro){  
   printf("Yo soy otro Hilo o Thread\n");
   int *ptr = (int *)parametro;
   printf("mi dato de entrada es %d\n", *ptr);
   pthread_exit(NULL);
}


int main()
{
   int k = 25;
   pthread_t hilo_1, hilo_2;
   pthread_create(&hilo_1, NULL, proceso_1, NULL); //al acabar esta linea se crea el hilo
   pthread_create(&hilo_2, NULL, proceso_2, (void *)&k);
   pthread_join(hilo_1, NULL);
   pthread_join(hilo_2, NULL);
   printf("fin de main\n");
   return 0;
}
