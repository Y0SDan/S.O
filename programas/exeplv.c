#include <stdio.h>                              // Include standard input/output library
#include <stdlib.h>                             // Include standard library
#include <unistd.h>                             // Include POSIX operating system API
#include <sys/wait.h>                           // Include wait system call
#include <string.h>                             // Include string library 

#define MAX 80
int main(void) {
    char **args;  
    int flag = 1; 
    char *comando; 
    
    comando = (char*)calloc(MAX,sizeof(char));
    args = (char**)calloc(1, sizeof(char*));
    while (flag) {
        fgets(comando, MAX, stdin);

        int i = 0;
        while (comando[i] != '\n' && comando[i] != '\0') {
            i++;
        }
        if (comando[i] == '\n') 
            comando[i] = '\0';
        
        if(strcmp(comando,"exit\0")==0)
            exit(1);

        char *subcadena = strtok(comando, " "); // similar split de python. Divide la cadena en una subcadena, separadas por el espacio
        i = 0;
        while (subcadena != NULL) {
            args[i] = subcadena;
            i++;
            subcadena = strtok(NULL, " ");
        }
        args[i] = NULL; // Asegurar que el último argumento sea NULL, necesario para execvp() 
        int pid = fork();
        if (pid == 0) { // Proceso hijo 
            execvp(args[0], args); 
            exit(0);
        } else { 
            wait(NULL);
        }
    }
    
    return 0;
}
