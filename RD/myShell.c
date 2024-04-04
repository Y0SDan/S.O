#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

int main() {
    char linea[200]; // Aumentamos el tamaño para permitir comandos más largos

    while (1) {
        printf("MyShell> ");
        fgets(linea, sizeof(linea), stdin); // Leer toda la línea de entrada

        // Eliminar el salto de línea al final
        linea[strcspn(linea, "\n")] = '\0';

        int pid = fork();

        if (pid == 0) {
            // Ejecutar el comando con argumentos
            execlp("/bin/sh", "/bin/sh", "-c", linea, NULL);
            perror("Error al ejecutar el comando"); // En caso de error
            exit(1);
        } else {
            wait(NULL);
            printf("Comando ejecutado.\n");
        }
    }

    return 0;
}
