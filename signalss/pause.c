//Explique  el funcionamiento de la funcion pause

/*
Función pause:
    Espera por una señal.

*/
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>

void tratar_alarma( ){
    static int c;
    printf("alarma activada = %d\n", c++);
    alarm( 1 );
}

void tiempo() {
  time_t t;
  time(&t);
  printf("El tiempo es : %s", ctime(&t));
}

int main( void ){
    struct sigaction act;

    /* especifica el manejador */

    act.sa_handler = tratar_alarma; //función a ejecutar
        //sa_handler    = SIG_DFL para la acción por defecto
        //              = SIG_ING para ignorar la señal
        //              = Controlador que responderá a la señal
    act.sa_restorer = NULL; // obsoleto, no se debe utilizar
    act.sa_flags = 0; /* ninguna acción especifica */

    sigaction(SIGALRM, &act, NULL); // Configurar para cachar la señal.

   
    alarm(10);  // Aqui se configura para que la señal de la alarma se envie en 10 en en 10 segundos
    printf("antes de la pausa... ");
    tiempo();
    pause();
    printf("despues de la pausa... ");
    tiempo();
}
/*
1. Se especifica el manejador.
2. Se configura para cachar la señal con la funcion sigaction.
3. Aqui se configura para que la señal de la alarma se envie en 10 en en 10 segundos
4. Se imprime el tiempo antes y despues de la pausa.
*/