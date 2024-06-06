#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t mutex; // semáforo para la exclusión mutua significa que solo un hilo puede acceder a la sección crítica


//crear una barrera que detiene a los hilos hasta que todos los hilos lleguen a la barrera