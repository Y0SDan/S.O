#include <stdio.h>
#include <semaphore.h>
#include <unistd.h>
#include <pthread.h>

#define CLIENTES 25
#define LUGARES_EN_LA_MESA 24
sem_t semaforo;
unsigned int x=0;

void *mesa( void *p){   // 
    sem_wait(&semaforo);    // decrementa contador en 1

    while(1)
        x++;

    sem_post( &semaforo );
    pthread_exit( NULL );

}
//0 rojo y cualquier valor mayor a 0 es verde
int main(){
    int k;
    pthread_t hilo[CLIENTES];
    sem_init( &semaforo, 0, LUGARES_EN_LA_MESA); // El 0 para indicar que va a ser con hilos.

    for(k=0; k < CLIENTES; k++)
        pthread_create(&hilo[k], NULL, mesa, NULL);

    for(k=0; k < CLIENTES; k++)
        pthread_join(hilo[k], NULL);

    sem_destroy( &semaforo);
    printf("Fin hilo principal\n");

    return 0;
}