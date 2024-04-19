#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>

#define TIMEOUT 5

sem_t tenedores[5];

void pensar(int i){
    printf("Filosofo %d pensando...\n", i);
    sleep(1);
}

void comer(int i){
    printf("Filosofo %d comiendo...\n", i);
    sleep(2);
}

void *filosofo(void *p){
    int i = *(int *)p;

    while(1){
        pensar(i);
        sem_wait(&tenedores[i]);        // Bloquea el tenedor de la izquierda por que el filosofo i quiere comer esto lo hace con sem_wait sabe que es el tenedor de la izquierda porque el tenedor de la derecha es el tenedor i+1%5
        sem_wait(&tenedores[(i+1)%5]);  // Bloquea el tenedor de la derecha
        comer(i);
        sem_post(&tenedores[i]);
        sem_post(&tenedores[(i+1)%5]);
    }
}

/*void *filosofo(void *p){
    int i = *(int *)p;
    struct timespec ts;

    while(1){
        pensar(i);
        sem_wait(&tenedores[i]);
        if(sem_timedwait(&tenedores[(i+1)%5], &ts) == -1){
            printf("Filosofo %d en interbloqueo, liberando tenedores...\n", i);
            sem_post(&tenedores[i]);
        } else {
            comer(i);
            sem_post(&tenedores[i]);
            sem_post(&tenedores[(i+1)%5]);
        }
    }
}*/

int main(){
    pthread_t filosofos[5];
    int ids[5] = {0, 1, 2, 3, 4};

    for(int i = 0; i < 5; i++){
        sem_init(&tenedores[i], 0, 1);
    }

    for(int i = 0; i < 5; i++){
        pthread_create(&filosofos[i], NULL, filosofo, &ids[i]);
    }

    for(int i = 0; i < 5; i++){
        pthread_join(filosofos[i], NULL);
    }

    return 0;
}
