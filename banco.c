#include <stdio.h>
#include <pthread.h>

float saldo = 500.0;

void *retira(void * arg);

int main(){
    pthread_t hilo[2];

    pthread_create(&hilo[0], NULL, retira, NULL);
    pthread_create(&hilo[1], NULL, retira, NULL);

    pthread_join(hilo[0], NULL);
    pthread_join(hilo[1], NULL);

    return 0;
}

void *retira(void * arg){
    if(saldo >= 500){
        //agregar un for o un sleep para dormir el proceso y hacer que espere y perdamos tiempo
        saldo -= 500;
        printf("Retiro exitoso\n");


    pthread_exit(NULL);
    }
}