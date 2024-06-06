#include <stdio.h>
#include <pthread.h>

int asientosDisponibles = 40;

void *compraBoletos(void *args){
    if(asientosDisponibles > 0){
        asientosDisponibles--;
        printf("Compra exitosa del asitento # %i por el hilo: %li\n", asientosDisponibles, pthread_self());
    }
}

int main(){
    pthread_t thread1, thread2, thread3, thread4, thread5;

    pthread_create(&thread1, NULL, compraBoletos, NULL);
    pthread_create(&thread2, NULL, compraBoletos, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
}