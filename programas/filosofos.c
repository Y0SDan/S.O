int tenedores[5];

int estado_filosofos[5];

void cambiar_estado(int filosofo, int nuevo_estado) {
    estado_filosofos[filosofo] = nuevo_estado;
}

int estado_izquierdo(int filosofo) {
    return estado_filosofos[(filosofo + 4) % 5];
}

int estado_derecho(int filosofo) {
    return estado_filosofos[(filosofo + 1) % 5];
}

void intentar_comer(int filosofo) {
    if (estado_filosofos[filosofo] == 1 && estado_izquierdo(filosofo) != 2 && estado_derecho(filosofo) != 2) {
        cambiar_estado(filosofo, 2);
        tomar_tenedores(filosofo);
    }
}

void dejar_comer(int filosofo) {
    cambiar_estado(filosofo, 0);
    dejar_tenedores(filosofo);
    intentar_comer((filosofo + 4) % 5);
    intentar_comer((filosofo + 1) % 5);
}

void filosofo(int id) {
    while (true) {
        pensar();
        cambiar_estado(id, 1);
        intentar_comer(id);
        esperar();
        dejar_comer(id);
    }
}