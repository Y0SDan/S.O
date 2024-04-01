# S.O
Funcionamiento de LINUX a profundidad

<h3>En que momento se ejecuta un proceso?</h3>
Los procesos se ejecutan en un orden indeterminado, en un nivel aleatorioa, se numeran por convención no siginifica que el uno se ejecuta antes que el 2 o antes que el 3 hya una cola de procesos y tambien una cola de hilos

<h3>Diferencia entre hilos y procesos</h3>
Un proceso tiene su propio espacio de memoria, un hilo puede compartir el espacio de memoria

### 

- El principal problema de los hilos es que comparten memoria

- Existe un problema de competencia

`void *proceso_2(void *parametro){}` -> Se le coloca un apuntador void por que asi puede apuntar a cualquier tipo de dato

>poder compartir a travez de los hilos un tipo de dato creado por nosotros Enmascarar