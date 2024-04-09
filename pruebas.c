#include <stdio.h>



int main() {
    int tuberia[ 2 ];
    int h1,h2;

    //tuberia[0] es de lectura
    //tuberia[1] es de escritura
    pipe( tuberia );

    h1 = fork(); //generamos un proceso. Es el hijo1


    
    return 0;
}
