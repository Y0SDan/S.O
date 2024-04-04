#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

int main() {
    char comando[100];
    char argumentos[100];

    while (1) {
        printf("MyShell> ");
        scanf("%99s", comando); // Limitamos la lectura a 99 caracteres

        // Leer argumentos (si los hay)
        printf("Argumentos (si los hay): ");
        scanf("%99s", argumentos); // Limitamos la lectura a 99 caracteres

        int pid = fork();

        if (pid == 0) {
            // Ejecutar el comando con argumentos
            execlp(comando, comando, argumentos, NULL);
            perror("Error al ejecutar el comando"); // En caso de error
            exit(1);
        } else {
            wait(NULL);
            printf("Comando ejecutado.\n");

            // Preguntar si desea ejecutar otro comando
            char respuesta[10];
            printf("¿Desea ejecutar otro comando? (s/n): ");
            scanf("%9s", respuesta); // Limitamos la lectura a 9 caracteres

            if (strcmp(respuesta, "n") == 0) {
                break; // Salir del bucle si la respuesta es "n"
            }
        }
    }

    return 0;
}
