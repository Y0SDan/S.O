/*Ejercicio que tiene 3 hilos donde cada hilo n imprima "Soy el número n"*/
///// Se puede hacer con candados o semaforos
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_THREADS 3

sem_t semaphores[NUM_THREADS];

void* print_num(void* num) {
    int* i = (int*) num;
    sem_wait(&semaphores[*i]);  // Espera a que el semáforo esté disponible
    printf("Soy el número %d\n", *i+1);
    if (*i < NUM_THREADS - 1) {
        sem_post(&semaphores[*i + 1]);  // Libera el siguiente semáforo
    }
    sem_destroy(&semaphores[*i]);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_args[NUM_THREADS];
    int i;

    // Inicializa los semáforos
    for (i = 0; i < NUM_THREADS; ++i) {
        sem_init(&semaphores[i], 0, 0);
    }
    // El primer semáforo debe estar disponible al principio
    sem_post(&semaphores[0]);

    // Crea los hilos
    for (i = 0; i < NUM_THREADS; ++i) {
        thread_args[i] = i;
        pthread_create(&threads[i], NULL, print_num, (void*) &thread_args[i]);
    }

    // Espera a que todos los hilos terminen
    for (i = 0; i < NUM_THREADS; ++i) {
        pthread_join(threads[i], NULL);
    }
    
    return 0;
}