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

# 2 de abril 2024
>cd /proc  ->  Es qui donde se guardan los procesos
### 
>cd 8080 nos movemos a la carpeta cuyo nombre sea el pid del proceso visto rn htop (éstas carpetas son temporales) Ahí podemor ver los hilos que se crean con el programa "hilos2.c"

Los ciclos estan úesto en un ciclo infinito por eso nunca terminan
### 
Si el hilo padre muere los hilos hijos tambien lo hacen
###
Para que compile de manera correcta tuve que compilar de esta manera en el codespace
>gcc -o term term.c -lpthread
###
Hilos diferentes ejecutando la misma tarea
>thread_create (h1, NULL procesaImagen, NULL);
###
>thread-create (h2, NULL, procesaImagen, NULL);
###
El reto es ejecutar una misma tarea con diferentes procesos 

# Tue, Apr 9

- Memoria Compartida 
- Condiciones de carrera
- Zona Crítica

El Sistema Operativo le da 20 milisegundos y durante esos 20 milisegundos te voy a esperar a que hagas todos los hilos que puedas y los que no ni modos te quedas dormido y el proceso va a la cola de procesos hasta que le vuelva a tocar el turno, por eso es probable que se queden dormidos hasta que les vuela a tocar y es peligroso si se quedan dormidos en una zona crítica para eso se usan candados


<h3>Memoria Compartida</h3>
<h3>Condiciones de carrera</h3>
<h3>Zona crítica</h3>

<h1>Ejercicio</h1>
Simular un punto de venta automatizado de venta de boletos de autobús;

###
Un autobús de pasajeros tiene 40 asisentos, escriba una programa multihilos que simula la venta de boletos del autobús

"Espera pasiva mandando a dormir con el conadado el hilo espera activa usando un while"
se puede programar en un raspberry antes la electronica no soportaba candados

¿que es una semaforo?

cambiaron al forma de manejar hilos en linux en 2018

en java se cooprta diferente


#
- <h3> Interbloqueos | Dead lock | Abrazo mortal </h3>
En este tema la palabra hilo y procesos son equivalentes, ya que los mismos bloqueos que se tieenen a nivel hilo se pueden tener en procesos

Cuando estan todos los hilos se quedan detenidos esperando a que uno hilo haga algo, si mas de un hilo

Otros problemas clásicos es el barbero dormilo ec. hay un libro con 8 problemas clsicos 

<h1>Archivos</h1>
Existen 3 formas de manipular archivos directa, indexada y secuencial.

-tabla auxiliar o tabla de inidices

