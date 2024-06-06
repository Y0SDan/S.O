#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    printf("Proceso padre: %d\n", getpid());
    printf("Proceso hijo: %d\n", pid);

    printf("Proceso padre: %d\n", getpid());
    printf("Proceso padre: %d\n", getppid());

    if (pid < 0) {
        printf("Error al crear el proceso\n");
        return 1;
    }

    if (pid == 0) {
        printf("Proceso hijo terminado\n");
        pause();  // El proceso hijo se detendrá aquí hasta que reciba alguna señal
    } else {
        sleep(5);
        kill(pid, 9);  // El proceso padre envía la señal 9 al proceso hijo después de 5 segundos
        printf("Señal enviada al proceso hijo\n");
    }

    return 0;
}
